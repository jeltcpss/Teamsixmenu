#pragma once
#include "gta/joaat.hpp"

namespace big
{
	constexpr const static inline auto launcher_scripts = std::to_array({
	    0u,
	    RAGE_JOAAT("AM_HOLD_UP"),
	    0u,
	    RAGE_JOAAT("AM_CR_SELL_DRUGS"),
	    RAGE_JOAAT("AM_STRIPPER"),
	    RAGE_JOAAT("stripclub_mp"),
	    RAGE_JOAAT("AM_ArmWrestling"),
	    RAGE_JOAAT("AM_ImportExport"),
	    RAGE_JOAAT("AM_Tennis"),
	    RAGE_JOAAT("AM_Darts"),
	    RAGE_JOAAT("AM_FistFight"),
	    RAGE_JOAAT("AM_DropOffHooker"),
	    RAGE_JOAAT("AM_Safehouse"),
	    RAGE_JOAAT("AM_Hitchhiker"),
	    0u,
	    RAGE_JOAAT("AM_DOORS"),
	    RAGE_JOAAT("MG_RACE_TO_POINT"),
	    RAGE_JOAAT("AM_PI_MENU"),
	    RAGE_JOAAT("AM_CRATE_DROP"),
	    RAGE_JOAAT("AM_IMP_EXP"),
	    RAGE_JOAAT("FM_INTRO"),
	    RAGE_JOAAT("AM_PROSTITUTE"),
	    RAGE_JOAAT("AM_TAXI"),
	    RAGE_JOAAT("AM_TAXI_LAUNCHER"),
	    RAGE_JOAAT("AM_GANG_CALL"),
	    RAGE_JOAAT("heli_gun"),
	    RAGE_JOAAT("AM_backup_heli"),
	    RAGE_JOAAT("AM_airstrike"),
	    RAGE_JOAAT("AM_AMMO_DROP"),
	    RAGE_JOAAT("AM_VEHICLE_DROP"),
	    RAGE_JOAAT("AM_BRU_BOX"),
	    RAGE_JOAAT("AM_GA_PICKUPS"),
	    RAGE_JOAAT("AM_JOYRIDER"),
	    RAGE_JOAAT("AM_PLANE_TAKEDOWN"),
	    RAGE_JOAAT("AM_DISTRACT_COPS"),
	    RAGE_JOAAT("AM_DESTROY_VEH"),
	    RAGE_JOAAT("AM_HOT_TARGET"),
	    RAGE_JOAAT("AM_KILL_LIST"),
	    RAGE_JOAAT("AM_TIME_TRIAL"),
	    RAGE_JOAAT("AM_CP_COLLECTION"),
	    RAGE_JOAAT("AM_CHALLENGES"),
	    RAGE_JOAAT("AM_PENNED_IN"),
	    RAGE_JOAAT("AM_PASS_THE_PARCEL"),
	    RAGE_JOAAT("AM_HOT_PROPERTY"),
	    RAGE_JOAAT("AM_DEAD_DROP"),
	    RAGE_JOAAT("AM_KING_OF_THE_CASTLE"),
	    RAGE_JOAAT("AM_CRIMINAL_DAMAGE"),
	    RAGE_JOAAT("AM_HUNT_THE_BEAST"),
	    RAGE_JOAAT("GB_LIMO_ATTACK"),
	    RAGE_JOAAT("GB_DEATHMATCH"),
	    RAGE_JOAAT("GB_STEAL_VEH"),
	    RAGE_JOAAT("GB_POINT_TO_POINT"),
	    RAGE_JOAAT("GB_TERMINATE"),
	    RAGE_JOAAT("GB_YACHT_ROB"),
	    RAGE_JOAAT("GB_BELLYBEAST"),
	    RAGE_JOAAT("GB_FIVESTAR"),
	    RAGE_JOAAT("GB_ROB_SHOP"),
	    RAGE_JOAAT("GB_COLLECT_MONEY"),
	    RAGE_JOAAT("GB_ASSAULT"),
	    RAGE_JOAAT("GB_VEH_SURV"),
	    RAGE_JOAAT("GB_SIGHTSEER"),
	    RAGE_JOAAT("GB_FLYING_IN_STYLE"),
	    RAGE_JOAAT("GB_FINDERSKEEPERS"),
	    RAGE_JOAAT("GB_HUNT_THE_BOSS"),
	    RAGE_JOAAT("GB_CARJACKING"),
	    RAGE_JOAAT("GB_HEADHUNTER"),
	    RAGE_JOAAT("GB_CONTRABAND_BUY"),
	    RAGE_JOAAT("GB_CONTRABAND_SELL"),
	    RAGE_JOAAT("GB_CONTRABAND_DEFEND"),
	    RAGE_JOAAT("GB_AIRFREIGHT"),
	    RAGE_JOAAT("GB_CASHING_OUT"),
	    RAGE_JOAAT("GB_SALVAGE"),
	    RAGE_JOAAT("GB_FRAGILE_GOODS"),
	    RAGE_JOAAT("GB_VEHICLE_EXPORT"),
	    RAGE_JOAAT("GB_VEHICLE_EXPORT"),
	    RAGE_JOAAT("GB_PLOUGHED"),
	    RAGE_JOAAT("GB_FULLY_LOADED"),
	    RAGE_JOAAT("GB_AMPHIBIOUS_ASSAULT"),
	    RAGE_JOAAT("GB_TRANSPORTER"),
	    RAGE_JOAAT("GB_FORTIFIED"),
	    RAGE_JOAAT("GB_VELOCITY"),
	    RAGE_JOAAT("GB_RAMPED_UP"),
	    RAGE_JOAAT("GB_STOCKPILING"),
	    RAGE_JOAAT("GB_BIKER_RACE_P2P"),
	    RAGE_JOAAT("GB_BIKER_JOUST"),
	    RAGE_JOAAT("GB_BIKER_UNLOAD_WEAPONS"),
	    0u,
	    RAGE_JOAAT("GB_BIKER_BAD_DEAL"),
	    RAGE_JOAAT("GB_BIKER_RESCUE_CONTACT"),
	    RAGE_JOAAT("GB_BIKER_LAST_RESPECTS"),
	    RAGE_JOAAT("GB_BIKER_CONTRACT_KILLING"),
	    RAGE_JOAAT("GB_BIKER_CONTRABAND_SELL"),
	    RAGE_JOAAT("GB_BIKER_CONTRABAND_DEFEND"),
	    RAGE_JOAAT("GB_ILLICIT_GOODS_RESUPPLY"),
	    RAGE_JOAAT("GB_BIKER_DRIVEBY_ASSASSIN"),
	    RAGE_JOAAT("GB_BIKER_RIPPIN_IT_UP"),
	    RAGE_JOAAT("GB_BIKER_FREE_PRISONER"),
	    RAGE_JOAAT("GB_BIKER_SAFECRACKER"),
	    RAGE_JOAAT("GB_BIKER_STEAL_BIKES"),
	    RAGE_JOAAT("GB_BIKER_SEARCH_AND_DESTROY"),
	    RAGE_JOAAT("AM_PENNED_IN"),
	    RAGE_JOAAT("GB_BIKER_STAND_YOUR_GROUND"),
	    RAGE_JOAAT("GB_BIKER_CRIMINAL_MISCHIEF"),
	    RAGE_JOAAT("GB_BIKER_DESTROY_VANS"),
	    RAGE_JOAAT("GB_BIKER_BURN_ASSETS"),
	    RAGE_JOAAT("GB_BIKER_SHUTTLE"),
	    RAGE_JOAAT("GB_BIKER_WHEELIE_RIDER"),
	    RAGE_JOAAT("GB_GUNRUNNING"),
	    RAGE_JOAAT("GB_GUNRUNNING"),
	    RAGE_JOAAT("GB_GUNRUNNING_DEFEND"),
	    RAGE_JOAAT("GB_SMUGGLER"),
	    RAGE_JOAAT("GB_SMUGGLER"),
	    RAGE_JOAAT("GB_SMUGGLER"),
	    RAGE_JOAAT("GB_GANGOPS"),
	    RAGE_JOAAT("Business Battles"),
	    RAGE_JOAAT("BUSINESS_BATTLES_SELL"),
	    RAGE_JOAAT("BUSINESS_BATTLES_DEFEND"),
	    RAGE_JOAAT("GB_SECURITY_VAN"),
	    RAGE_JOAAT("GB_TARGET_PURSUIT"),
	    RAGE_JOAAT("GB_JEWEL_STORE_GRAB"),
	    RAGE_JOAAT("GB_BANK_JOB"),
	    RAGE_JOAAT("GB_DATA_HACK"),
	    RAGE_JOAAT("GB_INFILTRATION"),
	    RAGE_JOAAT("BUSINESS_BATTLES_DEFEND"),
	    RAGE_JOAAT("BUSINESS_BATTLES_SELL"),
	    RAGE_JOAAT("GB_CASINO"),
	    RAGE_JOAAT("GB_CASINO_HEIST"),
	    RAGE_JOAAT("fm_content_business_battles"),
	    RAGE_JOAAT("fm_content_drug_vehicle"),
	    RAGE_JOAAT("fm_content_movie_props"),
	    RAGE_JOAAT("fm_content_island_heist"),
	    RAGE_JOAAT("fm_content_island_dj"),
	    RAGE_JOAAT("AM_ISLAND_BACKUP_HELI"),
	    RAGE_JOAAT("fm_content_golden_gun"),
	    RAGE_JOAAT("fm_content_tuner_robbery"),
	    RAGE_JOAAT("fm_content_vehicle_list"),
	    RAGE_JOAAT("tuner_sandbox_activity"),
	    RAGE_JOAAT("fm_content_auto_shop_delivery"),
	    RAGE_JOAAT("fm_content_payphone_hit"),
	    RAGE_JOAAT("fm_content_security_contract"),
	    RAGE_JOAAT("fm_content_vip_contract_1"),
	    RAGE_JOAAT("fm_content_metal_detector"),
	    RAGE_JOAAT("am_agency_suv"),
	    RAGE_JOAAT("fm_content_phantom_car"),
	    RAGE_JOAAT("fm_content_slasher"),
	    RAGE_JOAAT("fm_content_sightseeing"),
	    RAGE_JOAAT("fm_content_smuggler_trail"),
	    RAGE_JOAAT("fm_content_smuggler_plane"),
	    RAGE_JOAAT("fm_content_skydive"),
	    RAGE_JOAAT("fm_content_cerberus"),
	    RAGE_JOAAT("fm_content_parachuter"),
	    RAGE_JOAAT("fm_content_crime_scene"),
	    RAGE_JOAAT("fm_content_bar_resupply"),
	    RAGE_JOAAT("fm_content_bike_shop_delivery"),
	    RAGE_JOAAT("fm_content_clubhouse_contracts"),
	    RAGE_JOAAT("fm_content_cargo"),
	    RAGE_JOAAT("fm_content_export_cargo"),
	    RAGE_JOAAT("fm_content_ammunation"),
	    RAGE_JOAAT("fm_content_gunrunning"),
	    RAGE_JOAAT("fm_content_source_research"),
	    RAGE_JOAAT("fm_content_club_management"),
	    RAGE_JOAAT("fm_content_club_odd_jobs"),
	    RAGE_JOAAT("fm_content_club_source"),
	    RAGE_JOAAT("fm_content_convoy"),
	    RAGE_JOAAT("fm_content_robbery"),
	    RAGE_JOAAT("fm_content_acid_lab_setup"),
	    RAGE_JOAAT("fm_content_acid_lab_source"),
	    RAGE_JOAAT("fm_content_acid_lab_sell"),
	    RAGE_JOAAT("fm_content_drug_lab_work"),
	    RAGE_JOAAT("fm_content_stash_house"),
	    RAGE_JOAAT("fm_content_taxi_driver"),
	    RAGE_JOAAT("fm_content_xmas_mugger"),
	    RAGE_JOAAT("fm_content_bank_shootout"),
	    RAGE_JOAAT("fm_content_armoured_truck"),
	    RAGE_JOAAT("fm_content_ghosthunt"),
	    RAGE_JOAAT("fm_content_smuggler_sell"),
	    RAGE_JOAAT("fm_content_smuggler_resupply"),
	    RAGE_JOAAT("fm_content_smuggler_ops"),
	    RAGE_JOAAT("fm_content_bicycle_time_trial"),
	    RAGE_JOAAT("fm_content_possessed_animals"),
	    RAGE_JOAAT("AM_BOAT_TAXI"),
	    RAGE_JOAAT("AM_HELI_TAXI"),
	    RAGE_JOAAT("fm_hold_up_tut"),
	    RAGE_JOAAT("AM_CAR_MOD_TUT"),
	    RAGE_JOAAT("AM_CONTACT_REQUESTS"),
	    RAGE_JOAAT("am_mission_launch"),
	    RAGE_JOAAT("am_npc_invites"),
	    RAGE_JOAAT("am_lester_cut"),
	    RAGE_JOAAT("am_heist_int"),
	    RAGE_JOAAT("am_lowrider_int"),
	    RAGE_JOAAT("AM_VEHICLE_SPAWN"),
	    RAGE_JOAAT("am_ronTrevor_Cut"),
	    RAGE_JOAAT("AM_ARMYBASE"),
	    RAGE_JOAAT("AM_PRISON"),
	    RAGE_JOAAT("am_rollercoaster"),
	    RAGE_JOAAT("am_ferriswheel"),
	    RAGE_JOAAT("AM_LAUNCHER"),
	    RAGE_JOAAT("AM_DAILY_OBJECTIVES"),
	    RAGE_JOAAT("AM_ArmWrestling"),
	    RAGE_JOAAT("AM_Darts"),
	    RAGE_JOAAT("golf_mp"),
	    RAGE_JOAAT("Range_Modern_MP"),
	    RAGE_JOAAT("tennis_network_mp"),
	    RAGE_JOAAT("Pilot_School_MP"),
	    RAGE_JOAAT("FM_Impromptu_DM_Controler"),
	    RAGE_JOAAT("fm_Bj_race_controler"),
	    RAGE_JOAAT("fm_deathmatch_controler"),
	    RAGE_JOAAT("fm_hideout_controler"),
	    RAGE_JOAAT("fm_mission_controller"),
	    RAGE_JOAAT("FM_Race_Controler"),
	    RAGE_JOAAT("FM_Horde_Controler"),
	    RAGE_JOAAT("dont_cross_the_line"),
	    RAGE_JOAAT("am_darts_apartment"),
	    RAGE_JOAAT("AM_Armwrestling_Apartment"),
	    RAGE_JOAAT("grid_arcade_cabinet"),
	    RAGE_JOAAT("scroll_arcade_cabinet"),
	    RAGE_JOAAT("example_arcade"),
	    RAGE_JOAAT("road_arcade"),
	    RAGE_JOAAT("gunslinger_arcade"),
	    RAGE_JOAAT("wizard_arcade"),
	    RAGE_JOAAT("AM_CASINO_LIMO"),
	    RAGE_JOAAT("AM_CASINO_LUXURY_CAR"),
	    RAGE_JOAAT("Degenatron Games"),
	    RAGE_JOAAT("ggsm_arcade"),
	    RAGE_JOAAT("puzzle"),
	    RAGE_JOAAT("camhedz_arcade"),
	    RAGE_JOAAT("SCTV"),
	});

