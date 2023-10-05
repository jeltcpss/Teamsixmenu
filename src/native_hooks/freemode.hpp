#pragma once
#include "script_function.hpp"

namespace big
{
	namespace freemode
	{
		void GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH(rage::scrNativeCallContext* src)
		{
			const auto hash = src->get_arg<rage::joaat_t>(0);

			if (hash == RAGE_JOAAT("director_mode") || hash == RAGE_JOAAT("main"))
			{
				src->set_return_value(0);
				return;
			}

			src->set_return_value(SCRIPT::GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH(hash));
		}

		inline void IS_PLAYER_PLAYING(rage::scrNativeCallContext* src)
		{
			// block undead OTR
			if (g.session.decloak_players && src->get_arg<Player>(0) != self::id && !NETWORK::NETWORK_IS_ACTIVITY_SESSION())
				src->set_return_value<BOOL>(TRUE);
			else
				src->set_return_value<BOOL>(PLAYER::IS_PLAYER_PLAYING(src->get_arg<Player>(0)));
		};

		void NETWORK_HAS_RECEIVED_HOST_BROADCAST_DATA(rage::scrNativeCallContext* src)
		{
			if (NETWORK::NETWORK_IS_ACTIVITY_SESSION() || NETWORK::NETWORK_IS_IN_TRANSITION() || NETWORK::NETWORK_IS_TRANSITION_TO_GAME() || NETWORK::NETWORK_IS_HOST_OF_THIS_SCRIPT())
			{
				src->set_return_value<BOOL>(NETWORK::NETWORK_HAS_RECEIVED_HOST_BROADCAST_DATA());
			}
			else
			{
				if (g.session.force_script_host && NETWORK::NETWORK_HAS_RECEIVED_HOST_BROADCAST_DATA())
				{
					auto hash = SCRIPT::GET_HASH_OF_THIS_SCRIPT_NAME();
					g_fiber_pool->queue_job([hash] {
						scripts::force_host(hash);
						if (auto script = gta_util::find_script_thread(hash); script && script->m_net_component)
							((CGameScriptHandlerNetComponent*)script->m_net_component)->block_host_migration(true);
					});
				}

				src->set_return_value<BOOL>(NETWORK::NETWORK_HAS_RECEIVED_HOST_BROADCAST_DATA());
			}
		}
	}
}