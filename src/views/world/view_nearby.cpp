#include "views/view.hpp"
#include "util/local_player.hpp"
#include "util/entity.hpp"
#include "util/ped.hpp"
#include "util/vehicle.hpp"

namespace big
{
	void view::nearby()
	{
		components::sub_title("Peds");
		components::button("Delete", [] { for (auto peds : entity::get_entities(false, true)) entity::delete_entity(peds); }); ImGui::SameLine();
		components::button("Kill", [] { for (auto peds : entity::get_entities(false, true)) ped::kill_ped(peds); }, ImVec2(0, 0), ImVec4(0.95f, 0.2f, 0.2f, 1.f)); ImGui::SameLine();
		components::button("Kill Enemies", [] { for (auto peds : entity::get_entities(false, true)) ped::kill_ped_by_relation(peds, 4 || 5); }, ImVec2(0, 0), ImVec4(1.f, 0.1f, 0.1f, 1.f));
		
		components::command_checkbox<"pedsignore">(); ImGui::SameLine(140.f);
		components::command_checkbox<"pedrain">(); 
		components::command_checkbox<"highalert">(); ImGui::SameLine(140.f);
		components::command_checkbox<"pedrush">();

		ImGui::Separator();
		components::sub_title("Vehicles");
		components::button("Delete", [] { for (auto vehs : entity::get_entities(true, false)) entity::delete_entity(vehs); }, ImVec2(110, 0)); ImGui::SameLine();
		components::button("Max Upgrade", [] { for (auto vehs : entity::get_entities(true, false)) vehicle::max_vehicle(vehs); }, ImVec2(110, 0)); ImGui::SameLine();
		components::button("Downgrade", [] { for (auto vehs : entity::get_entities(true, false)) vehicle::downgrade(vehs); }, ImVec2(110, 0)); 

		
	}
}