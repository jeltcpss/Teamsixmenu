#include "backend/looped/looped.hpp"
#include "natives.hpp"
#include "services/players/player_service.hpp"

namespace big
{
	Cam cam = CAM::GET_RENDERING_CAM();
	void looped::vehicle_headlightmul() {
		static float headlightmul_val;
		headlightmul_val = g->vehicle.headlightmul_val;

		if (g->vehicle.headlightmul)
			VEHICLE::SET_VEHICLE_LIGHT_MULTIPLIER(self::veh, headlightmul_val);
		else
			VEHICLE::SET_VEHICLE_LIGHT_MULTIPLIER(self::veh, 1.f);
	}
}