broken_probot = Creature:new {
	customName = "broken_probot",
	socialGroup = "",
	faction = "",
	level = 5,
	chanceHit = 0.250000,
	damageMin = 45,
	damageMax = 50,
	baseXp = 85,
	baseHAM = 135,
	baseHAMmax = 165,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.000000,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = PACK,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,

	templates = {"object/mobile/probot.iff"},
	lootGroups = {
		{
			groups = {
				{group = "junk", chance = 7500000},
				{group = "loot_kit_parts", chance = 2000000},
				{group = "armor_all", chance = 250000},
				{group = "weapons_all", chance = 250000}
			},
			lootChance = 5000000
		}
	},
	weapons = {"droid_probot_ranged"},
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(broken_probot, "broken_probot")