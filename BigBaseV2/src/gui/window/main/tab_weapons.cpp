#include "core/data/custom_weapons.hpp"
#include "main_tabs.hpp"
#include "fiber_pool.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "features.hpp"
#include "natives.hpp"
#include "util/teleport.hpp"
#include "pointers.hpp"

namespace big
{
	void KillTargets()
	{
		for (int i = 0; i <= 1000; i++)
		{
			Blip_t* blip = g_pointers->pBlipList->m_Blips[i].m_pBlip;
			if (blip)
			{
				if (blip->m_color != BlipColors::Blue) //Don't hit friendlies.
				{
					if (blip->m_icon == BlipIcons::Cop  || blip->m_icon == BlipIcons::Enemy || (blip->m_icon == BlipIcons::Circle && blip->m_color == BlipColors::Red))
					{
						static bool bShoot = false;
						bShoot = !bShoot;
						if (bShoot)
						{
							static Hash weaponList[] = { WEAPON_ADVANCEDRIFLE, WEAPON_APPISTOL, WEAPON_ASSAULTRIFLE, WEAPON_ASSAULTSMG, WEAPON_CARBINERIFLE, WEAPON_COMBATMG, WEAPON_COMBATPDW, WEAPON_COMBATPISTOL, WEAPON_HEAVYPISTOL, WEAPON_HEAVYSNIPER, WEAPON_MARKSMANRIFLE, WEAPON_MG, WEAPON_MICROSMG, WEAPON_PISTOL, WEAPON_PISTOL50, WEAPON_SMG, WEAPON_SNIPERRIFLE, WEAPON_SNSPISTOL, WEAPON_SPECIALCARBINE, WEAPON_MINIGUN };
							if (blip->m_scale_x >= 1.0f)
								FIRE::ADD_OWNED_EXPLOSION(PLAYER::PLAYER_PED_ID(), blip->x, blip->y, blip->z, TANKER, 1000.0f, FALSE, TRUE, 0.0f);
							else
							{
								srand((unsigned int)time(NULL));
								MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(blip->x + 0.1f, blip->y, blip->z - 0.15f, blip->x - 0.1f, blip->y, blip->z + 1, 10000, TRUE, weaponList[rand() % (sizeof(weaponList) / 4)], PLAYER::PLAYER_PED_ID(), TRUE, TRUE, 1.0f);
							}
							notify::above_map("Killed Enemies");
						}
					}
					if ((blip->m_color == BlipColors::None && (blip->m_icon == EnemyHelicopter || blip->m_icon == PoliceHelicopter)) ||
						((blip->m_color == BlipColors::Red || blip->m_color == BlipColors::RedMission) && (blip->m_icon == PLANE || blip->m_icon == Motorcycle || blip->m_icon == BlipIcons::PersonalVehicleCar || blip->m_icon == Helicopter2 || blip->m_icon == Jet || blip->m_icon == PlayerHelicopter || blip->m_icon == PlaneDrop)))
					{
						FIRE::ADD_OWNED_EXPLOSION(PLAYER::PLAYER_PED_ID(), blip->x, blip->y, blip->z, TANKER, 1000.0f, FALSE, TRUE, 0.0f);
					}
				}
			}
		}
	}
	void tab_main::tab_weapons()
	{
		
		static const char* weaponNamesString[] = {
									"weapon_dagger", "weapon_bat", "weapon_bottle", "weapon_crowbar",
									"weapon_unarmed", "weapon_flashlight", "weapon_golfclub", "weapon_hammer",
									"weapon_hatchet", "weapon_knuckle", "weapon_knife", "weapon_machete",
									"weapon_switchblade", "weapon_nightstick", "weapon_wrench", "weapon_battleaxe",
									"weapon_poolcue", "weapon_stone_hatchet" "weapon_pistol", "weapon_pistol_mk2",
									"weapon_combatpistol", "weapon_appistol", "weapon_stungun", "weapon_pistol50",
									"weapon_snspistol", "weapon_snspistol_mk2", "weapon_heavypistol", "weapon_vintagepistol",
									"weapon_flaregun", "weapon_marksmanpistol", "weapon_revolver", "weapon_revolver_mk2",
									"weapon_doubleaction", "weapon_raypistol", "weapon_ceramicpistol", "weapon_navyrevolver"
									"weapon_microsmg", "weapon_smg", "weapon_smg_mk2", "weapon_assaultsmg",
									"weapon_combatpdw", "weapon_machinepistol", "weapon_minismg", "weapon_raycarbine"
									"weapon_pumpshotgun", "weapon_pumpshotgun_mk2", "weapon_sawnoffshotgun", "weapon_assaultshotgun",
									"weapon_bullpupshotgun", "weapon_musket", "weapon_heavyshotgun", "weapon_dbshotgun",
									"weapon_autoshotgun" "weapon_assaultrifle", "weapon_assaultrifle_mk2", "weapon_carbinerifle",
									"weapon_carbinerifle_mk2", "weapon_advancedrifle", "weapon_specialcarbine", "weapon_specialcarbine_mk2",
									"weapon_bullpuprifle", "weapon_bullpuprifle_mk2", "weapon_compactrifle" "weapon_mg",
									"weapon_combatmg", "weapon_combatmg_mk2", "weapon_gusenberg" "weapon_sniperrifle",
									"weapon_heavysniper", "weapon_heavysniper_mk2", "weapon_marksmanrifle", "weapon_marksmanrifle_mk2"
									"weapon_rpg", "weapon_grenadelauncher", "weapon_grenadelauncher_smoke", "weapon_minigun",
									"weapon_firework", "weapon_railgun", "weapon_hominglauncher", "weapon_compactlauncher",
									"weapon_rayminigun" "weapon_grenade", "weapon_bzgas", "weapon_smokegrenade",
									"weapon_flare", "weapon_molotov", "weapon_stickybomb", "weapon_proxmine",
									"weapon_snowball", "weapon_pipebomb", "weapon_ball" "weapon_petrolcan",
									"weapon_fireextinguisher", "weapon_parachute", "weapon_hazardcan", "weapon_militaryrifle",
									"weapon_combatshotgun", "weapon_gadgetpistol"
		};

		if (ImGui::BeginTabItem("Weapons"))
		{
			if (ImGui::TreeNode("Ammo Options"))
			{
				ImGui::Checkbox("Infinite Ammo", &g.weapons.infinite_ammo);

				ImGui::SameLine();

				ImGui::Checkbox("Infinite Clip", &g.weapons.infinite_mag);

				ImGui::TreePop();
			}

			if (ImGui::Button("Kill enemies"))
			{
				QUEUE_JOB_BEGIN_CLAUSE(){
					KillTargets();
				}QUEUE_JOB_END_CLAUSE
			}

			if (ImGui::TreeNode("Weapons"))
			{
				if (ImGui::Button("Give all weapons"))
				{
					QUEUE_JOB_BEGIN_CLAUSE()
					{
						for (auto name : weaponNamesString)
						{
							Hash weaponHash = MISC::GET_HASH_KEY(name);
								WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), weaponHash, 9999, 1);
						}
					}
					QUEUE_JOB_END_CLAUSE
				}

				static char weapon_name[255];
				ImGui::InputText("Weapon name", weapon_name, 255);

				ImGui::Separator();

				if (ImGui::Button("Give Weapon"))
				{
					Hash hash = MISC::GET_HASH_KEY(weapon_name);
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 1000, 1);
				}

