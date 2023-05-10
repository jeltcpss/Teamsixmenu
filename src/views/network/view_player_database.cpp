#include "core/data/block_join_reasons.hpp"
#include "core/data/command_access_levels.hpp"
#include "core/data/infractions.hpp"
#include "fiber_pool.hpp"
#include "pointers.hpp"
#include "services/api/api_service.hpp"
#include "services/player_database/player_database_service.hpp"
#include "services/players/player_service.hpp"
#include "util/session.hpp"
#include "views/view.hpp"

namespace big
{
	char name_buf[32];
	char search[64];
	std::shared_ptr<persistent_player> current_player;

	int filterIndex = 0;
	const char* filterOptions[] = {"All", "Friends", "Modders", "Blocked", "Command Level Access", "Not classified"};

	void draw_player_db_entry(std::shared_ptr<persistent_player> player, const std::string& lower_search)
	{
		std::string name = player->name;
		std::transform(name.begin(), name.end(), name.begin(), ::tolower);
		bool isBlocked = player->block_join;
		bool isFriend  = player->is_friends;
		bool isModder  = player->is_modder;
		ImVec4 onlineColor     = ImVec4(0.0f, 1.0f, 0.0f, 1.0f); // Green
		ImVec4 offlineColor    = ImVec4(0.7f, 0.7f, 0.7f, 1.0f); // Light grey
		ImVec4 backgroundColor = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);

		if (isBlocked)
			backgroundColor = ImVec4(1.000f, 0.000f, 0.000f, 0.900f); // Red
		else if (isFriend)
			backgroundColor = ImVec4(0.031f, 0.347f, 0.706f, 0.902f); // Blue
		else if (isModder)
			backgroundColor = ImVec4(1.0f, 0.5f, 0.0f, 1.0f); //Orange

		if (lower_search.empty() || name.find(lower_search) != std::string::npos)
		{
			ImGui::PushID(player->rockstar_id);

			float circle_size = 10.0f;
			auto cursor_pos   = ImGui::GetCursorScreenPos();
			auto plyr_state   = player->online_state;

			//render status circle
			ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(cursor_pos.x + 4.f + circle_size, cursor_pos.y + 4.f + circle_size),
			    circle_size,
			    ImColor(plyr_state == PlayerOnlineStatus::ONLINE  ? onlineColor :
			            plyr_state == PlayerOnlineStatus::OFFLINE ? offlineColor :
			            plyr_state == PlayerOnlineStatus::UNKNOWN ? ImVec4(.5f, .5f, .5f, 1.0f) :
			                                                        ImVec4(.5f, .5f, .5f, 1.0f)));

