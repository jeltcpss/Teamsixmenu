#pragma once

#include "gta/joaat.hpp"
#include "natives.hpp"

enum Weapons : Hash
{
	WEAPON_UNARMED = RAGE_JOAAT("WEAPON_UNARMED")
};

enum Gadgets : Hash
{
	GADGET_OBJECT    = RAGE_JOAAT("OBJECT"),
	GADGET_PARACHUTE = RAGE_JOAAT("GADGET_PARACHUTE")
};

enum WeaponGroup : Hash
{
	GROUP_MELEE            = RAGE_JOAAT("GROUP_MELEE"),
	GROUP_UNARMED          = RAGE_JOAAT("GROUP_UNARMED"),
	GROUP_PISTOL           = RAGE_JOAAT("GROUP_PISTOL"),
	GROUP_RIFLE            = RAGE_JOAAT("GROUP_RIFLE"),
	GROUP_MG               = RAGE_JOAAT("GROUP_MG"),
	GROUP_SHOTGUN          = RAGE_JOAAT("GROUP_SHOTGUN"),
	GROUP_STUNGUN          = RAGE_JOAAT("GROUP_STUNGUN"),
	GROUP_SNIPER           = RAGE_JOAAT("GROUP_SNIPER"),
	GROUP_HEAVY            = RAGE_JOAAT("GROUP_HEAVY"),
	GROUP_THROWN           = RAGE_JOAAT("GROUP_THROWN"),
	GROUP_FIREEXTINGUISHER = RAGE_JOAAT("GROUP_FIREEXTINGUISHER"),
	GROUP_PETROLCAN        = RAGE_JOAAT("GROUP_PETROLCAN"),
	GROUP_DIGISCANNER      = RAGE_JOAAT("GROUP_DIGISCANNER"),
	GROUP_NIGHTVISION      = RAGE_JOAAT("GROUP_NIGHTVISION"),
	GROUP_PARACHUTE        = RAGE_JOAAT("GROUP_PARACHUTE")
};