	constexpr const static inline auto all_script_names = std::to_array({
	    "abigail1",
	    "abigail2",
	    "achievement_controller",
	    "act_cinema",
	    //"activity_creator_prototype_launcher",
	    "af_intro_t_sandy",
	    "agency_heist1",
	    "agency_heist2",
	    "agency_heist3a",
	    "agency_heist3b",
	    "agency_prep1",
	    "agency_prep2amb",
	    //"aicover_test",
	    //"ainewengland_test",
	    "altruist_cult",
	    "am_airstrike",
	    "am_ammo_drop",
	    "am_arena_shp",
	    "am_armwrestling_apartment",
	    "am_armwrestling",
	    "am_armybase",
	    "am_backup_heli",
	    "am_beach_washup_cinematic",
	    "am_boat_taxi",
	    "am_bru_box",
	    "am_car_mod_tut",
	    "am_casino_limo",
	    "am_casino_luxury_car",
	    "am_casino_peds",
	    "am_challenges",
	    "am_contact_requests",
	    "am_cp_collection",
	    "am_crate_drop",
	    "am_criminal_damage",
	    "am_darts_apartment",
	    "am_darts",
	    "am_dead_drop",
	    "am_destroy_veh",
	    "am_distract_cops",
	    "am_doors",
	    "am_ferriswheel",
	    "am_ga_pickups",
	    "am_gang_call",
	    "am_heist_int",
	    "am_heli_taxi",
	    "am_hi_plane_land_cinematic",
	    "am_hi_plane_take_off_cinematic",
	    "am_hold_up",
	    "am_hot_property",
	    "am_hot_target",
	    "am_hs4_isd_take_vel",
	    "am_hs4_lsa_land_nimb_arrive",
	    "am_hs4_lsa_land_vel",
	    "am_hs4_lsa_take_vel",
	    "am_hs4_nimb_isd_lsa_leave",
	    "am_hs4_nimb_lsa_isd_arrive",
	    "am_hs4_nimb_lsa_isd_leave",
	    "am_hs4_vel_lsa_isd",
	    "am_hunt_the_beast",
	    "am_imp_exp",
	    "am_island_backup_heli",
	    "am_joyrider",
	    "am_kill_list",
	    "am_king_of_the_castle",
	    "am_launcher",
	    "am_lester_cut",
	    "am_lowrider_int",
	    "am_lsia_take_off_cinematic",
	    "am_mission_launch",
	    "am_mp_arc_cab_manager",
	    "am_mp_arcade_claw_crane",
	    "am_mp_arcade_fortune_teller",
	    "am_mp_arcade_love_meter",
	    "am_mp_arcade_peds",
	    "am_mp_arcade_strength_test",
	    "am_mp_arcade",
	    "am_mp_arena_box",
	    "am_mp_arena_garage",
	    "am_mp_armory_aircraft",
	    "am_mp_armory_truck",
	    "am_mp_auto_shop",
	    "am_mp_biker_warehouse",
	    "am_mp_boardroom_seating",
	    "am_mp_bunker",
	    "am_mp_business_hub",
	    "am_mp_car_meet_property",
	    "am_mp_car_meet_sandbox",
	    "am_mp_carwash_launch",
	    "am_mp_casino_apartment",
	    "am_mp_casino_nightclub",
	    "am_mp_casino_valet_garage",
	    "am_mp_casino",
	    "am_mp_creator_aircraft",
	    "am_mp_creator_trailer",
	    "am_mp_defunct_base",
	    "am_mp_drone",
	    "am_mp_garage_control",
	    "am_mp_hacker_truck",
	    "am_mp_hangar",
	    "am_mp_ie_warehouse",
	    "am_mp_island",
	    "am_mp_nightclub",
	    "am_mp_orbital_cannon",
	    "am_mp_peds",
	    "am_mp_property_ext",
	    "am_mp_property_int",
	    "am_mp_rc_vehicle",
	    "am_mp_shooting_range",
	    "am_mp_smoking_activity",
	    "am_mp_smpl_interior_ext",
	    "am_mp_smpl_interior_int",
	    "am_mp_solomon_office",
	    "am_mp_submarine",
	    "am_mp_vehicle_reward",
	    "am_mp_vehicle_weapon",
	    "am_mp_warehouse",
	    "am_mp_yacht",
	    "am_npc_invites",
	    "am_pass_the_parcel",
	    "am_penned_in",
	    "am_penthouse_peds",
	    "am_pi_menu",
	    "am_plane_takedown",
	    "am_prison",
	    "am_prostitute",
	    "am_rollercoaster",
	    "am_rontrevor_cut",
	    "am_taxi",
	    "am_vehicle_spawn",
	    "ambient_diving",
	    "ambient_mrsphilips",
	    "ambient_solomon",
	    "ambient_sonar",
	    "ambient_tonya",
	    "ambient_tonyacall2",
	    "ambient_tonyacall5",
	    "ambient_tonyacall",
	    "ambient_ufos",
	    "ambientblimp",
	    "animal_controller",
	    "apartment_minigame_launcher",
	    "apparcadebusiness",
	    "apparcadebusinesshub",
	    "appbikerbusiness",
	    "appbroadcast",
	    "appbunkerbusiness",
	    "appbusinesshub",
	    "appcamera",
	    "appchecklist",
	    "appcontacts",
	    "appcovertops",
	    "appemail",
	    "appextraction",
	    "apphackertruck",
	    "apphs_sleep",
	    "appimportexport",
	    "appinternet",
	    "appjipmp",
	    "appmedia",
	    "appmpbossagency",
	    "appmpemail",
	    "appmpjoblistnew",
	    "apporganiser",
	    "apprepeatplay",
	    "appsecurohack",
	    "appsecuroserv",
	    "appsettings",
	    "appsidetask",
	    "appsmuggler",
	    "apptextmessage",
	    "apptrackify",
	    "appvlsi",
	    "appzit",
	    "arcade_seating",
	    "arena_box_bench_seats",
	    "arena_carmod",
	    "arena_workshop_seats",
	    "armenian1",
	    "armenian2",
	    "armenian3",
	    "armory_aircraft_carmod",
	    "assassin_bus",
	    "assassin_construction",
	    "assassin_hooker",
	    "assassin_multi",
	    "assassin_rankup",
	    "assassin_valet",
	    "atm_trigger",
	    //"audiotest",
	    "auto_shop_seating",
	    "autosave_controller",
	    "bailbond1",
	    "bailbond2",
	    "bailbond3",
	    "bailbond4",
	    "bailbond_launcher",
	    "barry1",
	    "barry2",
	    "barry3",
	    "barry3a",
	    "barry3c",
	    "barry4",
	    "base_carmod",
	    "base_corridor_seats",
	    "base_entrance_seats",
	    "base_heist_seats",
	    "base_lounge_seats",
	    "base_quaters_seats",
	    "base_reception_seats",
	    //"basic_creator",
	    "beach_exterior_seating",
	    "benchmark",
	    "bigwheel",
	    "bj",
	    "blackjack",
	    "blimptest",
	    "blip_controller",
	    "bootycall_debug_controller",
	    "bootycallhandler",
	    "buddydeathresponse",
	    //"bugstar_mission_export",
	    "building_controller",
	    "buildingsiteambience",
	    "business_battles_defend",
	    "business_battles_sell",
	    "business_battles",
	    "business_hub_carmod",
	    "business_hub_garage_seats",
	    "cablecar",
	    //"cam_coord_sender",
	    //"camera_test",
	    "camhedz_arcade",
	    "candidate_controller",
	    "car_meet_carmod",
	    "car_meet_exterior_seating",
	    "car_roof_test",
	    "carmod_shop",
	    "carsteal1",
	    "carsteal2",
	    "carsteal3",
	    "carsteal4",
	    "carwash1",
	    "carwash2",
	    "casino_bar_seating",
	    "casino_exterior_seating",
	    "casino_interior_seating",
	    "casino_lucky_wheel",
	    "casino_main_lounge_seating",
	    "casino_nightclub_seating",
	    "casino_penthouse_seating",
	    "casino_slots",
	    "casinoroulette",
	    //"celebration_editor",
	    "celebrations",
	    "cellphone_controller",
	    "cellphone_flashhand",
	    "charactergoals",
	    //"charanimtest",
	    "cheat_controller",
	    "chinese1",
	    "chinese2",
	    "chop",
	    "clothes_shop_mp",
	    "clothes_shop_sp",
	    "code_controller",
	    //"combat_test",
	    "comms_controller",
	    "completionpercentage_controller",
	    "component_checker",
	    "context_controller",
	    "controller_ambientarea",
	    "controller_races",
	    "controller_taxi",
	    "controller_towing",
	    "controller_trafficking",
	    "coordinate_recorder",
	    "country_race_controller",
	    "country_race",
	    "creation_startup",
	    "creator",
	    //"custom_config",
	    //"cutscene_test",
	    //"cutscenemetrics",
	    //"cutscenesamples",
	    "darts",
	    //"debug_app_select_screen",
	    //"debug_clone_outfit_testing",
	    //"debug_launcher",
	    //"debug_ped_data",
	    //"debug",
	    "degenatron_games",
	    //"density_test",
	    "dialogue_handler",
	    "director_mode",
	    "docks2asubhandler",
	    "docks_heista",
	    "docks_heistb",
	    "docks_prep1",
	    "docks_prep2b",
	    "docks_setup",
	    "dont_cross_the_line",
	    "dreyfuss1",
	    "drf1",
	    "drf2",
	    "drf3",
	    "drf4",
	    "drf5",
	    "drunk_controller",
	    "drunk",
	    //"dynamixtest",
	    "email_controller",
	    "emergencycall",
	    "emergencycalllauncher",
	    "epscars",
	    "epsdesert",
	    "epsilon1",
	    "epsilon2",
	    "epsilon3",
	    "epsilon4",
	    "epsilon5",
	    "epsilon6",
	    "epsilon7",
	    "epsilon8",
	    "epsilontract",
	    "epsrobes",
	    "error_listener",
	    //"error_thrower",
	    "event_controller",
	    "exile1",
	    "exile2",
	    "exile3",
	    "exile_city_denial",
	    "extreme1",
	    "extreme2",
	    "extreme3",
	    "extreme4",
	    "fairgroundhub",
	    "fake_interiors",
	    "fame_or_shame_set",
	    "fameorshame_eps_1",
	    "fameorshame_eps",
	    "family1",
	    "family1taxi",
	    "family2",
	    "family3",
	    "family4",
	    "family5",
	    "family6",
	    "family_scene_f0",
	    "family_scene_f1",
	    "family_scene_m",
	    "family_scene_t0",
	    "family_scene_t1",
	    "fanatic1",
	    "fanatic2",
	    "fanatic3",
	    "fbi1",
	    "fbi2",
	    "fbi3",
	    "fbi4_intro",
	    "fbi4_prep1",
	    "fbi4_prep2",
	    "fbi4_prep3",
	    "fbi4_prep3amb",
	    "fbi4_prep4",
	    "fbi4_prep5",
	    "fbi4",
	    "fbi5a",
	    "finale_choice",
	    "finale_credits",
	    "finale_endgame",
	    "finale_heist1",
	    "finale_heist2_intro",
	    "finale_heist2a",
	    "finale_heist2b",
	    "finale_heist_prepa",
	    "finale_heist_prepb",
	    "finale_heist_prepc",
	    "finale_heist_prepd",
	    "finale_heist_prepeamb",
	    "finale_intro",
	    "finalea",
	    "finaleb",
	    "finalec1",
	    "finalec2",
	    "floating_help_controller",
	    "flow_autoplay",
	    "flow_controller",
	    "flow_help",
	    "flowintrotitle",
	    "flowstartaccept",
	    "flyunderbridges",
	    "fm_bj_race_controler",
	    "fm_capture_creator",
	    "fm_content_auto_shop_delivery",
	    "fm_content_business_battles",
	    "fm_content_drug_vehicle",
	    "fm_content_golden_gun",
	    "fm_content_island_dj",
	    "fm_content_island_heist",
	    "fm_content_movie_props",
	    "fm_content_phantom_car",
	    "fm_content_sightseeing",
	    "fm_content_slasher",
	    "fm_content_tuner_robbery",
	    "fm_content_vehicle_list",
	    "fm_deathmatch_controler",
	    "fm_deathmatch_creator",
	    "fm_hideout_controler",
	    "fm_hold_up_tut",
	    "fm_horde_controler",
	    "fm_impromptu_dm_controler",
	    "fm_intro_cut_dev",
	    "fm_intro",
	    "fm_lts_creator",
	    "fm_main_menu",
	    "fm_maintain_cloud_header_data",
	    "fm_maintain_transition_players",
	    "fm_mission_controller_2020",
	    "fm_mission_controller",
	    //"fm_mission_creator",
	    "fm_race_controler",
	    "fm_race_creator",
	    "fm_survival_controller",
	    "fm_survival_creator",
	    "fmmc_launcher",
	    "fmmc_playlist_controller",
	    "forsalesigns",
	    //"fps_test_mag",
	    //"fps_test",
	    "franklin0",
	    "franklin1",
	    "franklin2",
	    "freemode_clearglobals",
	    "freemode_creator",
	    "freemode_init",
	    "freemode",
	    "friendactivity",
	    "friends_controller",
	    "friends_debug_controller",
	    //"fullmap_test_flow",
	    //"fullmap_test",
	    //"game_server_test",
	    "gb_airfreight",
	    "gb_amphibious_assault",
	    "gb_assault",
	    "gb_bank_job",
	    "gb_bellybeast",
	    "gb_biker_bad_deal",
	    "gb_biker_burn_assets",
	    "gb_biker_contraband_defend",
	    "gb_biker_contraband_sell",
	    "gb_biker_contract_killing",
	    "gb_biker_criminal_mischief",
	    "gb_biker_destroy_vans",
	    "gb_biker_driveby_assassin",
	    "gb_biker_free_prisoner",
	    "gb_biker_joust",
	    "gb_biker_last_respects",
	    "gb_biker_race_p2p",
	    "gb_biker_rescue_contact",
	    "gb_biker_rippin_it_up",
	    "gb_biker_safecracker",
	    "gb_biker_search_and_destroy",
	    "gb_biker_shuttle",
	    "gb_biker_stand_your_ground",
	    "gb_biker_steal_bikes",
	    "gb_biker_target_rival",
	    "gb_biker_unload_weapons",
	    "gb_biker_wheelie_rider",
	    "gb_carjacking",
	    "gb_cashing_out",
	    "gb_casino_heist_planning",
	    "gb_casino_heist",
	    "gb_casino",
	    "gb_collect_money",
	    "gb_contraband_buy",
	    "gb_contraband_defend",
	    "gb_contraband_sell",
	    "gb_data_hack",
	    "gb_deathmatch",
	    "gb_delivery",
	    "gb_finderskeepers",
	    "gb_fivestar",
	    "gb_fortified",
	    "gb_fragile_goods",
	    "gb_fully_loaded",
	    "gb_gang_ops_planning",
	    "gb_gangops",
	    "gb_gunrunning_defend",
	    "gb_gunrunning_delivery",
	    "gb_gunrunning",
	    "gb_headhunter",
	    "gb_hunt_the_boss",
	    "gb_ie_delivery_cutscene",
	    "gb_illicit_goods_resupply",
	    "gb_infiltration",
	    "gb_jewel_store_grab",
	    "gb_ploughed",
	    "gb_point_to_point",
	    "gb_ramped_up",
	    "gb_rob_shop",
	    "gb_salvage",
	    "gb_security_van",
	    "gb_sightseer",
	    "gb_smuggler",
	    "gb_stockpiling",
	    "gb_target_pursuit",
	    "gb_terminate",
	    "gb_transporter",
	    "gb_vehicle_export",
	    "gb_velocity",
	    "gb_yacht_rob",
	    "general_test",
	    "ggsm_arcade",
	    "globals_fmmc_struct_registration",
	    "globals_fmmcstruct2_registration",
	    "golf_ai_foursome_putting",
	    "golf_ai_foursome",
	    "golf_mp",
	    "golf",
	    "gpb_andymoon",
	    "gpb_baygor",
	    "gpb_billbinder",
	    "gpb_clinton",
	    "gpb_griff",
	    "gpb_jane",
	    "gpb_jerome",
	    "gpb_jesse",
	    "gpb_mani",
	    "gpb_mime",
	    "gpb_pameladrake",
	    "gpb_superhero",
	    "gpb_tonya",
	    "gpb_zombie",
	    "grid_arcade_cabinet",
	    //"gtest_airplane",
	    //"gtest_avoidance",
	    //"gtest_boat",
	    //"gtest_divingfromcar",
	    //"gtest_divingfromcarwhilefleeing",
	    //"gtest_helicopter",
	    //"gtest_nearlymissedbycar",
	    "gunclub_shop",
	    "gunfighttest",
	    "gunslinger_arcade",
	    "hacker_truck_carmod",
	    "hairdo_shop_mp",
	    "hairdo_shop_sp",
	    "hangar_carmod",
	    "hao1",
	    //"headertest",
	    //"heatmap_test_flow",
	    //"heatmap_test",
	    "heist_ctrl_agency",
	    "heist_ctrl_docks",
	    "heist_ctrl_finale",
	    "heist_ctrl_jewel",
	    "heist_ctrl_rural",
	    "heist_island_planning",
	    "heli_gun",
	    "heli_streaming",
	    //"hud_creator",
	    "hunting1",
	    "hunting2",
	    "hunting_ambient",
	    "idlewarper",
	    "ingamehud",
	    "initial",
	    "jewelry_heist",
	    "jewelry_prep1a",
	    "jewelry_prep1b",
	    "jewelry_prep2a",
	    "jewelry_setup1",
	    "josh1",
	    "josh2",
	    "josh3",
	    "josh4",
	    "lamar1",
	    "laptop_trigger",
	    "launcher_abigail",
	    "launcher_barry",
	    "launcher_basejumpheli",
	    "launcher_basejumppack",
	    "launcher_carwash",
	    "launcher_darts",
	    "launcher_dreyfuss",
	    "launcher_epsilon",
	    "launcher_extreme",
	    "launcher_fanatic",
	    "launcher_golf",
	    "launcher_hao",
	    "launcher_hunting_ambient",
	    "launcher_hunting",
	    "launcher_josh",
	    "launcher_maude",
	    "launcher_minute",
	    "launcher_mrsphilips",
	    "launcher_nigel",
	    "launcher_offroadracing",
	    "launcher_omega",
	    "launcher_paparazzo",
	    "launcher_pilotschool",
	    "launcher_racing",
	    "launcher_rampage",
	    "launcher_range",
	    "launcher_stunts",
	    "launcher_tennis",
	    "launcher_thelastone",
	    "launcher_tonya",
	    "launcher_triathlon",
	    "launcher_yoga",
	    "lester1",
	    "lesterhandler",
	    "letterscraps",
	    //"line_activation_test",
	    "liverecorder",
	    //"locates_tester",
	    "luxe_veh_activity",
	    //"magdemo2",
	    //"magdemo",
	    "main_install",
	    "main_persistent",
	    "main",
	    "maintransition",
	    "martin1",
	    "maude1",
	    "maude_postbailbond",
	    "me_amanda1",
	    "me_jimmy1",
	    "me_tracey1",
	    "mg_race_to_point",
	    "michael1",
	    "michael2",
	    "michael3",
	    "michael4",
	    "michael4leadout",
	    "minigame_ending_stinger",
	    "minigame_stats_tracker",
	    "minute1",
	    "minute2",
	    "minute3",
	    "mission_race",
	    "mission_repeat_controller",
	    "mission_stat_alerter",
	    "mission_stat_watcher",
	    "mission_triggerer_a",
	    "mission_triggerer_b",
	    "mission_triggerer_c",
	    "mission_triggerer_d",
	    "missioniaaturret",
	    "mp_awards",
	    "mp_bed_high",
	    "mp_fm_registration",
	    "mp_menuped",
	    "mp_prop_global_block",
	    "mp_prop_special_global_block",
	    "mp_registration",
	    "mp_save_game_global_block",
	    "mp_unlocks",
	    "mp_weapons",
	    "mpstatsinit",
	    //"mptestbed",
	    "mrsphilips1",
	    "mrsphilips2",
	    "murdermystery",
	    "navmeshtest",
	    //"net_activity_creator_ui",
	    //"net_apartment_activity_light",
	    //"net_apartment_activity",
	    //"net_bot_brain",
	    //"net_bot_simplebrain",
	    //"net_cloud_mission_loader",
	    //"net_combat_soaktest",
	    //"net_jacking_soaktest",
	    //"net_rank_tunable_loader",
	    //"net_session_soaktest",
	    //"net_tunable_check",
	    "nigel1",
	    "nigel1a",
	    "nigel1b",
	    "nigel1c",
	    "nigel1d",
	    "nigel2",
	    "nigel3",
	    "nightclub_ground_floor_seats",
	    "nightclub_office_seats",
	    "nightclub_vip_seats",
	    "nightclubpeds",
	    //"nodemenututorial",
	    //"nodeviewer",
	    "ob_abatdoor",
	    "ob_abattoircut",
	    "ob_airdancer",
	    "ob_bong",
	    "ob_cashregister",
	    "ob_drinking_shots",
	    "ob_foundry_cauldron",
	    "ob_franklin_beer",
	    "ob_franklin_tv",
	    "ob_franklin_wine",
	    "ob_huffing_gas",
	    "ob_jukebox",
	    "ob_mp_bed_high",
	    "ob_mp_bed_low",
	    "ob_mp_bed_med",
	    "ob_mp_shower_med",
	    "ob_mp_stripper",
	    "ob_mr_raspberry_jam",
	    "ob_poledancer",
	    "ob_sofa_franklin",
	    "ob_sofa_michael",
	    "ob_telescope",
	    "ob_tv",
	    "ob_vend1",
	    "ob_vend2",
	    "ob_wheatgrass",
	    "offroad_races",
	    "omega1",
	    "omega2",
	    "paparazzo1",
	    "paparazzo2",
	    "paparazzo3",
	    "paparazzo3a",
	    "paparazzo3b",
	    "paparazzo4",
	    "paradise2",
	    "paradise",
	    //"pausemenu_example",
	    "pausemenu_map",
	    "pausemenu_multiplayer",
	    "pausemenu_sp_repeat",
	    "pausemenu",
	    "pb_busker",
	    "pb_homeless",
	    "pb_preacher",
	    "pb_prostitute",
	    "personal_carmod_shop",
	    "photographymonkey",
	    "photographywildlife",
	    //"physics_perf_test_launcher",
	    //"physics_perf_test",
	    "pi_menu",
	    "pickup_controller",
	    //"pickuptest",
	    "pickupvehicles",
	    "pilot_school_mp",
	    "pilot_school",
	    "placeholdermission",
	    //"placementtest",
	    //"planewarptest",
	    "player_controller_b",
	    "player_controller",
	    "player_scene_f_lamgraff",
	    "player_scene_f_lamtaunt",
	    "player_scene_f_taxi",
	    "player_scene_ft_franklin1",
	    "player_scene_m_cinema",
	    "player_scene_m_fbi2",
	    "player_scene_m_kids",
	    "player_scene_m_shopping",
	    "player_scene_mf_traffic",
	    "player_scene_t_bbfight",
	    "player_scene_t_chasecar",
	    "player_scene_t_insult",
	    "player_scene_t_park",
	    "player_scene_t_tie",
	    "player_timetable_scene",
	    //"playthrough_builder",
	    "pm_defend",
	    "pm_delivery",
	    "pm_gang_attack",
	    "pm_plane_promotion",
	    "pm_recover_stolen",
	    "postkilled_bailbond2",
	    "postrc_barry1and2",
	    "postrc_barry4",
	    "postrc_epsilon4",
	    "postrc_nigel3",
	    "profiler_registration",
	    "prologue1",
	    //"prop_drop",
	    "puzzle",
	    //"racetest",
	    "rampage1",
	    "rampage2",
	    "rampage3",
	    "rampage4",
	    "rampage5",
	    "rampage_controller",
	    "randomchar_controller",
	    "range_modern_mp",
	    "range_modern",
	    "re_abandonedcar",
	    "re_accident",
	    "re_armybase",
	    "re_arrests",
	    "re_atmrobbery",
	    "re_bikethief",
	    "re_border",
	    "re_burials",
	    "re_bus_tours",
	    "re_cartheft",
	    "re_chasethieves",
	    "re_crashrescue",
	    "re_cultshootout",
	    "re_dealgonewrong",
	    "re_domestic",
	    "re_drunkdriver",
	    "re_duel",
	    "re_gang_intimidation",
	    "re_gangfight",
	    "re_getaway_driver",
	    "re_hitch_lift",
	    "re_homeland_security",
	    "re_lossantosintl",
	    "re_lured",
	    "re_monkey",
	    "re_mountdance",
	    "re_muggings",
	    "re_paparazzi",
	    "re_prison",
	    "re_prisonerlift",
	    "re_prisonvanbreak",
	    "re_rescuehostage",
	    "re_seaplane",
	    "re_securityvan",
	    "re_shoprobbery",
	    "re_snatched",
	    "re_stag_do",
	    "re_yetarian",
	    "replay_controller",
	    "rerecord_recording",
	    "respawn_controller",
	    "restrictedareas",
	    //"rng_output",
	    "road_arcade",
	    "rollercoaster",
	    "rural_bank_heist",
	    "rural_bank_prep1",
	    "rural_bank_setup",
	    "save_anywhere",
	    "savegame_bed",
	    "sc_lb_global_block",
	    //"scaleformgraphictest",
	    //"scaleformminigametest",
	    //"scaleformprofiling",
	    //"scaleformtest",
	    //"scene_builder",
	    "sclub_front_bouncer",
	    //"script_metrics",
	    //"scripted_cam_editor",
	    //"scriptplayground",
	    //"scripttest1",
	    //"scripttest2",
	    //"scripttest3",
	    //"scripttest4",
	    "scroll_arcade_cabinet",
	    "sctv",
	    //"selector_example",
	    "selector",
	    "selling_short_1",
	    "selling_short_2",
	    "sh_intro_f_hills",
	    "sh_intro_m_home",
	    //"shooting_camera",
	    "shop_controller",
	    "shoprobberies",
	    "shot_bikejump",
	    "shrinkletter",
	    //"smoketest",
	    "social_controller",
	    "solomon1",
	    "solomon2",
	    "solomon3",
	    "sp_dlc_registration",
	    //"sp_editor_mission_instance",
	    "sp_menuped",
	    "sp_pilotschool_reg",
	    "spaceshipparts",
	    "spawn_activities",
	    "speech_reverb_tracker",
	    "spmc_instancer",
	    "spmc_preloader",
	    "standard_global_init",
	    "standard_global_reg",
	    "startup_install",
	    "startup_locationtest",
	    "startup_positioning",
	    "startup_smoketest",
	    "startup",
	    "stats_controller",
	    "stock_controller",
	    "streaming",
	    "stripclub_drinking",
	    "stripclub_mp",
	    "stripclub",
	    "stripperhome",
	    "stunt_plane_races",
	    "tasklist_1",
	    "tattoo_shop",
	    "taxi_clowncar",
	    "taxi_cutyouin",
	    "taxi_deadline",
	    "taxi_followcar",
	    "taxi_gotyounow",
	    "taxi_gotyourback",
	    "taxi_needexcitement",
	    "taxi_procedural",
	    "taxi_takeiteasy",
	    "taxi_taketobest",
	    "taxilauncher",
	    "taxiservice",
	    "taxitutorial",
	    //"tempalpha",
	    //"temptest",
	    "tennis_ambient",
	    "tennis_family",
	    "tennis_network_mp",
	    "tennis",
	    "test_startup",
	    "thelastone",
	    "three_card_poker",
	    "timershud",
	    "title_update_registration_2",
	    "title_update_registration",
	    "tonya1",
	    "tonya2",
	    "tonya3",
	    "tonya4",
	    "tonya5",
	    "towing",
	    "traffick_air",
	    "traffick_ground",
	    "traffickingsettings",
	    "traffickingteleport",
	    //"train_create_widget",
	    //"train_tester",
	    "trevor1",
	    "trevor2",
	    "trevor3",
	    "trevor4",
	    "triathlonsp",
	    "tunables_registration",
	    "tuneables_processing",
	    "tuner_planning",
	    "tuner_property_carmod",
	    "tuner_sandbox_activity",
	    "turret_cam_script",
	    "ufo",
	    "ugc_global_registration",
	    "underwaterpickups",
	    //"utvc",
	    "valentinerpreward2",
	    "veh_play_widget",
	    //"vehicle_ai_test",
	    //"vehicle_force_widget",
	    "vehicle_gen_controller",
	    //"vehicle_plate",
	    "vehicle_stealth_mode",
	    "vehiclespawning",
	    //"walking_ped",
	    "wardrobe_mp",
	    "wardrobe_sp",
	    //"weapon_audio_widget",
	    "wizard_arcade",
	    "wp_partyboombox",
	    //"xml_menus",
	    "yoga",

	    // 1.58 Contract DLC

	    "am_agency_suv",
	    "am_mp_fixer_hq",
	    "am_mp_music_studio",
	    "appfixersecurity",
	    "fixer_hq_carmod",
	    "fixer_hq_seating_op_floor",
	    "fixer_hq_seating_pq",
	    "fixer_hq_seating",
	    "fm_content_payphone_hit",
	    "fm_content_payphone_intro",
	    "fm_content_security_contract",
	    "fm_content_vip_contract_1",
	    "music_studio_seating_external",
	    "music_studio_seating",
	    "music_studio_smoking",
	    "ugc_global_registration_2",

	    // 1.59 Next Gen Patch

	    "car_meet_interior_seating",
	    "fm_content_hsw_setup",
	    "fm_content_hsw_time_trial",
	    "fm_content_mp_intro",
	    "landing_pre_startup",

	    // 1.61

	    "am_luxury_showroom",
	    "am_mp_simeon_showroom",
	    "fm_content_ammunation",
	    "fm_content_bar_resupply",
	    "fm_content_bike_shop_delivery",
	    "fm_content_cargo",
	    "fm_content_cerberus",
	    "fm_content_club_management",
	    "fm_content_club_odd_jobs",
	    "fm_content_club_source",
	    "fm_content_clubhouse_contracts",
	    "fm_content_crime_scene",
	    "fm_content_export_cargo",
	    "fm_content_gunrunning",
	    "fm_content_metal_detector",
	    "fm_content_parachuter",
	    "fm_content_skydive",
	    "fm_content_smuggler_plane",
	    "fm_content_smuggler_trail",
	    "fm_content_source_research",
	    "net_test_drive",
	    "simeon_showroom_seating",
	});
}