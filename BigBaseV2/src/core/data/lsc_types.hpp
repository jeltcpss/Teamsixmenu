#pragma once
#include "gta/VehicleValues.h"


static const std::map<int, std::string> lsc_plate_styles = {
	{ PLATE_BLUEONWHITE1, "Blue on White 1" },
	{ PLATE_BLUEONWHITE2, "Blue on White 2" },
	{ PLATE_BLUEONWHITE3, "Blue on White 3" },
	{ PLATE_YELLOWONBLACK, "Yellow on Black" },
	{ PLATE_YELLOWONBLUE, "Yellow on Blue" },
	{ PLATE_YANKTON, "Yankton" }
};

static const std::map<int, std::string> lsc_wheel_styles = {
	{ WHEEL_TYPE_SPORT, "Sport" },
	{ WHEEL_TYPE_MUSCLE, "Muscle" },
	{ WHEEL_TYPE_LOWRIDER, "Lowrider" },
	{ WHEEL_TYPE_SUV, "SUV" },
	{ WHEEL_TYPE_OFFROAD, "Offroad" },
	{ WHEEL_TYPE_TUNER, "Tuner" },
	{ WHEEL_TYPE_BIKEWHEELS, "Bike Wheels" },
	{ WHEEL_TYPE_HIGHEND, "High End" },
	{ WHEEL_TYPE_BENNYS_ORIGINAL, "Bennys Original" },
	{ WHEEL_TYPE_BENNYS_BESPOKE, "Bennys Bespoke" },
	{ WHEEL_TYPE_OPEN_WHEEL, "Open Wheel" },
	{ WHEEL_TYPE_STREET, "Street" },
	{ WHEEL_TYPE_TRACK, "Track" }
};

static const std::map<int, std::string> lsc_window_tint_types = {
	{ WINDOWTINT_NONE, "None" },
	{ WINDOWTINT_BLACK, "Black" },
	{ WINDOWTINT_DARKSMOKE, "Dark" },
	{ WINDOWTINT_LIGHTSMOKE, "Light" },
	{ WINDOWTINT_STOCK, "Stock" },
	{ WINDOWTINT_LIMO, "Limo" },
	{ WINDOWTINT_GREEN, "Green" }
};

