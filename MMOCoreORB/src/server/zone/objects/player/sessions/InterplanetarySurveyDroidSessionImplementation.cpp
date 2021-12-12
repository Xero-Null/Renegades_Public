#include "server/zone/objects/player/sessions/InterplanetarySurveyDroidSession.h"
#include "server/zone/managers/resource/ResourceManager.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/scene/SessionFacadeType.h"
#include "server/zone/objects/tangible/tool/SurveyTool.h"
#include "server/zone/objects/player/sessions/sui/SurveyDroidSessionSuiCallback.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/tangible/component/Component.h"
#include "server/zone/managers/resource/InterplanetarySurvey.h"
#include "server/zone/managers/resource/InterplanetarySurveyTask.h"

int InterplanetarySurveyDroidSessionImplementation::cancelSession() {
	ManagedReference<CreatureObject*> player = this->player.get();
	if (player != nullptr) {
		player->dropActiveSession(SessionFacadeType::INTERPLANETARYSURVEYDROID);
		player->getPlayerObject()->removeSuiBoxType(SuiWindowType::SURVERY_DROID_MENU);
	}

	clearSession();

	return 0;
}

bool InterplanetarySurveyDroidSessionImplementation::hasSurveyTool() {
	ManagedReference<CreatureObject*> player = this->player.get();

	if (player == nullptr)
		return false;

	ManagedReference<SceneObject*> inventory = player->getSlottedObject("inventory");

	if (inventory == nullptr)
		return false;

	Locker inventoryLocker(inventory);

	for (int i = 0; i < inventory->getContainerObjectsSize(); ++i) {
		ManagedReference<SceneObject*> sceno = inventory->getContainerObject(i);

		uint32 objType = sceno->getGameObjectType();

		if (objType == SceneObjectType::SURVEYTOOL) {
			return true;
		}
	}

	return false;
}

void InterplanetarySurveyDroidSessionImplementation::initalizeDroid(TangibleObject* droid) {
	droidObject = droid;
	ManagedReference<CreatureObject*> player = this->player.get();

	if (!hasSurveyTool()) {
		player->sendSystemMessage("@pet/droid_modules:survey_no_survey_tools");
		cancelSession();
		return;
	}

	ManagedReference<SceneObject*> inventory = player->getSlottedObject("inventory");

	if (inventory == nullptr) {
		cancelSession();
		return;
	}

	Locker invLocker(inventory);

	// fire up sui box
	droidSuiBox = new SuiListBox(player, SuiWindowType::SURVERY_DROID_MENU, 2);
	droidSuiBox->setPromptTitle("@pet/droid_modules:survey_planet_title");
	droidSuiBox->setPromptText("@pet/droid_modules:survey_planet_prompt");

	// Loop planets and add them in
	player->getZoneServer()->getResourceManager()->addPlanetsToListBox(droidSuiBox);
	droidSuiBox->setUsingObject(droid);
	droidSuiBox->setCallback(new SurveyDroidSessionSuiCallback(player->getZoneServer()));

	droidSuiBox->setCancelButton(true, "@cancel");
	player->getPlayerObject()->addSuiBox(droidSuiBox);
	player->sendMessage(droidSuiBox->generateMessage());
}

void InterplanetarySurveyDroidSessionImplementation::handleMenuSelect(CreatureObject* pl, uint64 menuID, SuiListBox* suiBox) {
	ManagedReference<CreatureObject*> player = this->player.get();
	ManagedReference<TangibleObject*> tangibleObject = this->droidObject.get();

	if (tangibleObject == nullptr || player == nullptr || player != pl)
		return;

	// which did he pick? first or second callback?

	Locker droidLocker(tangibleObject);

	Component* component = dynamic_cast<Component*>(tangibleObject.get());

	if (component == nullptr) {
		cancelSession();
		return;
	}

	float quality = component->getAttributeValue("mechanism_quality");
	uint64 chosen = droidSuiBox->getMenuObjectID(menuID);
	this->targetPlanet = pl->getZoneServer()->getResourceManager()->getPlanetByIndex(chosen);
	int duration = (2800 - (27 * quality));

	if (duration < 60) duration = 60;

	int minutes = duration / 60;

	duration *= 1000;

	StringBuffer buffer;
	buffer << "Droid sent, ETA for the report is ";
	buffer << minutes;
	buffer << " minutes.";
	pl->sendSystemMessage(buffer.toString());

	// Create a bogus task to run to show the output to the console
	ManagedReference<InterplanetarySurvey*> data = new InterplanetarySurvey();
	Time expireTime;
	uint64 currentTime = expireTime.getMiliTime();

	// TEst case: add this for the future and persist it.
	data->setPlanet(this->targetPlanet);
	data->setSurveyToolType(1);
	data->setRequestor(pl->getFirstName());
	data->setCurTime(currentTime);
	data->setTimeStamp(duration);
	data->setSurveyType("mineral");

	Reference<InterplanetarySurveyTask*> task = new InterplanetarySurveyTask(data.get());
	task->schedule(duration); // remove the tools form the world

	ObjectManager::instance()->persistObject(data, 1, "surveys");

	tangibleObject->decreaseUseCount();
	cancelSession();
}
