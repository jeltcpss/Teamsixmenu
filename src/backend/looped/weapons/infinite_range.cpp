#include "natives.hpp"
#include "backend/looped_command.hpp"

namespace big
{

	class infinite_range : looped_command
	{
		using looped_command::looped_command;

		float blast = g_local_player->m_weapon_manager->m_weapon_info->m_weapon_range && !bchanged;
		bool bchanged;

		virtual void on_tick() override
		{
			bchanged = true;
			g_local_player->m_weapon_manager->m_weapon_info->m_weapon_range = SIZE_MAX;
		}
		virtual void on_disable() override
		{
			g_local_player->m_weapon_manager->m_weapon_info->m_weapon_range = blast;
			bchanged = false;
		}
	};

	infinite_range g_infinite_range("infrange", "Infinite Range", "Kill anything at any distance.", g.weapons.infinite_range);
}
