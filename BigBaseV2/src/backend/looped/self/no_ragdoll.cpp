#include "backend/looped/looped.hpp"
#include "natives.hpp"

namespace big
{
	void looped::self_no_ragdoll()
	{
		PED::SET_PED_CAN_RAGDOLL(self::id, !g->self.no_ragdoll);
	}
}
