#include "backend/looped/looped.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "gta_util.hpp"
#include "util/session.hpp"
#include "gta/script_handler.hpp"

namespace big
{
	void looped::session_randomize_ceo_colors()
	{
		if (g->session.randomize_ceo_colors && *g_pointers->m_is_session_started && !STREAMING::IS_PLAYER_SWITCH_IN_PROGRESS())
		{
			if (auto freemode = gta_util::find_script_thread(RAGE_JOAAT("freemode")); freemode && freemode->m_net_component && freemode->m_net_component->is_local_player_host())
			{
				for (int i = 0; i < *scr_globals::gsbd.at(818).at(44).as<int*>(); i++)
				{
					*scr_globals::gsbd.at(818).at(44).at(i, 2).at(1).as<int*>() = rand() % 15;
				}
			}
		}
	}
}
