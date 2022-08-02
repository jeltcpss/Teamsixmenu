#include "fiber_pool.hpp"
#include "util/vehicle.hpp"
#include "views/view.hpp"
#include "util/mobile.hpp"
#include "core/data/speed_units.hpp"

namespace big
{
	void view::vehicle_fun()
	{
		static std::map<int, bool> seats;
		static bool ready = true;

		if (self::veh == 0)
		{
			seats.clear();
		}

		if (self::veh != 0 && ready == true)
		{
			ready = false;

			g_fiber_pool->queue_job([] {

				std::map<int, bool> tmp_seats;

				Hash model = ENTITY::GET_ENTITY_MODEL(self::veh);
				int num_of_seats = VEHICLE::GET_VEHICLE_MODEL_NUMBER_OF_SEATS(model);

				for (int i = -1; i < num_of_seats - 1; i++)
				{
					tmp_seats[i] = VEHICLE::IS_VEHICLE_SEAT_FREE(self::veh, i, true);
				}

				seats = tmp_seats;
				ready = true;
			});
		}


		components::small_text("Seat Changer");

		if (seats.size() == 0)
		{
			ImGui::Text("Please enter a vehicle.");
		}
		else
		{
			for (auto& it : seats)
			{
				int idx = it.first;

				if (!it.second)
				{
					ImGui::BeginDisabled();
				}

				std::string name = "Driver";

				if (idx >= 0)
				{
					name = "Seat " + std::to_string(idx + 1);
				}

				if ((idx + 1) % 4 != 0) {
					ImGui::SameLine();
				}

				components::button(name, [idx] {
					PED::SET_PED_INTO_VEHICLE(self::ped, self::veh, idx);
				});
				if (!it.second)
				{
					ImGui::EndDisabled();
				}
			}
		}

		ImGui::Separator();

		components::small_text("Auto Drive");

		float auto_drive_speed_user_unit = vehicle::mps_to_speed(g->vehicle.auto_drive_speed, g->vehicle.speed_unit);
		if (ImGui::SliderFloat(
			fmt::format("Top Speed({})", speed_unit_strings[(int)g->vehicle.speed_unit]).c_str(),
			&auto_drive_speed_user_unit,
			vehicle::mps_to_speed(0.f, g->vehicle.speed_unit),
			vehicle::mps_to_speed(150.f, g->vehicle.speed_unit),
			"%.1f"
		)) {
			g->vehicle.auto_drive_speed = vehicle::speed_to_mps(auto_drive_speed_user_unit, g->vehicle.speed_unit);
		}

		static constexpr char const* driving_style_names[] = { "Law-Abiding", "The Road Is Yours" };
		if (ImGui::BeginCombo("Driving Style", driving_style_names[(int)g->vehicle.auto_drive_style]))
		{
			for (int i = 0; i < 2; i++)
			{
				if (ImGui::Selectable(driving_style_names[i], g->vehicle.auto_drive_style == (AutoDriveStyle)i))
				{
					g->vehicle.auto_drive_style = (AutoDriveStyle)i;
					g_notification_service->push_warning("Auto Drive", fmt::format("Driving style set to {}.", driving_style_names[i]));
				}

				if (g->vehicle.auto_drive_style == (AutoDriveStyle)i)
				{
					ImGui::SetItemDefaultFocus();
				}
			}

			ImGui::EndCombo();
		}

		if (components::button("To Objective")) {
			g->vehicle.auto_drive_destination = AutoDriveDestination::OBJECTITVE;
		}
		ImGui::SameLine();
		if (components::button("To Waypoint")) {
			g->vehicle.auto_drive_destination = AutoDriveDestination::WAYPOINT;
		}
		ImGui::SameLine();
		if (components::button("Wander")) {
			g->vehicle.auto_drive_destination = AutoDriveDestination::WANDER;
		}
		ImGui::SameLine();
		if (components::button("Emergency Stop")) {
			g->vehicle.auto_drive_destination = AutoDriveDestination::EMERGENCY_STOP;
		}

		ImGui::Separator();

		components::small_text("Rainbow Paint");
		
		ImGui::Checkbox("Primary", &g->vehicle.rainbow_primary);
		ImGui::SameLine();
		ImGui::Checkbox("Secondary", &g->vehicle.rainbow_secondary);
		ImGui::SameLine();
		ImGui::Checkbox("Neon", &g->vehicle.rainbow_neon);
		ImGui::SameLine();
		ImGui::Checkbox("Smoke", &g->vehicle.rainbow_smoke);

		if (g->vehicle.rainbow_primary || g->vehicle.rainbow_neon || g->vehicle.rainbow_secondary || g->vehicle.rainbow_smoke) {
			ImGui::SetNextItemWidth(120);

			static constexpr char const* rgb_types[] = { "Off", "Fade", "Spasm" };
			if (ImGui::BeginCombo("RGB Type", rgb_types[g->vehicle.rainbow_paint]))
			{
				for (int i = 0; i < 3; i++)
				{
					bool itemSelected = g->vehicle.rainbow_paint == i;

					if (ImGui::Selectable(rgb_types[i], itemSelected))
					{
						g->vehicle.rainbow_paint = i;
					}

					if (itemSelected)
					{
						ImGui::SetItemDefaultFocus();
					}
				}

				ImGui::EndCombo();
			}
			if (g->vehicle.rainbow_paint != 0) 
			{				
				ImGui::SameLine();
				ImGui::SetNextItemWidth(150);
				ImGui::SliderInt("RGB Speed", &g->rgb.speed, 1, 10);
			}
		}		
		
		ImGui::Separator();

		components::small_text("Vehicle Fly");

		ImGui::BeginGroup();

		ImGui::Checkbox("Enabled", &g->vehicle.fly.enabled);
		ImGui::Checkbox("Don't Stop", &g->vehicle.fly.dont_stop);

		ImGui::EndGroup();
		ImGui::SameLine();
		ImGui::BeginGroup();

		ImGui::Checkbox("Disable Collision", &g->vehicle.fly.no_collision);
		ImGui::Checkbox("Stop On Exit", &g->vehicle.fly.stop_on_exit);

		ImGui::EndGroup();

		float fly_speed_user_unit = vehicle::mps_to_speed(g->vehicle.fly.speed, g->vehicle.speed_unit);

		if (!g->vehicle.fly.dont_stop) {
			if (ImGui::SliderFloat(
				fmt::format("Speed({})", speed_unit_strings[(int)g->vehicle.speed_unit]).c_str(),
				&fly_speed_user_unit,
				vehicle::mps_to_speed(0.f, g->vehicle.speed_unit),
				vehicle::mps_to_speed(150.f, g->vehicle.speed_unit),
				"%.1f"
			)) {
				g->vehicle.fly.speed = vehicle::speed_to_mps(fly_speed_user_unit, g->vehicle.speed_unit);
			}
		}
	}
}
