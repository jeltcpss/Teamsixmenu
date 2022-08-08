#include "fiber_pool.hpp"
#include "util/entity.hpp"
#include "util/local_player.hpp"
#include "views/view.hpp"
#include "services/gta_data/gta_data_service.hpp"
#include "services/model_preview/model_preview_service.hpp"
#include <imgui_internal.h>

namespace big
{
	void view::self()
	{
		components::button("Suicide", [] {
			ENTITY::SET_ENTITY_HEALTH(self::ped, 0, 0);
		});

		ImGui::SameLine();

		components::button("Heal", [] {
			ENTITY::SET_ENTITY_HEALTH(self::ped, PED::GET_PED_MAX_HEALTH(self::ped), 0);
			PED::SET_PED_ARMOUR(self::ped, PLAYER::GET_PLAYER_MAX_ARMOUR(self::id));
		});

		ImGui::SameLine();

		components::button("Fill Inventory", [] {
			std::string mpPrefix = local_player::get_mp_prefix();
			STATS::STAT_SET_INT(rage::joaat(mpPrefix + "NO_BOUGHT_YUM_SNACKS"), 30, true);
			STATS::STAT_SET_INT(rage::joaat(mpPrefix + "NO_BOUGHT_HEALTH_SNACKS"), 15, true);
			STATS::STAT_SET_INT(rage::joaat(mpPrefix + "NO_BOUGHT_EPIC_SNACKS"), 5, true);
			STATS::STAT_SET_INT(rage::joaat(mpPrefix + "MP_CHAR_ARMOUR_1_COUNT"), 10, true);
			STATS::STAT_SET_INT(rage::joaat(mpPrefix + "MP_CHAR_ARMOUR_2_COUNT"), 10, true);
			STATS::STAT_SET_INT(rage::joaat(mpPrefix + "MP_CHAR_ARMOUR_3_COUNT"), 10, true);
			STATS::STAT_SET_INT(rage::joaat(mpPrefix + "MP_CHAR_ARMOUR_4_COUNT"), 10, true);
			STATS::STAT_SET_INT(rage::joaat(mpPrefix + "MP_CHAR_ARMOUR_5_COUNT"), 10, true);
		});

		ImGui::SameLine();

		components::button("Skip Cutscene", [] {
			CUTSCENE::STOP_CUTSCENE_IMMEDIATELY();
		});

		ImGui::Separator();

		components::small_text("Player Model Changer");

		static int selected_ped_type = -1;
		static bool ped_model_dropdown_open = false;
		static char ped_model_buf[64];

		auto ped_type_arr = g_gta_data_service->get_ped_type_arr();
		auto ped_arr = g_gta_data_service->get_ped_arr();

		ImGui::SetNextItemWidth(300.f);
		if (ImGui::BeginCombo("Ped Type", selected_ped_type == -1 ? "ALL" : ped_type_arr[selected_ped_type]))
		{
			if (ImGui::Selectable("ALL", selected_ped_type == -1))
			{
				selected_ped_type = -1;
			}

			for (int i = 0; i < ped_type_arr.size(); i++)
			{
				if (ImGui::Selectable(ped_type_arr[i], selected_ped_type == i))
				{
					selected_ped_type = i;
					ped_model_buf[0] = 0;
				}

				if (selected_ped_type == i)
				{
					ImGui::SetItemDefaultFocus();
				}
			}

			ImGui::EndCombo();
		}

		ImGui::SetNextItemWidth(300.f);

		components::input_text_with_hint("Model Name##player_model_name", "Model Name", ped_model_buf, sizeof(ped_model_buf), ImGuiInputTextFlags_EnterReturnsTrue, [] {
			ped_model_dropdown_open = false;
		});

		bool ped_model_dropdown_focused = ImGui::IsItemActive();

		if (ImGui::IsItemActivated())
		{
			ped_model_dropdown_open = true;
		}

		if (ped_model_dropdown_open)
		{
			bool is_open = true;
			bool item_hovered = false;

			std::string lower_search = ped_model_buf;
			std::transform(lower_search.begin(), lower_search.end(), lower_search.begin(), tolower);

			ImGui::SetNextWindowPos({ ImGui::GetItemRectMin().x, ImGui::GetItemRectMax().y });
			ImGui::SetNextWindowSize({ 300, 300 });
			if (ImGui::Begin("##player_model_popup", &is_open, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_Tooltip))
			{
				ImGui::BringWindowToDisplayFront(ImGui::GetCurrentWindow());
				ped_model_dropdown_focused |= ImGui::IsWindowFocused();

				for (auto& item : ped_arr)
				{
					if (!item.hash)
					{
						continue;
					}

					std::string type = item.get_type();
					std::string name = item.name;

					std::transform(name.begin(), name.end(), name.begin(), tolower);

					if ((
						selected_ped_type == -1 || ped_type_arr[selected_ped_type] == type
					) && (
						name.find(lower_search) != std::string::npos
					)) {

						bool selectable_highlighted = lower_search == name;
						bool selectable_clicked = ImGui::Selectable(item.name, selectable_highlighted);
						ped_model_dropdown_focused |= ImGui::IsItemFocused();

						if (selectable_clicked)
						{
							strncpy(ped_model_buf, item.name, 64);
							ped_model_dropdown_open = false;
							ped_model_dropdown_focused = false;
						}

						if (selectable_highlighted)
						{
							ImGui::SetItemDefaultFocus();
						}

						if (ImGui::IsItemHovered())
						{
							item_hovered = true;
							g_model_preview_service->show_ped(item.hash);
						}
					}
				}
				ImGui::End();
			}

			ped_model_dropdown_open = ped_model_dropdown_focused;

			if (!g->self.preview_ped || (g->self.preview_ped && (!item_hovered || !ped_model_dropdown_open)))
			{
				g_model_preview_service->stop_preview();
			}
		}

		if (ImGui::Checkbox("Preview", &g->self.preview_ped))
		{
			if (!g->self.preview_ped)
			{
				g_model_preview_service->stop_preview();
			}
		}
		ImGui::SameLine();
		components::button("Change Player Model", [] {
			const Hash hash = rage::joaat(ped_model_buf);

			for (uint8_t i = 0; !STREAMING::HAS_MODEL_LOADED(hash) && i < 100; i++)
			{
				STREAMING::REQUEST_MODEL(hash);
				script::get_current()->yield();
			}
			if (!STREAMING::HAS_MODEL_LOADED(hash))
			{
				g_notification_service->push_error("Self", "Failed to spawn model, did you give an incorrect model ? ");
				return;
			}
			PLAYER::SET_PLAYER_MODEL(PLAYER::GET_PLAYER_INDEX(), hash);
			PED::SET_PED_DEFAULT_COMPONENT_VARIATION(self::ped);
			script::get_current()->yield();
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
		});




		ImGui::Separator();

		components::small_text("General");

		ImGui::BeginGroup();

		ImGui::Checkbox("God Mode", &g->self.god_mode);
		ImGui::Checkbox("Off Radar", &g->self.off_radar);
		ImGui::Checkbox("Free Cam", &g->self.free_cam);
		ImGui::Checkbox("Disable Phone", &g->tunables.disable_phone);

		ImGui::EndGroup();
		ImGui::SameLine();
		ImGui::BeginGroup();

		ImGui::Checkbox("No Clip", &g->self.noclip);
		ImGui::Checkbox("No Ragdoll", &g->self.no_ragdoll);
		ImGui::Checkbox("Super Run", &g->self.super_run);
		ImGui::Checkbox("No Idle Kick", &g->tunables.no_idle_kick);

		ImGui::EndGroup();
		ImGui::SameLine();
		ImGui::BeginGroup();

		ImGui::Checkbox("Invisibility", &g->self.invisibility);
		if (g->self.invisibility) {
			ImGui::Checkbox("Locally Visible", &g->self.local_visibility);
		}

		ImGui::Checkbox("Keep Player Clean", &g->self.clean_player);

		components::button("Clean Player", [] {
			entity::clean_ped(self::ped);
		});

		ImGui::EndGroup();

		ImGui::Separator();

		components::small_text("Proofs");

		if (ImGui::Button("Check all"))
		{
			g->self.proof_bullet = true;
			g->self.proof_fire = true;
			g->self.proof_collision = true;
			g->self.proof_melee = true;
			g->self.proof_explosion = true;
			g->self.proof_steam = true;
			g->self.proof_drown = true;
			g->self.proof_water = true;
		}

		ImGui::SameLine();

		if (ImGui::Button("Uncheck all"))
		{
			g->self.proof_bullet = false;
			g->self.proof_fire = false;
			g->self.proof_collision = false;
			g->self.proof_melee = false;
			g->self.proof_explosion = false;
			g->self.proof_steam = false;
			g->self.proof_drown = false;
			g->self.proof_water = false;
		}

		ImGui::BeginGroup();

		ImGui::Checkbox("Bullet", &g->self.proof_bullet);
		ImGui::Checkbox("Fire", &g->self.proof_fire);

		ImGui::EndGroup();
		ImGui::SameLine();
		ImGui::BeginGroup();

		ImGui::Checkbox("Collision", &g->self.proof_collision);
		ImGui::Checkbox("Melee", &g->self.proof_melee);

		ImGui::EndGroup();
		ImGui::SameLine();
		ImGui::BeginGroup();

		ImGui::Checkbox("Explosion", &g->self.proof_explosion);
		ImGui::Checkbox("Steam", &g->self.proof_steam);

		ImGui::EndGroup();
		ImGui::SameLine();
		ImGui::BeginGroup();

		ImGui::Checkbox("Drown", &g->self.proof_drown);
		ImGui::Checkbox("Water", &g->self.proof_water);

		ImGui::EndGroup();

		ImGui::Separator();

		components::small_text("Police");

		ImGui::Checkbox("Never Wanted", &g->self.never_wanted);

		if (!g->self.never_wanted)
		{
			ImGui::Checkbox("Force Wanted Level", &g->self.force_wanted_level);
			ImGui::Text("Wanted Level");
			if (
				ImGui::SliderInt("###wanted_level", &g->self.wanted_level, 0, 5) &&
				!g->self.force_wanted_level &&
				g_local_player != nullptr
				) {
				g_local_player->m_player_info->m_wanted_level = g->self.wanted_level;
			}
		}

		g->self.proof_mask = 0;
		if (g->self.god_mode)
		{
			g->self.proof_mask |= static_cast<int>(eEntityProofs::GOD);
		}
		if (g->self.proof_bullet)
		{
			g->self.proof_mask |= static_cast<int>(eEntityProofs::BULLET);
		}
		if (g->self.proof_fire)
		{
			g->self.proof_mask |= static_cast<int>(eEntityProofs::FIRE);
		}
		if (g->self.proof_collision)
		{
			g->self.proof_mask |= static_cast<int>(eEntityProofs::COLLISION);
		}
		if (g->self.proof_melee)
		{
			g->self.proof_mask |= static_cast<int>(eEntityProofs::MELEE);
		}
		if (g->self.proof_explosion)
		{
			g->self.proof_mask |= static_cast<int>(eEntityProofs::EXPLOSION);
		}
		if (g->self.proof_steam)
		{
			g->self.proof_mask |= static_cast<int>(eEntityProofs::STEAM);
		}
		if (g->self.proof_drown)
		{
			g->self.proof_mask |= static_cast<int>(eEntityProofs::DROWN);
		}
		if (g->self.proof_water)
		{
			g->self.proof_mask |= static_cast<int>(eEntityProofs::WATER);
		}
	}
}