static const std::map<int, std::string> lsc_classic_colors = {
	{ COLOR_CLASSIC_BLACK, "Black" },
	{ COLOR_CLASSIC_CARBON_BLACK, "Carbon Black" },
	{ COLOR_CLASSIC_GRAPHITE, "Graphite" },
	{ COLOR_CLASSIC_ANHRACITE_BLACK, "Anthracite Black" },
	{ COLOR_CLASSIC_BLACK_STEEL, "Black Steel" },
	{ COLOR_CLASSIC_DARK_STEEL, "Dark Steel" },
	{ COLOR_CLASSIC_SILVER, "Silver" },
	{ COLOR_CLASSIC_BLUISH_SILVER, "Bluish Silver" },
	{ COLOR_CLASSIC_ROLLED_STEEL, "Rolled Steel" },
	{ COLOR_CLASSIC_SHADOW_SILVER, "Shadow SIlver" },
	{ COLOR_CLASSIC_STONE_SILVER, "Stone Silver" },
	{ COLOR_CLASSIC_MIDNIGHT_SILVER, "Midnight Silver" },
	{ COLOR_CLASSIC_CAST_IRON_SILVER, "Cast Iron Silver" },
	{ COLOR_CLASSIC_RED, "Red" },
	{ COLOR_CLASSIC_TORINO_RED, "Torino Red" },
	{ COLOR_CLASSIC_FORMULA_RED, "Formula Red" },
	{ COLOR_CLASSIC_LAVA_RED, "Lava Red" },
	{ COLOR_CLASSIC_BLAZE_RED, "Blaze Red" },
	{ COLOR_CLASSIC_GRACE_RED, "Grace Red" },
	{ COLOR_CLASSIC_GARNET_RED, "Garnet Red" },
	{ COLOR_CLASSIC_SUNSET_RED, "Sunset Red" },
	{ COLOR_CLASSIC_CABERNET_RED, "Cabernet Red" },
	{ COLOR_CLASSIC_WINE_RED, "Wine Red" },
	{ COLOR_CLASSIC_CANDY_RED, "Candy Red" },
	{ COLOR_CLASSIC_HOT_PINK, "Hot Pink" },
	{ COLOR_CLASSIC_PFSITER_PINK, "Pfister Pink" },
	{ COLOR_CLASSIC_SALMON_PINK, "Salmon Pink" },
	{ COLOR_CLASSIC_SUNRISE_ORANGE, "Sunrise Orange" },
	{ COLOR_CLASSIC_ORANGE, "Orange" },
	{ COLOR_CLASSIC_BRIGHT_ORANGE, "Bright Orange" },
	{ COLOR_CLASSIC_GOLD, "Gold" },
	{ COLOR_CLASSIC_BRONZE, "Bronze" },
	{ COLOR_CLASSIC_YELLOW, "Yellow" },
	{ COLOR_CLASSIC_RACE_YELLOW, "Race Yellow" },
	{ COLOR_CLASSIC_DEW_YELLOW, "Dew Yellow" },
	{ COLOR_CLASSIC_DARK_GREEN, "Dark Green" },
	{ COLOR_CLASSIC_RACING_GREEN, "Racing Green" },
	{ COLOR_CLASSIC_SEA_GREEN, "Sea Green" },
	{ COLOR_CLASSIC_OLIVE_GREEN, "Olive Green" },
	{ COLOR_CLASSIC_BRIGHT_GREEN, "Bright Green" },
	{ COLOR_CLASSIC_GASOLINE_GREEN, "Gasoline Green" },
	{ COLOR_CLASSIC_LIME_GREEN, "Lime Green" },
	{ COLOR_CLASSIC_MIDNIGHT_BLUE, "Midnight Blue" },
	{ COLOR_CLASSIC_GALAXY_BLUE, "Galaxy Blue" },
	{ COLOR_CLASSIC_DARK_BLUE, "Dark Blue" },
	{ COLOR_CLASSIC_SAXON_BLUE, "Saxon Blue" },
	{ COLOR_CLASSIC_BLUE, "Blue" },
	{ COLOR_CLASSIC_MARINER_BLUE, "Mariner Blue" },
	{ COLOR_CLASSIC_HARBOR_BLUE, "Harbor Blue" },
	{ COLOR_CLASSIC_DIAMOND_BLUE, "Diamond Blue" },
	{ COLOR_CLASSIC_SURF_BLUE, "Surf Blue" },
	{ COLOR_CLASSIC_NAUTICAL_BLUE, "Nautical Blue" },
	{ COLOR_CLASSIC_RACING_BLUE, "Racing Blue" },
	{ COLOR_CLASSIC_ULTRA_BLUE, "Ultra Blue" },
	{ COLOR_CLASSIC_LIGHT_BLUE, "Light Blue" },
	{ COLOR_CLASSIC_CHOCOLATE_BROWN, "Chocolate Brown" },
	{ COLOR_CLASSIC_BISON_BROWN, "Bison Brown" },
	{ COLOR_CLASSIC_CREEEN_BROWN, "Creek Brown" },
	{ COLOR_CLASSIC_FELTZER_BROWN, "Feltzer Brown" },
	{ COLOR_CLASSIC_MAPLE_BROWN, "Maple Brown" },
	{ COLOR_CLASSIC_BEECHWOOD_BROWN, "Beechwood Brown" },
	{ COLOR_CLASSIC_SIENNA_BROWN, "Sienna Brown" },
	{ COLOR_CLASSIC_SADDLE_BROWN, "Saddle Brown" },
	{ COLOR_CLASSIC_MOSS_BROWN, "Moss Brown" },
	{ COLOR_CLASSIC_WOODBEECH_BROWN, "Woodbeech Brown" },
	{ COLOR_CLASSIC_STRAW_BROWN, "Straw Brown" },
	{ COLOR_CLASSIC_SANDY_BROWN, "Sandy Brown" },
	{ COLOR_CLASSIC_BLEACHED_BROWN, "Bleached Brown" },
	{ COLOR_CLASSIC_SCHAFTER_PURPLE, "Schafter Purple" },
	{ COLOR_CLASSIC_SPINNAKER_PURPLE, "Spinnaker Purple" },
	{ COLOR_CLASSIC_MIDNIGHT_PURPLE, "Midnight Purple" },
	{ COLOR_CLASSIC_BRIGHT_PURPLE, "Bright Purple" },
	{ COLOR_CLASSIC_CREAM, "Cream" },
	{ COLOR_CLASSIC_ICE_WHITE, "Ice White" },
	{ COLOR_CLASSIC_FROST_WHITE, "Frost White" }
};

