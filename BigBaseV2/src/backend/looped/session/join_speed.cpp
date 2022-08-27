#include "backend/looped/looped.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "script_global.hpp"
#include "script.hpp"
#include "core/enums.hpp"

namespace big
{
	void looped::fast_join()
	{
		if (g->tunables.fast_join)
		{
			if (*script_global::script_global(1574991).as<eTransitionState*>() == eTransitionState::TRANSITION_STATE_LOOK_FOR_FRESH_JOIN_FM)
			{
				STREAMING::STOP_PLAYER_SWITCH();
			}

			if (*script_global::script_global(1574991).as<eTransitionState*>() == eTransitionState::TRANSITION_STATE_IS_FM_AND_TRANSITION_READY)
			{
				script::get_current()->yield(1500ms);
				STREAMING::STOP_PLAYER_SWITCH();
			}
		}
	}
}