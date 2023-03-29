#include "gui/components/components.hpp"
#include "pointers.hpp"

namespace big
{
	bool components::nav_button(const std::string_view text)
	{
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.f, 0.f, 0.f, 0.f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImGui::ColorConvertU32ToFloat4(g.window.colorhover));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImGui::ColorConvertU32ToFloat4(g.window.coloractive));
		ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, {0.05f, 0.5f});
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, {0, 5});
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, {0, 2});
		ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, {0, 0});
		bool result = ImGui::Button(text.data(), {((float)*g_pointers->m_resolution_x * 0.15f) - 30, 0});
		ImGui::PopStyleVar(4);
		ImGui::PopStyleColor(3);

		return result;
	}
}