#include "entity.hpp"

namespace big::entity
{
	void cage_ped(Ped ped)
	{
		Hash hash = RAGE_JOAAT("prop_gold_cont_01");

		Vector3 location = ENTITY::GET_ENTITY_COORDS(ped, true);
		OBJECT::CREATE_OBJECT(hash, location.x, location.y, location.z - 1.f, true, false, false);
	}

	void clean_ped(Ped ped)
	{
		Ped player_ped = self::ped;

		PED::CLEAR_PED_BLOOD_DAMAGE(player_ped);
		PED::CLEAR_PED_WETNESS(player_ped);
		PED::CLEAR_PED_ENV_DIRT(player_ped);
		PED::RESET_PED_VISIBLE_DAMAGE(player_ped);
	}

	void delete_entity(Entity& ent, bool force)
	{
		if (!ENTITY::DOES_ENTITY_EXIST(ent))
			return;
		if (!force && !take_control_of(ent))
		{
			LOG(VERBOSE) << "Failed to take control of entity before deleting";
			return;
		}

		if (ENTITY::IS_ENTITY_A_VEHICLE(ent))
		{
			for (auto obj : pools::get_all_props())
			{
				auto object = g_pointers->m_gta.m_ptr_to_handle(obj);
				if (!object)
					break;

				if (!ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(ent, object))
					continue;

				ENTITY::DELETE_ENTITY(&object);
			}

			for (auto veh : pools::get_all_vehicles())
			{
				auto vehicle = g_pointers->m_gta.m_ptr_to_handle(veh);
				if (!vehicle)
					break;

				if (ent == vehicle || !ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(ent, vehicle))
					continue;

				ENTITY::DELETE_ENTITY(&vehicle);
			}
		}
		
		ENTITY::DETACH_ENTITY(ent, 1, 1);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ent, 7000.f, 7000.f, 15.f, 0, 0, 0);
		if (!ENTITY::IS_ENTITY_A_MISSION_ENTITY(ent))
		{
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(ent, true, true);
		}
		ENTITY::DELETE_ENTITY(&ent);
	}

	bool raycast(Entity* ent)
	{
		BOOL hit;
		Vector3 endCoords;
		Vector3 surfaceNormal;

		Vector3 camCoords = CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 rot       = CAM::GET_GAMEPLAY_CAM_ROT(2);
		Vector3 dir       = math::rotation_to_direction(rot);
		Vector3 farCoords;

		farCoords.x = camCoords.x + dir.x * 1000;
		farCoords.y = camCoords.y + dir.y * 1000;
		farCoords.z = camCoords.z + dir.z * 1000;

		int ray = SHAPETEST::START_EXPENSIVE_SYNCHRONOUS_SHAPE_TEST_LOS_PROBE(camCoords.x,
		    camCoords.y,
		    camCoords.z,
		    farCoords.x,
		    farCoords.y,
		    farCoords.z,
		    -1,
		    0,
		    7);
		SHAPETEST::GET_SHAPE_TEST_RESULT(ray, &hit, &endCoords, &surfaceNormal, ent);

		return (bool)hit;
	}

	bool raycast(Vector3* endcoor)
	{
		Entity ent;
		BOOL hit;
		Vector3 surfaceNormal;

		Vector3 camCoords = CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 dir       = math::rotation_to_direction(CAM::GET_GAMEPLAY_CAM_ROT(2));
		Vector3 farCoords;

		farCoords.x = camCoords.x + dir.x * 1000;
		farCoords.y = camCoords.y + dir.y * 1000;
		farCoords.z = camCoords.z + dir.z * 1000;

		int ray = SHAPETEST::START_EXPENSIVE_SYNCHRONOUS_SHAPE_TEST_LOS_PROBE(camCoords.x,
		    camCoords.y,
		    camCoords.z,
		    farCoords.x,
		    farCoords.y,
		    farCoords.z,
		    -1,
		    0,
		    7);
		SHAPETEST::GET_SHAPE_TEST_RESULT(ray, &hit, endcoor, &surfaceNormal, &ent);

		return (bool)hit;
	}

	bool network_has_control_of_entity(rage::netObject* net_object)
	{
		return !net_object || !net_object->m_next_owner_id && (net_object->m_control_id == -1);
	}

	bool take_control_of(Entity ent, int timeout)
	{
		if (!*g_pointers->m_gta.m_is_session_started)
			return true;

		auto hnd = g_pointers->m_gta.m_handle_to_ptr(ent);

		if (!hnd || !hnd->m_net_object || !*g_pointers->m_gta.m_is_session_started)
			return false;

		if (network_has_control_of_entity(hnd->m_net_object))
			return true;

		for (int i = 0; i < timeout; i++)
		{
			g_pointers->m_gta.m_request_control(hnd->m_net_object);

			if (network_has_control_of_entity(hnd->m_net_object))
				return true;

			if (timeout != 0)
				script::get_current()->yield();
		}

		return false;
	}

	std::vector<Entity> get_entities(bool vehicles, bool peds, bool props, bool include_self_veh)
	{
		std::vector<Entity> target_entities;

		if (vehicles)
		{
			for (auto vehicle : pools::get_all_vehicles())
			{
				if (!include_self_veh && vehicle == gta_util::get_local_vehicle())
					continue;

				target_entities.push_back(g_pointers->m_gta.m_ptr_to_handle(vehicle));
			}
		}

		if (peds)
		{
			for (auto ped : pools::get_all_peds())
			{
				if (ped == g_local_player)
					continue;

				target_entities.push_back(g_pointers->m_gta.m_ptr_to_handle(ped));
			}
		}

		if (props)
		{
			for (auto prop : pools::get_all_props())
			{
				target_entities.push_back(g_pointers->m_gta.m_ptr_to_handle(prop));
			}
		}
		return target_entities;
	}

	bool load_ground_at_3dcoord(Vector3& location)
	{
	    constexpr float max_ground_check = 1000.f;
	    constexpr int max_attempts = 300;
	    float ground_z = location.z;
	    int current_attempts = 0;
	    bool found_ground;
		float height;

	    do {
	        found_ground = MISC::GET_GROUND_Z_FOR_3D_COORD(location.x, location.y, max_ground_check, &ground_z, FALSE, FALSE);
	        STREAMING::REQUEST_COLLISION_AT_COORD(location.x, location.y, location.z);

	        if (current_attempts % 10 == 0)
	        {
	            location.z += 25.f;
	        }

	        ++current_attempts;

	        script::get_current()->yield();
	    } while (!found_ground && current_attempts < max_attempts);

	    if (!found_ground)
	    {
	        return false;
	    }

        if (WATER::GET_WATER_HEIGHT(location.x, location.y, location.z, &height))
        {
			location.z = height;
        }
		else
		{
			location.z = ground_z + 1.f;	
		}

	    return true;
	}

	double distance_to_middle_of_screen(const rage::fvector2& screen_pos)
	{
		double cumulative_distance{};

		if (screen_pos.x > 0.5)
			cumulative_distance += screen_pos.x - 0.5;
		else
			cumulative_distance += 0.5 - screen_pos.x;

		if (screen_pos.y > 0.5)
			cumulative_distance += screen_pos.y - 0.5;
		else
			cumulative_distance += 0.5 - screen_pos.y;

		return cumulative_distance;
	}

	Entity get_entity_closest_to_middle_of_screen(rage::fwEntity** pointer, std::vector<Entity> ignore_entities, bool include_veh, bool include_ped, bool include_prop, bool include_players)
	{
		Entity closest_entity{};
		rage::fwEntity* closest_entity_ptr = nullptr;
		float distance                     = 1;

		auto ignored_entity = [=](Entity handle) -> bool {
			if (handle == self::ped)
				return true;

			for (auto ent : ignore_entities)
			{
				if (handle == ent)
					return true;
			}

			return false;
		};

		auto update_closest_entity = [&](Entity handle, rage::fwEntity* entity_ptr) {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(handle, 1);
			rage::fvector2 screenpos;
			HUD::GET_HUD_SCREEN_POSITION_FROM_WORLD_POSITION(pos.x, pos.y, pos.z, &screenpos.x, &screenpos.y);

			if (distance_to_middle_of_screen(screenpos) < distance && ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(self::ped, handle, 17) && !ignored_entity(handle))
			{
				closest_entity     = handle;
				closest_entity_ptr = entity_ptr;
				distance           = distance_to_middle_of_screen(screenpos);
			}
		};

		auto include_pool = [&](auto& pool) {
			for (const auto ptr : pool())
				if (ptr)
					update_closest_entity(g_pointers->m_gta.m_ptr_to_handle(ptr), ptr);
		};

		if (include_veh)
			include_pool(pools::get_all_vehicles);

		if (include_ped)
			include_pool(pools::get_all_peds);

		if (include_prop)
			include_pool(pools::get_all_props);

		if (include_players)
		{
			for (auto player : g_player_service->players() | std::ranges::views::values)
			{
				if (player->get_ped())
				{
					Ped handle = g_pointers->m_gta.m_ptr_to_handle(player->get_ped());
					update_closest_entity(handle, player->get_ped());
				}
			}
		}

		if (pointer)
			*pointer = closest_entity_ptr;

		return closest_entity;
	}
}