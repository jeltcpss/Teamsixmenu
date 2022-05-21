#include "backend/looped/looped.hpp"
#include "gta/enums.hpp"
#include "natives.hpp"

namespace big
{

	void looped::vehicle_instant_brake()
	{
		if (!g->vehicle.instant_brake) return;

		Vehicle vehicle = self::veh;

		if (vehicle == 0 || ENTITY::GET_ENTITY_SPEED_VECTOR(vehicle, true).y < 1.f)
		{
			return;
		}

		if (PAD::IS_CONTROL_PRESSED(0, 33))
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(vehicle, 0);
	}
}