				ImGui::SameLine();

				if (ImGui::Button("Remove Weapon"))
				{
					Hash hash = MISC::GET_HASH_KEY(weapon_name);
					WEAPON::REMOVE_WEAPON_FROM_PED(PLAYER::PLAYER_PED_ID(), hash);
				}
				ImGui::TreePop();

			}
			if (ImGui::TreeNode("Custom Weapons"))
			{
				CustomWeapon selected = g.weapons.custom_weapon;

				if (ImGui::BeginCombo("Weapon", custom_weapons[(int)selected].name))
				{
					for (const custom_weapon& weapon : custom_weapons)
					{
						if (ImGui::Selectable(weapon.name, weapon.id == selected))
						{
							g.weapons.custom_weapon = weapon.id;
						}

						if (weapon.id == selected)
							ImGui::SetItemDefaultFocus();
					}

					ImGui::EndCombo();
				}

				switch (selected)
				{
				case CustomWeapon::NONE:
					break;
				case CustomWeapon::CAGE_GUN:
					break;
				case CustomWeapon::DELETE_GUN:
					break;
				case CustomWeapon::GRAVITY_GUN:
					break;
				case CustomWeapon::REPAIR_GUN:
					break;
				case CustomWeapon::VEHICLE_GUN:
					ImGui::Text("Shooting Model:");
					ImGui::InputText("##vehicle_gun_model", g.weapons.vehicle_gun_model, 12);

					break;
				}

				ImGui::TreePop();
			}

			ImGui::EndTabItem();
		}
	}
}