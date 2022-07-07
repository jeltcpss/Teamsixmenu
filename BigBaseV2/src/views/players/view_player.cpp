#include "gta_util.hpp"
#include "services/pickups/pickup_service.hpp"
#include "services/players/player_service.hpp"
#include "util/globals.hpp"
#include "util/toxic.hpp"
#include "util/misc.hpp"
#include "util/ped.hpp"
#include "util/teleport.hpp"
#include "util/entity.hpp"
#include "views/view.hpp"

namespace big
{
	void view::view_player() {

		std::string title = fmt::format("Player Options: {}", g_player_service->get_selected()->get_name());

		ImGui::Text(title.c_str());
		ImGui::Checkbox("Spectate", &g->player.spectating);

		ImGui::SameLine();

		ImGui::Checkbox("Freeze", &g->player.freezeplayer);

		ImGui::Checkbox("Shaky Booty", &g->player.shakecam);

		ImGui::SameLine();

		ImGui::Checkbox("Freeze All", &g->player.freezeallplayers);

		if (g_player_service->get_selected()->is_valid())
		{
			components::button("Desync", [] { gta_util::get_network_player_mgr()->RemovePlayer(g_player_service->get_selected()->get_net_game_player()); });

			if (ImGui::TreeNode("Misc")) {
				components::button("Steal Outfit", [] {
					ped::steal_outfit(
						PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id())
					);
					});

				ImGui::SameLine();

				components::button("Steal Identity", [] {
					ped::steal_identity(
						PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id())
					);
					});

				components::button("Clear Wanted Level", [] {
					toxic::clear_wanted_player(g_player_service->get_selected()->id());
					});

				ImGui::SameLine();

				ImGui::Checkbox("Never Wanted", &g_player_service->get_selected()->never_wanted);

				components::button("Give Health", [] {
					g_pickup_service->give_player_health(g_player_service->get_selected()->id());
					});

				ImGui::SameLine();

				components::button("Give Armour", [] {
					g_pickup_service->give_player_armour(g_player_service->get_selected()->id());
					});

				components::button("Give Ammo", [] {
					g_pickup_service->give_player_ammo(g_player_service->get_selected()->id());
					});

				ImGui::SameLine();

				components::button("Give Weapons", [] {
					g_pickup_service->give_player_weapons(g_player_service->get_selected()->id());
					});

				components::button("Spawn Bodyguard", [] {
					toxic::bodyguard(g_player_service->get_selected()->id());
					});

				ImGui::TreePop();
			}

			if (ImGui::TreeNode("Info")) {

				ImGui::Text("Player ID: %d", g_player_service->get_selected()->id());

				ImGui::Text("Session Host: %s", g_player_service->get_selected()->is_host() ? "Yes" : "No");

				ImGui::Separator();

				if (CPlayerInfo* player_info = g_player_service->get_selected()->get_player_info(); player_info != nullptr)
				{
					ImGui::Text("Wanted Level: %d", player_info->m_wanted_level);
				}

				if (CPed* ped = g_player_service->get_selected()->get_ped(); ped != nullptr)
				{
					ImGui::Text("Player God Mode: %s",
						misc::has_bit_set((int*)&ped->m_damage_bits, 8) ? "Yes" : "No"
					);
				}

				CAutomobile* vehicle = g_player_service->get_selected()->get_current_vehicle();
				ImGui::Text("Vehicle God Mode: %s",
					vehicle == nullptr ? "No vehicle detected" :
					misc::has_bit_set((int*)&vehicle->m_damage_bits, 8) ? "Yes" : "No"
				);

				ImGui::Separator();

				if (rage::netPlayerData* net_player_data = g_player_service->get_selected()->get_net_data(); net_player_data != nullptr)
				{
					ImGui::Text("Rockstar ID: %d", net_player_data->m_rockstar_id);
					ImGui::Text(
						"IP Address: %d.%d.%d.%d:%d",
						net_player_data->m_external_ip.m_field1,
						net_player_data->m_external_ip.m_field2,
						net_player_data->m_external_ip.m_field3,
						net_player_data->m_external_ip.m_field4,
						net_player_data->m_external_port
					);
				}

				ImGui::TreePop();
			}

			if (ImGui::TreeNode("Teleport")) {

				components::button("Teleport", [] {
					teleport::to_player(g_player_service->get_selected()->id());
					});

				ImGui::SameLine();

				components::button("Bring", [] {
					teleport::bring_player(g_player_service->get_selected()->id());
					});

				components::button("Teleport into Vehicle", [] {
					Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id()), false);

					teleport::into_vehicle(veh);
					});

				ImGui::TreePop();
			}

			if (ImGui::TreeNode("Toxic")) {
				components::button("Explode Self", [] {
					toxic::blame_explode_player(
						g_player_service->get_selected()->id(),
						g_player_service->get_selected()->id(),
						eExplosionType::PLANE, 1000, false, true, 10000.f
					);
					});

				ImGui::SameLine();

				components::button("Taze", [] {
					toxic::taze_player(g_player_service->get_selected()->id());
					});

				ImGui::SameLine();

				components::button("Kick to SP", [] {
					toxic::KICK_TO_SP(g_player_service->get_selected()->id());
					});

				components::button("EMP", [] {
					toxic::emp_player(g_player_service->get_selected()->id());
					});

				ImGui::SameLine();

				components::button("Kick From Vehicle", [] {
					toxic::kick_from_vehicle(g_player_service->get_selected()->id());
					});

				components::button("Airstrike", [] {
					toxic::airstrike(g_player_service->get_selected()->id());
					});

				ImGui::SameLine();

				components::button("Flying Vehicle", [] {
					toxic::flying_vehicle(g_player_service->get_selected()->id());
					});

				components::button("Destroy vehicle", [] {
					toxic::destroyveh(g_player_service->get_selected()->id());
					});

				ImGui::SameLine();

				components::button("Send to APT", [] {
					toxic::Apartment(g_player_service->get_selected()->id());
					});

				/*components::button("Crash Script", [] {
					toxic::crash(g_player_service->get_selected()->id());
				});*/

				components::button("Send to Cayo Perico", [] {
					toxic::send_to_cayo_perico(g_player_service->get_selected()->id());
					});
				
				ImGui::SameLine();

				components::button("Bitching", [] {
					toxic::bitching(g_player_service->get_selected()->id());
					});
								
				ImGui::TreePop();
			}
		}
	}
}