static const std::map<int, std::string> lsc_matte_colors = {
	{ COLOR_MATTE_BLACK, "Black" },
	{ COLOR_MATTE_GRAY, "Gray" },
	{ COLOR_MATTE_LIGHT_GRAY, "Light Gray" },
	{ COLOR_MATTE_ICE_WHITE, "Ice White" },
	{ COLOR_MATTE_BLUE, "Blue" },
	{ COLOR_MATTE_DARK_BLUE, "Dark Blue" },
	{ COLOR_MATTE_MIDNIGHT_BLUE, "Midnight Blue" },
	{ COLOR_MATTE_MIDNIGHT_PURPLE, "Midnight Purple" },
	{ COLOR_MATTE_SCHAFTER_PURPLE, "Shafter Purple" },
	{ COLOR_MATTE_RED, "Red" },
	{ COLOR_MATTE_DARK_RED, "Dark Red" },
	{ COLOR_MATTE_ORANGE, "Orange" },
	{ COLOR_MATTE_YELLOW, "Yellow" },
	{ COLOR_MATTE_LIME_GREEN, "Lime Green" },
	{ COLOR_MATTE_GREEN, "Green" },
	{ COLOR_MATTE_FOREST_GREEN, "Forest Green" },
	{ COLOR_MATTE_FOLIAGE_GREEN, "Foliage Green" },
	{ COLOR_MATTE_OLIVE_DARB, "Olive Drab" },
	{ COLOR_MATTE_DARK_EARTH, "Dark Earth" },
	{ COLOR_MATTE_DESERT_TAN, "Desert Tan" }
};

static const std::map<int, std::string> lsc_metal_colors = {
	{ COLOR_METALS_BRUSHED_STEEL, "Brushed Steel" },
	{ COLOR_METALS_BRUSHED_BLACK_STEEL, "Brushed Black Steel" },
	{ COLOR_METALS_BRUSHED_ALUMINUM, "Brushed Aluminium" },
	{ COLOR_METALS_PURE_GOLD, "Pure Gold" },
	{ COLOR_METALS_BRUSHED_GOLD, "Brushed Gold" }
};

static const std::map<int, std::string> lsc_headlight_colors = {
	{ XENON_DEFAULT, "Default" },
	{ XENON_WHITE, "White" },
	{ XENON_BLUE, "Blue" },
	{ XENON_ELECTRIC_BLUE, "Electric Blue" },
	{ XENON_MINT_GREEN, "Mint Green" },
	{ XENON_LIME_GREEN, "Lime Green" },
	{ XENON_YELLOW, "Yellow" },
	{ XENON_GOLDEN_SHOWER, "Golden Shower" },
	{ XENON_ORANGE, "Orange" },
	{ XENON_RED, "Red" },
	{ XENON_PONY_PINK, "Pony Pink" },
	{ XENON_HOT_PINK, "Hot Pink" },
	{ XENON_PURPLE, "Purple" },
	{ XENON_BACKLIGHT, "Backlight" }
};

static const std::map<std::string, std::vector<int>> lsc_tire_smoke_rgb = {
	{ "White", { TIRESMOKE_COLOR_WHITE } },
	{ "Black", { TIRESMOKE_COLOR_BLACK } },
	{ "Blue", { TIRESMOKE_COLOR_BLUE } },
	{ "Yellow", { TIRESMOKE_COLOR_YELLOW } },
	{ "Purple", { TIRESMOKE_COLOR_PURPLE } },
	{ "Orange", { TIRESMOKE_COLOR_ORANGE } },
	{ "Green", { TIRESMOKE_COLOR_GREEN } },
	{ "Red", { TIRESMOKE_COLOR_RED } },
	{ "Pink", { TIRESMOKE_COLOR_PINK } },
	{ "Brown", { TIRESMOKE_COLOR_BROWN } }
};

static const std::map<std::string, std::vector<int>> lsc_neon_rgb = {
	{ "White", { NEON_COLOR_WHITE } },
	{ "Blue", { NEON_COLOR_BLUE } },
	{ "Electro Blue", { NEON_COLOR_ELECTRICBLUE } },
	{ "Mint Green", { NEON_COLOR_MINTGREEN } },
	{ "Lime Green", { NEON_COLOR_LIMEGREEN } },
	{ "Yellow", { NEON_COLOR_YELLOW } },
	{ "Golden Shower", { NEON_COLOR_GOLDENSHOWER } },
	{ "Orange", { NEON_COLOR_ORANGE } },
	{ "Red", { NEON_COLOR_RED } },
	{ "Pony Pink", { NEON_COLOR_PONYPINK } },
	{ "Hot Pink", { NEON_COLOR_HOTPINK } },
	{ "Purple", { NEON_COLOR_PURPLE } }
};
