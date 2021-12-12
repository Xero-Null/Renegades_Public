#include "SceneObjectType.h"

const String SceneObjectType::typeToString(int gameObjectType) {
	switch (gameObjectType) {
		case OBJECT:					return "@got_n:none";
		case CORPSE:					return "@got_n:corpse";
		case GROUPOBJECT:				return "@got_n:misc";
		case GUILDOBJECT:				return "@got_n:misc";
		case LAIR:						return "@got_n:lair";
		case STATICOBJECT:				return "@got_n:static";
		case VENDOR:					return "@got_n:misc";
		case LOADBEACON:				return "@got_n:misc";
		case CELLOBJECT:				return "@got_n:misc";
		case PLAYEROBJECT:				return "@got_n:creature_character";
		case ARMOR:						return "@got_n:armor";
		case BODYARMOR:					return "@got_n:armor_body";
		case HEADARMOR:					return "@got_n:armor_head";
		case MISCARMOR:					return "@got_n:armor_misc";
		case LEGARMOR:					return "@got_n:armor_leg";
		case ARMARMOR:					return "@got_n:armor_arm";
		case HANDARMOR:					return "@got_n:armor_hand";
		case FOOTARMOR:					return "@got_n:armor_foot";
		case SHIELDGENERATOR:			return "@got_n:armor_shield";
		case BUILDING:					return "@got_n:building";
		case MUNICIPALBUILDING:			return "@got_n:building_municipal";
		case PLAYERBUILDING:			return "@got_n:building_player";
		case FACTIONBUILDING:			return "@got_n:building_factional";
		case TUTORIALBUILDING:			return "@got_n:building";
		case HOSPITALBUILDING:			return "@got_n:building";
		case RECREATIONBUILDING:		return "@got_n:building";
		case TRAVELBUILDING:			return "@got_n:building";
		case STARPORTBUILDING:			return "@got_n:building";
		case CAPITOLBUILDING:			return "@got_n:building";
		case HOTELBUILDING:				return "@got_n:building";
		case THEATERBUILDING:			return "@got_n:building";
		case COMBATBUILDING:			return "@got_n:building";
		case COMMERCEBUILDING:			return "@got_n:building";
		case UNIVERSITYBUILDING:		return "@got_n:building";
		case GARAGEBUILDING:			return "@got_n:building";
		case CITYHALLBUILDING:			return "@got_n:building";
		case SALONBUILDING:				return "@got_n:building";
		case POIBUILDING:				return "@got_n:building";
		case CREATURE:					return "@got_n:creature";
		case NPCCREATURE:				return "@got_n:creature_character";
		case DROIDCREATURE:				return "@got_n:creature_droid";
		case PROBOTCREATURE:			return "@got_n:creature_droid_probe";
		case PLAYERCREATURE:			return "@got_n:creature_monster";
		case TRAINERCREATURE:			return "got_n:creature";
		case INFORMANTCREATURE:			return "got_n:creature";
		case VENDORCREATURE:			return "got_n:creature";
		case INTANGIBLE:				return "@got_n:data";
		case DRAFTSCHEMATIC:			return "@got_n:data_draft_schematic";
		case MANUFACTURINGSCHEMATIC:	return "@got_n:data_manufacturing_schematic";
		case MISSIONOBJECT:				return "@got_n:data_mission_object";
		case TOKEN:						return "@got_n:data_token";
		case WAYPOINT:					return "@got_n:data_waypoint";
		case DATA2:						return "@got_n:data_fictional";
		case PETCONTROLDEVICE:			return "@got_n:data_pet_control_device";
		case VEHICLECONTROLDEVICE:		return "@got_n:data_vehicle_control_device";
		case SHIPCONTROLDEVICE:			return "@got_n:data_ship_control_deice";
		case DROIDCONTROLDEVICE:		return "@got_n:data_droid_control_device";
		case THEATEROBJECT:				return "@got_n:misc";
		case INSTALLATION:				return "@got_n:installation";
		case FACTORY:					return "@got_n:installation_factory";
		case GENERATOR:					return "@got_n:installation_generator";
		case HARVESTER:					return "@got_n:installation_harvester";
		case DESTRUCTIBLE:				return "@got_n:installation_turret";
		case MINEFIELD:					return "@got_n:installation_minefield";
		case GARAGEINSTALLATION:		return "@got_n:installation";
		case SHUTTLEINSTALLATION:		return "@got_n:installation";
		case TANGIBLE:					return "@got_n:misc";
		case AMMUNITION:				return "@got_n:misc_ammunition";
		case CHEMICAL:					return "@got_n:misc_chemical";
		case CONTAINER:					return "@got_n:misc_container";
		case CRAFTINGSTATION:			return "@got_n:misc_crafting_station";
		case ELECTRONICS:				return "@got_n:misc_electronics";
		case FLORA:						return "@got_n:misc_flora";
		case FOOD:						return "@got_n:misc_food";
		case FURNITURE:					return "@got_n:misc_furniture";
		case INSTRUMENT:				return "@got_n:misc_instrument";
		case PHARMACEUTICAL:			return "@got_n:misc_pharmaceutical";
		case SIGN:						return "@got_n:misc_sign";
		case COUNTER:					return "@got_n:misc_counter";
		case FACTORYCRATE:				return "@got_n:misc_factory_crate";
		case TRAVELTICKET:				return "@got_n:misc_ticket_travel";
		case GENERICITEM:				return "@got_n:misc_item";
		case TRAP:						return "@got_n:misc_trap";
		case WEARABLECONTAINER:			return "@got_n:misc_container_wearable";
		case FISHINGPOLE:				return "@got_n:misc_fishing_pole";
		case FISHINGBAIT:				return "@got_n:misc_fishing_bait";
		case DRINK:						return "@got_n:misc_drink";
		case FIREWORK:					return "@got_n:misc_firework";
		case ITEM:						return "@got_n:misc_item_usable";
		case PETMEDECINE:				return "@got_n:misc_petmed";
		case FIREWORKSHOW:				return "@got_n:misc_firework_show";
		case CLOTHINGATTACHMENT:		return "@got_n:misc_clothing_attachment";
		case LIVESAMPLE:				return "@got_n:misc_live_sample";
		case ARMORATTACHMENT:			return "@got_n:misc_armor_attachment";
		case COMMUNITYCRAFTINGPROJECT:	return "@got_n:misc_community_crafting_project";
		case CRYSTAL:					return "@got_n:misc_force_crystal";
		case DROIDPROGRAMMINGCHIP:		return "@got_n:misc_droid_programming_chip";
		case ASTEROID:					return "@got_n:misc_asteroid";
		case PILOTCHAIR:				return "@got_n:misc_pob_ship_pilot_chair";
		case OPERATIONSCHAIR:			return "@got_n:misc_operations_chair";
		case TURRETACCESSLADDER:		return "@got_n:misc_turret_access_ladder";
		case CONTAINER2:				return "@got_n:misc_container_ship_loot";
		case CAMOKIT:					return "@got_n:misc";
		case LOOTKIT:					return "@got_n:misc";
		case FISH:						return "@got_n:misc";
		case STIMPACK:					return "@got_n:misc";
		case RANGEDSTIMPACK:			return "@got_n:misc";
		case ENHANCEPACK:				return "@got_n:misc";
		case CUREPACK:					return "@got_n:misc";
		case DOTPACK:					return "@got_n:misc";
		case WOUNDPACK:					return "@got_n:misc";
		case STATEPACK:					return "@got_n:misc";
		case REVIVEPACK:				return "@got_n:misc";
		case STATICLOOTCONTAINER:		return "@got_n:misc";
		case PLAYERLOOTCRATE:			return "@got_n:misc";
		case FSPUZZLEPACK:				return "@got_n:misc";
		case GROWABLEPLANT:				return "@got_n:misc";
		case FSCRAFTINGCOMPONENT:		return "@got_n:misc";
		case FSCSOBJECT:				return "@got_n:misc";
		case FSBUFFITEM:				return "@got_n:misc";
		case CONTRACTCRATE:				return "@got_n:misc";
		case TERMINAL:					return "@got_n:terminal";
		case BANK:						return "@got_n:terminal_bank";
		case BAZAAR:					return "@got_n:terminal_bazaar";
		case CLONING:					return "@got_n:terminal_cloning";
		case INSURANCE:					return "@got_n:terminal_insurance";
		case MANAGEMENTTERMINAL:		return "@got_n:terminal_manage";
		case MISSIONTERMINAL:			return "@got_n:terminal_mission";
		case PERMISSIONSTERMINAL:		return "@got_n:terminal_permissions";
		case PLAYERTERMINALSTRUCTURE:	return "@got_n:terminal_player_structure";
		case SHIPPINGTERMINAL:			return "@got_n:terminal_shipping";
		case SPACETERMINAL:				return "@got_n:terminal_space";
		case INTERACTIVETERMINAL:		return "@got_n:terminal_misc";
		case NEWBIETUTORIALTERMINAL:	return "@got_n:terminal_misc";
		case CHARACTERBUILDERTERMINAL:	return "@got_n:terminal_misc";
		case TICKETCOLLECTOR:			return "@got_n:terminal";
		case TRAVELTERMINAL:			return "@got_n:terminal_travel";
		case GUILDTERMINAL:				return "@got_n:terminal_manage";
		case CITYTERMINAL:				return "@got_n:terminal_manage";
		case CITYVOTETERMINAL:			return "@got_n:terminal_manage";
		case GAMBLINGTERMINAL:			return "@got_n:terminal_misc";
		case JUKEBOX:					return "@got_n:terminal_misc";
		case FLAGGAME:					return "@got_n:misc";
		case EVENTPERK:					return "@got_n:misc";
		case LOTTERYDROID:				return "@got_n:misc";
		case SCAVENGERCHEST:			return "@got_n:misc";
		case SHUTTLEBEACON:				return "@got_n:misc";
		case SCAVENGERDROID:			return "@got_n:misc";
		case TOOL:						return "@got_n:tool";
		case CRAFTINGTOOL:				return "@got_n:tool_crafting";
		case SURVEYTOOL:				return "@got_n:tool_survey";
		case REPAIRTOOL:				return "@got_n:tool_repair";
		case CAMPKIT:					return "@got_n:tool_camp_kit";
		case SHIPCOMPONENTREPAIRITEM:	return "@got_n:tool_ship_component_repair";
		case SLICINGTOOL:				return "@got_n:tool";
		case MOLECULARCLAMP:			return "@got_n:tool";
		case FLOWANALYZER:				return "@got_n:tool";
		case LASERKNIFE:				return "@got_n:tool";
		case WEAPONUPGRADEKIT:			return "@got_n:tool";
		case ARMORUPGRADEKIT:			return "@got_n:tool";
		case RECYCLETOOL:				return "@got_n:tool";
		case ANTIDECAYKIT:				return "@got_n:tool";
		case VEHICLE:					return "@got_n:vehicle";
		case HOVERVEHICLE:				return "@got_n:vehicle_hover";
		case WEAPON:					return "@got_n:weapon";
		case MELEEWEAPON:				return "@got_n:weapon_melee_misc";
		case RANGEDWEAPON:				return "@got_n:weapon_ranged_misc";
		case THROWNWEAPON:				return "@got_n:weapon_ranged_thrown";
		case HEAVYWEAPON:				return "@got_n:weapon_heavy_misc";
		case MINE:						return "@got_n:weapon_heavy_mine";
		case SPECIALHEAVYWEAPON:		return "@got_n:weapon_heavy_special";
		case ONEHANDMELEEWEAPON:		return "@got_n:weapon_melee_1h";
		case TWOHANDMELEEWEAPON:		return "@got_n:weapon_melee_2h";
		case POLEARM:					return "@got_n:weapon_melee_polearm";
		case PISTOL:					return "@got_n:weapon_ranged_pistol";
		case CARBINE:					return "@got_n:weapon_ranged_carbine";
		case RIFLE:						return "@got_n:weapon_ranged_rifle";
		case COMPONENT:					return "@got_n:component";
		case ARMORCOMPONENT:			return "@got_n:component_armor";
		case CHEMISTRYCOMPONENT:		return "@got_n:component_chemistry";
		case CLOTHINGCOMPONENT:			return "@got_n:component_clothing";
		case DROIDCOMPONENT:			return "@got_n:component_droid";
		case ELECTRONICSCOMPONENT:		return "@got_n:component_electronics";
		case MUNITIONCOMPONENT:			return "@got_n:component_munition";
		case STRUCTURECOMPONENT:		return "@got_n:component_structure";
		case MELEEWEAPONCOMPONENT:		return "@got_n:component_weapon_melee";
		case RANGEDWEAPONCOMPONENT:		return "@got_n:component_weapon_ranged";
		case TISSUECOMPONENT:			return "@got_n:component_tissue";
		case GENETICCOMPONENT:			return "@got_n:component_genetic";
		case LIGHTSABERCRYSTAL:			return "@got_n:component_saber_crystal";
		case COMMUNITYCRAFTINGCOMPONENT:return "@got_n:component_community_crafting";
		case DNACOMPONENT:				return "@got_n:component";
		case WEAPONPOWERUP:				return "@got_n:powerup_weapon";
		case MELEEWEAPONPOWERUP:		return "@got_n:powerup_weapon_melee";
		case RANGEDWEAPONPOWERUP:		return "@got_n:powerup_weapon_ranged";
		case THROWNWEAPONPOWERUP:		return "@got_n:powerup_weapon_thrown";
		case HEAVYWEAPONPOWERUP:		return "@got_n:powerup_weapon_heavy";
		case MINEPOWERUP:				return "@got_n:powerup_weapon_mine";
		case SPECIALHEAVYWEAPONPOWERUP:	return "@got_n:powerup_weapon_heavy_special";
		case ARMORPOWERUP:				return "@got_n:powerup_armor";
		case BODYARMORPOWERUP:			return "@got_n:powerup_armor_body";
		case HEADARMORPOWERUP:			return "@got_n:powerup_armor_head";
		case MISCARMORPOWERUP:			return "@got_n:powerup_armor_misc";
		case LEGARMORPOWERUP:			return "@got_n:powerup_armor_leg";
		case ARMARMORPOWERUP:			return "@got_n:powerup_armor_arm";
		case HANDARMORPOWERUP:			return "@got_n:powerup_armor_hand";
		case FOOTARMORPOWERUP:			return "@got_n:powerup_armor_foot";
		case JEWELRY:					return "@got_n:jewelry";
		case RING:						return "@got_n:jewelry_ring";
		case BRACELET:					return "@got_n:jewelry_bracelet";
		case NECKLACE:					return "@got_n:jewelry_necklace";
		case EARRING:					return "@got_n:jewelry_earring";
		case RESOURCECONTAINER:			return "@got_n:resource_container";
		case ENERGYGAS:					return "@got_n:resource_container_energy_gas";
		case ENERGYLIQUID:				return "@got_n:resource_container_energy_liquid";
		case ENERGYRADIOACTIVE:			return "@got_n:resource_container_energy_radioactive";
		case ENERGYSOLID:				return "@got_n:resource_container_energy_solid";
		case INORGANICCHEMICAL:			return "@got_n:resource_container_inorganic_chemicals";
		case INORGANICGAS:				return "@got_n:resource_container_inorganic_gas";
		case INORGANICMINERAL:			return "@got_n:resource_container_inorganic_minerals";
		case WATER:						return "@got_n:resource_container_inorganic_water";
		case ORGANICFOOD:				return "@got_n:resource_container_organic_food";
		case ORGANICHIDE:				return "@got_n:resource_container_organic_hide";
		case ORGANICSTRUCTURAL:			return "@got_n:resource_container_organic_structure";
		case QUESTRESOURCE:				return "@got_n:resource_container_pseudo";
		case RESOURCESPAWN:				return "got_n:misc";
		case DEED:						return "@got_n:deed";
		case BUILDINGDEED:				return "@got_n:deed_building";
		case INSTALLATIONDEED:			return "@got_n:deed_installation";
		case PETDEED:					return "@got_n:deed_pet";
		case DROIDDEED:					return "@got_n:deed_droid";
		case VEHICLEDEED:				return "@got_n:deed_vehicle";
		case RESOURCEDEED:				return "@got_n:deed";
		case EVENTPERKDEED:				return "@got_n:deed";
		case VETHARVESTERDEED:			return "@got_n:deed";
		case CLOTHING:					return "@got_n:clothing";
		case BANDOLIER:					return "@got_n:clothing_bandolier";
		case BELT:						return "@got_n:clothing_belt";
		case BODYSUIT:					return "@got_n:clothing_bodysuit";
		case CAPE:						return "@got_n:clothing_cape";
		case CLOAK:						return "@got_n:clothing_cloak";
		case FOOTWEAR:					return "@got_n:clothing_foot";
		case DRESS:						return "@got_n:clothing_dress";
		case HANDWEAR:					return "@got_n:clothing_hand";
		case EYEWEAR:					return "@got_n:clothing_eye";
		case HEADWEAR:					return "@got_n:clothing_head";
		case JACKET:					return "@got_n:clothing_jacket";
		case PANTS:						return "@got_n:clothing_pants";
		case ROBE:						return "@got_n:clothing_robe";
		case SHIRT:						return "@got_n:clothing_shirt";
		case VEST:						return "@got_n:clothing_vest";
		case WOOKIEGARB:				return "@got_n:clothing_wookiee";
		case MISCCLOTHING:				return "@got_n:clothing_misc";
		case SKIRT:						return "@got_n:clothing_skirt";
		case BADGEAREA:					return "@got_n:misc";
		case REGIONAREA:				return "@got_n:misc";
		case MISSIONSPAWNAREA:			return "@got_n:misc";
		case MISSIONRECONAREA:			return "@got_n:misc";
		case SPAWNAREA:					return "@got_n:misc";
		case ACTIVEAREA:				return "@got_n:misc";
		case CAMPAREA:					return "@got_n:misc";
		case FSVILLAGEAREA:				return "@got_n:misc";
		case SARLACCAREA:				return "@got_n:misc";
		case NAVMESHAREA:				return "@got_n:misc";
		case SHIP:						return "@got_n:ship";
		case SHIPFIGHTER:				return "@got_n:ship_fighter";
		case SHIPCAPITAL:				return "@got_n:ship_capital";
		case SHIPSTATION:				return "@got_n:ship_station";
		case SHIPTRANSPORT:				return "@got_n:ship_transport";
		case SHIPATTACHMENT:			return "@got_n:ship_component";
		case SHIPREACTOR:				return "@got_n:ship_component_reactor";
		case SHIPENGINE:				return "@got_n:ship_component_engine";
		case SHIPSHIELDGENERATOR:		return "@got_n:ship_component_shield";
		case SHIPARMOR:					return "@got_n:ship_component_armor";
		case SHIPWEAPON:				return "@got_n:ship_component_weapon";
		case SHIPWEAPONCAPACITOR:		return "@got_n:ship_component_capacitor";
		case SHIPBOOSTER:				return "@got_n:ship_component_booster";
		case SHIPDRIODINTERFACE:		return "@got_n:ship_component_droid_interface";
		case HANGER:					return "@got_n:ship_component_hangar";
		case TARGETINGSTATION:			return "@got_n:ship_component_targeting_station";
		case BRIDGE:					return "@got_n:ship_component_bridge";
		case SHIPCHASSIS:				return "@got_n:ship_component_chassis";
		case SHIPMISSILE:				return "@got_n:ship_component_missilepack";
		case SHIPCOUNTERMEASURE:		return "@got_n:ship_component_countermeasurepack";
		case SHIPWEAPONLAUNCHER:		return "@got_n:ship_component_missilelauncher";
		case SHIPCOUNTERMEASURELAUNCHER:return "@got_n:ship_component_countermeasurelauncher";
		default:						return "@got_n:misc";
}
}