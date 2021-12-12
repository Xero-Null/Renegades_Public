luke_skywalker_city_control = Creature:new {
	objectName = "@mob/creature_names:luke_skywalker",
	socialGroup = "rebel",
	faction = "rebel",
	level = 100,
	chanceHit = 1,
	damageMin = 645,
	damageMax = 1000,
	baseXp = 9429,
	baseHAM = 24000,
	baseHAMmax = 30000,
	armor = 0,
	resists = {0,0,0,0,0,0,0,0,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = NONE,
	optionsBitmask = AIENABLED + INVULNERABLE,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_luke_skywalker.iff"},
	lootGroups = {},
	weapons = {"luke_skywalker_weapons"},
	conversationTemplate = "",
	attacks = merge(lightsabermaster, forcepowermaster)
}

CreatureTemplates:addCreatureTemplate(luke_skywalker_city_control, "luke_skywalker_city_control")