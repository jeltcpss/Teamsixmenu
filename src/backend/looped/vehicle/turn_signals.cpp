#include "backend/looped_command.hpp"
#include "fiber_pool.hpp"
#include "gta/enums.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "util/is_key_pressed.hpp"
#include "windows.h"

namespace big
{
	struct key_state
	{
		key_state(int v_key) :
		    v_key(v_key)
		{
		}

		enum
		{
			up,
			down,
			just_pressed,
			just_released,
		};

		uint8_t state = up;
		int v_key;
	};
	struct controller_combo_state
	{
		controller_combo_state(std::array<int, 2> action_combo) :
		    action_combo(action_combo)
		{
		}

		enum
		{
			up,
			down,
			just_pressed,
			just_released,
		};

		uint8_t state = up;
		std::array<int, 2> action_combo;
	};
	struct signal_state
	{
		enum
		{
			right,
			left,
			hazzards
		};
	};

	class turn_signals : looped_command
	{
		using looped_command::looped_command;

		key_state right_signal_key{'L'};
		key_state left_signal_key{'J'};
		key_state hazzards_key{'K'};

		controller_combo_state right_controller_combo
		{ 
			std::array<int, 2>(
			{
				(int)ControllerInputs::INPUT_VEH_ACCELERATE,
				(int)ControllerInputs::INPUT_VEH_HANDBRAKE
			})
		};
		controller_combo_state left_controller_combo
		{ 
			std::array<int, 2>(
			{
				(int)ControllerInputs::INPUT_VEH_ACCELERATE,
				(int)ControllerInputs::INPUT_VEH_AIM
			})
		};
		controller_combo_state hazzards_controller_combo
		{ 
			std::array<int, 2>(
			{
				(int)ControllerInputs::INPUT_VEH_HANDBRAKE,
				(int)ControllerInputs::INPUT_VEH_AIM
			})
		};

		std::optional<std::chrono::system_clock::time_point> queued_right_turn_signal;
		std::optional<std::chrono::system_clock::time_point> queued_left_turn_signal;

		bool hazzards = false;
		bool right = false;
		bool left = false;

		void update_key_state(key_state& key_last_tick)
		{
			if (big::is_key_pressed(key_last_tick.v_key))
			{
				switch (key_last_tick.state)
				{
					case key_state::up: key_last_tick.state = key_state::just_pressed; break;
					case key_state::just_pressed: key_last_tick.state = key_state::down; break;
				}
			}
			else
			{
				switch (key_last_tick.state)
				{
					case key_state::down: key_last_tick.state = key_state::just_released; break;
					case key_state::just_released: key_last_tick.state = key_state::up; break;
				}
			}
		}
		void update_controller_combo_state(controller_combo_state& controller_combo_last_tick)
		{
			if (PAD::IS_CONTROL_PRESSED(0, controller_combo_last_tick.action_combo[0]) && 
				PAD::IS_CONTROL_PRESSED(0, controller_combo_last_tick.action_combo[1]))
			{
				switch (controller_combo_last_tick.state)
				{
					case controller_combo_state::up: controller_combo_last_tick.state = controller_combo_state::just_pressed; break;
					case controller_combo_state::just_pressed: controller_combo_last_tick.state = controller_combo_state::down; break;
				}
			}
			else
			{
				switch (controller_combo_last_tick.state)
				{
					case controller_combo_state::down: controller_combo_last_tick.state = controller_combo_state::just_released; break;
					case controller_combo_state::just_released: controller_combo_last_tick.state = controller_combo_state::up; break;
				}
			}
		}
		void update_input_states()
		{
			update_key_state(right_signal_key);
			update_key_state(left_signal_key);
			update_key_state(hazzards_key);
			
			if (PAD::IS_USING_KEYBOARD_AND_MOUSE(0))
				return;

			update_controller_combo_state(right_controller_combo);
			update_controller_combo_state(left_controller_combo);
			update_controller_combo_state(hazzards_controller_combo);
		}

		inline void set_turn_signals(int signal_state, bool on)
		{
			static constexpr int off = 0;

			if (self::veh)
			{
				switch (signal_state)
				{
					case signal_state::hazzards:
						VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(self::veh, signal_state::left, on);
						VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(self::veh, signal_state::right, on);
					    left = false;
					    right = false;
					    hazzards = on;
						break;

					case signal_state::left:
					    VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(self::veh, signal_state::left, on);
					    VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(self::veh, signal_state::right, off);
					    left     = on;
					    right    = false;
					    hazzards = false;
					    break;

					case signal_state::right:
						VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(self::veh, signal_state::left, off);
						VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(self::veh, signal_state::right, on);
					    left     = false;
					    right    = on;
					    hazzards = false;
						break;
				}
			}
		}

		virtual void on_enable() override
		{
			g_notification_service->push("Vehicle Signals", "Keybinds:\r\nToggle Left = J / R2+L1\r\nToggle Right = L / R2+R1\r\nToggle Hazzards = K / L1+R1");
		}
		virtual void on_tick() override
		{
			if (!g.vehicle.turn_signals && self::veh)
			{
				VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(self::veh, 0, 0);
				VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(self::veh, 1, 0);
				return;
			}

			update_input_states();			

			if (left_signal_key.state == key_state::just_pressed || left_controller_combo.state == controller_combo_state::just_pressed 
				|| g.vehicle.auto_turn_signals && PAD::IS_CONTROL_PRESSED(0, (int)ControllerInputs::INPUT_VEH_MOVE_LEFT_ONLY) 
				|| queued_left_turn_signal.has_value() && queued_left_turn_signal.value() - std::chrono::system_clock::now() > 1500ms)
			{
				set_turn_signals(signal_state::left, !left);
				queued_left_turn_signal = std::nullopt;
			}
				
			if (right_signal_key.state == key_state::just_pressed || right_controller_combo.state == controller_combo_state::just_pressed
			    || g.vehicle.auto_turn_signals && PAD::IS_CONTROL_PRESSED(0, (int)ControllerInputs::INPUT_VEH_MOVE_RIGHT_ONLY)
			    || queued_right_turn_signal.has_value() && queued_right_turn_signal.value() - std::chrono::system_clock::now() > 1500ms)
			{
				set_turn_signals(signal_state::right, !right);
				queued_right_turn_signal = std::nullopt;
			}

			if (hazzards_key.state == key_state::just_pressed || hazzards_controller_combo.state == controller_combo_state::just_pressed)
				set_turn_signals(signal_state::hazzards, !hazzards);

			if (!queued_left_turn_signal.has_value() && !queued_right_turn_signal.has_value())
			{
				if (PAD::IS_CONTROL_JUST_RELEASED(0, (int)ControllerInputs::INPUT_VEH_MOVE_LEFT_ONLY))
					queued_left_turn_signal = std::chrono::system_clock::now();

				if (PAD::IS_CONTROL_JUST_RELEASED(0, (int)ControllerInputs::INPUT_VEH_MOVE_RIGHT_ONLY))
					queued_right_turn_signal = std::chrono::system_clock::now();
			}
		}
		virtual void on_disable() override
		{
			if (self::veh)
			{
				VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(self::veh, 0, 0);
				VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(self::veh, 1, 0);
			}
		}
	};

	turn_signals g_turn_signals("turnsignals", "Turn Signals", "Enables toggleable turn signals for vehicles", g.vehicle.turn_signals);
}
