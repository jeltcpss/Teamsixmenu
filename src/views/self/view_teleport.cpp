#include "core/data/ipls.hpp"
#include "fiber_pool.hpp"
#include "util/globals.hpp"
#include "util/mobile.hpp"
#include "util/teleport.hpp"
#include "util/vehicle.hpp"
#include "views/view.hpp"

namespace big
{
	void view::teleport()
	{
		ImGui::SeparatorText("BLIPS"_T.data());
		ImGui::Spacing();

		components::command_button<"waypointtp">({}, "Waypoint");
		ImGui::SameLine();
		components::command_button<"objectivetp">({}, "Objective");
		ImGui::SameLine();
		components::command_button<"highlighttp">({}, "Selected");
		components::command_checkbox<"autotptowp">();

		ImGui::SeparatorText("Movement");

		ImGui::Spacing();

		components::small_text("Current coordinates");
		float coords[3] = {self::pos.x, self::pos.y, self::pos.z};
		static float new_location[3];
		static float increment = 1;

		ImGui::SetNextItemWidth(400);
		ImGui::InputFloat3("##currentcoordinates", coords, "%f", ImGuiInputTextFlags_ReadOnly);
		ImGui::SameLine();
		components::button("Copy to custom", [coords] {
			std::copy(std::begin(coords), std::end(coords), std::begin(new_location));
		});

		components::small_text("Custom teleport");
		ImGui::SetNextItemWidth(400);
		ImGui::InputFloat3("##Customlocation", new_location);
		ImGui::SameLine();
		components::button("Teleport", [] {
			teleport::to_coords({new_location[0], new_location[1], new_location[2]});
		});

		ImGui::Spacing();
		components::small_text("Specific movement");
		ImGui::Spacing();

		ImGui::SetNextItemWidth(200);
		ImGui::InputFloat("Distance", &increment);

		ImGui::BeginGroup();
		components::button("Forward", [] {
			teleport::to_coords(ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(self::ped, 0, increment, 0));
		});
		components::button("Backward", [] {
			teleport::to_coords(ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(self::ped, 0, -increment, 0));
		});
		ImGui::EndGroup();

		ImGui::SameLine();

		ImGui::BeginGroup();
		components::button("Left", [] {
			teleport::to_coords(ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(self::ped, -increment, 0, 0));
		});
		components::button("Right", [] {
			teleport::to_coords(ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(self::ped, increment, 0, 0));
		});
		ImGui::EndGroup();

		ImGui::SameLine();

		ImGui::BeginGroup();
		components::button("Up", [] {
			teleport::to_coords(ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(self::ped, 0, 0, increment));
		});
		components::button("Down", [] {
			teleport::to_coords(ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(self::ped, 0, 0, -increment));
		});
		ImGui::EndGroup();

		ImGui::SeparatorText("VEHICLES"_T.data());
		ImGui::Spacing();

		components::command_button<"lastvehtp">();
		ImGui::SameLine();
		components::command_button<"bringpv">();
		ImGui::SameLine();
		components::command_button<"pvtp">();

		ImGui::SeparatorText("GUI_TAB_IPL"_T.data());

		static int current_select = g.self.ipls.select;
		static int last_select    = current_select;

		if (ImGui::BeginCombo("IPL_LOCATION"_T.data(), ipls[current_select].friendly_name))
		{
			for (int i = 0; i < IM_ARRAYSIZE(ipls); i++)
			{
				bool is_selected = (i == current_select);
				if (ImGui::Selectable(ipls[i].friendly_name, is_selected))
				{
					current_select = i;
				}
				if (is_selected)
				{
					ImGui::SetItemDefaultFocus();
				}
			}
			ImGui::EndCombo();
		}
		components::button("LOAD_IPL"_T.data(), [] 
		{
			// If we've changed selections, first unload previously loaded IPL, then load previously deleted IPLs
			if (current_select != last_select)
			{
				// Unload previously loaded IPL of the last selection
				for (auto& ipl_name_unload : ipls[last_select].ipl_names)
				{
					if (STREAMING::IS_IPL_ACTIVE(ipl_name_unload))
					{
						STREAMING::REMOVE_IPL(ipl_name_unload);
						LOG(INFO) << "Unloaded previous IPL " << ipl_name_unload;
					}
				}

				// Delay to wait for the unloading to complete
				script::get_current()->yield(100ms);

				// Load previously deleted IPLs of the last selection
				for (auto& ipl_name_load : ipls[last_select].ipl_names_remove)
				{
					STREAMING::REQUEST_IPL(ipl_name_load);
					LOG(INFO) << "Loaded previously deleted IPLs " << ipl_name_load;
				}

				// Small delay to allow for IPLs to load
				script::get_current()->yield(100ms);

				// Load new IPLs of the current selection
				for (auto& ipl_name : ipls[current_select].ipl_names)
				{
					STREAMING::REQUEST_IPL(ipl_name);
					LOG(INFO) << "New IPL loaded " << ipl_name;
				}

				// Remove old IPLs of the current selection to avoid conflicts
				for (auto& ipl_name_remove : ipls[current_select].ipl_names_remove_when_load)
				{
					STREAMING::REMOVE_IPL(ipl_name_remove);
					LOG(INFO) << "Removed IPL to avoid conflict " << ipl_name_remove;
				}

				last_select = current_select;
			}
		});

		ImGui::SameLine();

		components::button("TP_TO_IPL"_T.data(), [] 
		{
			teleport::to_coords(ipls[current_select].location);
		});

		ImGui::Spacing();
		components::small_text("IPL_INFOS"_T.data());

		ImGui::Text(std::vformat("IPL_CNT"_T, std::make_format_args(ipls[current_select].ipl_names.size())).data());
		ImGui::Text(std::vformat("IPL_POSITION"_T, std::make_format_args(ipls[current_select].location.x, ipls[current_select].location.y, ipls[current_select].location.z)).data());
	}
}