			// Render additional circles for blocked, friends, and modders
			if (isBlocked)
				ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(cursor_pos.x + 4.f + circle_size, cursor_pos.y + 4.f + circle_size), circle_size - 3.0f, ImColor(backgroundColor));

			if (isFriend)
				ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(cursor_pos.x + 4.f + circle_size, cursor_pos.y + 4.f + circle_size), circle_size - 3.0f, ImColor(backgroundColor));

			if (isModder)
				ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(cursor_pos.x + 4.f + circle_size, cursor_pos.y + 4.f + circle_size), circle_size - 3.0f, ImColor(backgroundColor));

			//we need some padding
			ImVec2 cursor = ImGui::GetCursorPos();
			ImGui::SetCursorPos(ImVec2(cursor.x + 30.f, cursor.y));

			if (components::selectable(player->name, player == g_player_database_service->get_selected()))
			{
				g_player_database_service->set_selected(player);
				current_player = player;
				strncpy(name_buf, current_player->name.data(), sizeof(name_buf));
			}

			ImGui::PopID();
		}
	}

	void view::player_database()
	{
		ImGui::SetNextItemWidth(300.f);
		components::input_text_with_hint("PLAYER"_T, "SEARCH"_T, search, sizeof(search), ImGuiInputTextFlags_None);
		ImGui::SetNextItemWidth(300.f);
		ImGui::Combo("##filterCombo", &filterIndex, filterOptions, IM_ARRAYSIZE(filterOptions));
		ImGui::SameLine();
		ImGui::Text("Filter");
		ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "Offline");
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Player is currently offline.");
		ImGui::SameLine();
		ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "Online");
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Player is currently online.");
		ImGui::SameLine();
		ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 0.9f), "Blocked");
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Player circle is Red, will always override blue or oragne, use the filters if you have more then one option");
		ImGui::SameLine();
		ImGui::TextColored(ImVec4(0.0f, 0.0f, 1.0f, 1.0f), "Friends");
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Player circle is Blue, will always override orange");
		ImGui::SameLine();
		ImGui::TextColored(ImVec4(1.0f, 0.5f, 0.0f, 1.0f), "Modders");
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Player Circle is Orange");


		if (ImGui::ListBoxHeader("###players", {180, static_cast<float>(*g_pointers->m_gta.m_resolution_y - 400 - 38 * 4)}))
		{
			auto& item_arr = g_player_database_service->get_sorted_players();
			if (item_arr.size() > 0)
			{
				std::string lower_search = search;
				std::transform(lower_search.begin(), lower_search.end(), lower_search.begin(), tolower);

				// Loop through the players, considering online state and filtering
				for (auto& player : item_arr | std::ranges::views::values)
				{
					// Check if the player meets the filtering criteria
					bool isFiltered = false;
					switch (filterIndex)
					{
					case 0: // All
						break;
					case 1: // Friends
						if (!player->is_friends)
							isFiltered = true;
						break;
					case 2: // Modders
						if (!player->is_modder)
							isFiltered = true;
						break;
					case 3: // Blocked
						if (!player->block_join)
							isFiltered = true;
						break;
					case 4: // Command level access
						if (!player->command_access_level.has_value()
						    || (player->command_access_level != CommandAccessLevel::FRIENDLY && player->command_access_level != CommandAccessLevel::AGGRESSIVE
						        && player->command_access_level != CommandAccessLevel::TOXIC && player->command_access_level != CommandAccessLevel::ADMIN))
							isFiltered = true;
						break;
					case 5: // Not classified as modder, friend, blocked, or notify
						if (player->is_modder || player->is_friends || player->block_join)
							isFiltered = true;
						break;
					}

					// Draw the player entry if it's not filtered and online
					if (!isFiltered && player->online_state == PlayerOnlineStatus::ONLINE)
						draw_player_db_entry(player, lower_search);
				}

				ImGui::Separator();

				// Loop through the players again for offline entries
				for (auto& player : item_arr | std::ranges::views::values)
				{
					// Check if the player meets the filtering criteria
					bool isFiltered = false;
					switch (filterIndex)
					{
					case 0: // All
						break;
					case 1: // Friends
						if (!player->is_friends)
							isFiltered = true;
						break;
					case 2: // Modders
						if (!player->is_modder)
							isFiltered = true;
						break;
					case 3: // Blocked
						if (!player->block_join)
							isFiltered = true;
						break;
					case 4: // Command level access
						if (!player->command_access_level.has_value()
						    || (player->command_access_level != CommandAccessLevel::FRIENDLY && player->command_access_level != CommandAccessLevel::AGGRESSIVE
						        && player->command_access_level != CommandAccessLevel::TOXIC && player->command_access_level != CommandAccessLevel::ADMIN))
							isFiltered = true;
						break;
					case 5: // Not classified as modder, friend, blocked, or notify
						if (player->is_modder || player->is_friends || player->block_join)
							isFiltered = true;
						break;
					}

					// Draw the player entry if it's not filtered and offline
					if (!isFiltered && player->online_state != PlayerOnlineStatus::ONLINE)
						draw_player_db_entry(player, lower_search);
				}

				ImGui::PopStyleColor();
			}
			else
			{
				ImGui::Text("NO_STORED_PLAYERS"_T.data());
			}


			ImGui::ListBoxFooter();
		}

		if (auto selected = g_player_database_service->get_selected())
		{
			ImGui::SameLine();
			if (ImGui::BeginChild("###selected_player", {500, static_cast<float>(*g_pointers->m_gta.m_resolution_y - 388 - 38 * 4)}, false, ImGuiWindowFlags_NoBackground))
			{
				if (ImGui::InputText("NAME"_T.data(), name_buf, sizeof(name_buf)))
				{
					current_player->name = name_buf;
				}

				if (ImGui::InputScalar("RID"_T.data(), ImGuiDataType_S64, &current_player->rockstar_id)
				    || ImGui::Checkbox("IS_FRIENDS"_T.data(), &current_player->is_friends)
				    || ImGui::Checkbox("IS_MODDER"_T.data(), &current_player->is_modder)
				    || ImGui::Checkbox("BLOCK_JOIN"_T.data(), &current_player->block_join))
				{
					if (current_player->rockstar_id != selected->rockstar_id)
						g_player_database_service->update_rockstar_id(selected->rockstar_id, current_player->rockstar_id);
					g_player_database_service->save();
				}

				if (ImGui::BeginCombo("BLOCK_JOIN_ALERT"_T.data(), block_join_reasons[current_player->block_join_reason]))
				{
					for (const auto& reason : block_join_reasons)
					{
						if (ImGui::Selectable(reason.second, reason.first == current_player->block_join_reason))
						{
							current_player->block_join_reason = reason.first;
							g_player_database_service->save();
						}

						if (reason.first == current_player->block_join_reason)
						{
							ImGui::SetItemDefaultFocus();
						}
					}

					ImGui::EndCombo();
				}

				if (ImGui::IsItemHovered())
					ImGui::SetTooltip("ONLY_AS_HOST"_T.data());


				if (ImGui::BeginCombo("CHAT_COMMAND_PERMISSIONS"_T.data(),
				        COMMAND_ACCESS_LEVELS[current_player->command_access_level.value_or(g.session.chat_command_default_access_level)]))
				{
					for (const auto& [type, name] : COMMAND_ACCESS_LEVELS)
					{
						if (ImGui::Selectable(name, type == current_player->command_access_level.value_or(g.session.chat_command_default_access_level)))
						{
							current_player->command_access_level = type;
							g_player_database_service->save();
						}

						if (type == current_player->command_access_level.value_or(g.session.chat_command_default_access_level))
						{
							ImGui::SetItemDefaultFocus();
						}
					}

					ImGui::EndCombo();
				}

				if (!current_player->infractions.empty())
				{
					ImGui::Text("INFRACTIONS"_T.data());

					for (auto& infraction : current_player->infractions)
					{
						ImGui::BulletText(infraction_desc[(Infraction)infraction]);
					}
				}

				components::button("JOIN_SESSION"_T, [] {
					session::join_by_rockstar_id(current_player->rockstar_id);
				});

				static char message[256];
				components::input_text("INPUT_MSG"_T, message, sizeof(message));
				if (components::button("SEND_MSG"_T))
				{
					g_thread_pool->push([selected] {
						if (g_api_service->send_socialclub_message(selected->rockstar_id, message))
						{
							g_notification_service->push("SCAPI"_T.data(), "MSG_SENT_SUCCESS"_T.data());
							return;
						}
						g_notification_service->push_error("SCAPI"_T.data(), "MSG_SENT_FAIL"_T.data());
					});
				};

				if (ImGui::Button("SAVE"_T.data()))
				{
					if (current_player->rockstar_id != selected->rockstar_id)
						g_player_database_service->update_rockstar_id(selected->rockstar_id, current_player->rockstar_id);

					selected = current_player;
					g_player_database_service->save();
				}

				ImGui::SameLine();

				if (ImGui::Button("REMOVE"_T.data()))
				{
					g_player_database_service->remove_rockstar_id(selected->rockstar_id);
				}
			}
			ImGui::EndChild();
		}

		if (ImGui::Button("REMOVE_ALL"_T.data()))
		{
			g_player_database_service->set_selected(nullptr);
			g_player_database_service->get_players().clear();
			g_player_database_service->get_sorted_players().clear();
			g_player_database_service->save();
		}

		ImGui::SameLine();

		components::button("RELOAD_PLYR_ONLINE_STATES"_T, [] {
			g_player_database_service->update_player_states();
		});

		if (components::command_checkbox<"player_db_auto_update_states">())
			g_player_database_service->start_update_loop();

		ImGui::Separator();
		components::sub_title("NEW_ENTRY"_T);

		static char new_name[64];
		static int64_t new_rockstar_id;

		components::input_text("NAME"_T, new_name, sizeof(new_name));
		ImGui::InputScalar("RID"_T.data(), ImGuiDataType_S64, &new_rockstar_id);

		if (ImGui::Button("ADD"_T.data()))
		{
			current_player = g_player_database_service->add_player(new_rockstar_id, new_name);
			g_player_database_service->save();
		}
	}
}
