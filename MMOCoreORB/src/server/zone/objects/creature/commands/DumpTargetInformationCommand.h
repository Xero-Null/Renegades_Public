/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef DUMPTARGETINFORMATIONCOMMAND_H_
#define DUMPTARGETINFORMATIONCOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"

class DumpTargetInformationCommand : public QueueCommand {
public:

	DumpTargetInformationCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		if (!creature->isPlayerCreature())
			return GENERALERROR;

		CreatureObject* player = cast<CreatureObject*>(creature);

		//Apparently this command doesn't actually pass the targetid, so that probably means that it only accepts a player name
		//TODO: Reimplement this command as @getPlayerInfo
		uint64 targetID = player->getTargetID();

		ManagedReference<SceneObject*> obj = server->getZoneServer()->getObject(targetID);

		if (obj == nullptr)
			return INVALIDTARGET;

		ManagedReference<CellObject*> cell = obj->getParent().get().castTo<CellObject*>();

		int cellid = 0;
		uint32 buildingTemplate = 0;

		if (cell != nullptr) {
			cellid = cell->getCellNumber();
			ManagedReference<SceneObject*> building = cell->getParent().get();
			buildingTemplate = building->getServerObjectCRC();
		}

		StringBuffer msg;

		float posX = obj->getPositionX(), posZ = obj->getPositionZ(), posY = obj->getPositionY();
		const Quaternion* direction = obj->getDirection();

		msg << "x = " << posX << ", z = " << posZ << ", y = " << posY << ", ow = " << direction->getW()
				<< ", ox = " << direction->getX() << ", oz = " << direction->getZ() << ", oy = " << direction->getY()
				<< ", cellid = " << cellid;
		
		float y = direction->getY();
		float z = direction->getZ();
		float x = direction->getX();
		float w = direction->getW();
		msg << endl << endl
		<< "ClientMatrix data: " << endl
		<< "Matrix1: " << 1 - 2 * (y * y +  z * z) << ", " << 2 * (x * y - w * z) << ", " << 2 * (x * z + w * y) << endl
		<< "X: " << posX << endl
		<< "Matrix2: " << 2 * (x * y + w * z) << ", " <<  1 - 2 * (x * x + z * z) << ", " <<  2 * (y * z - w * x) << endl
		<< "Z: " << posZ << endl
		<< "Matrix3: " << 2 * (x * z - w * y) << ", " <<  2 * (y * z + w * x) << ", " <<  1 - 2 * (x * x + y * y) << endl
		<< "Y: " << posY << endl << endl;

		if (buildingTemplate != 0)
			msg << endl << TemplateManager::instance()->getTemplateFile(buildingTemplate);

		if (obj->isAiAgent())
		{
			AiAgent* objCreo = obj.castTo<AiAgent*>();

			PatrolPoint* home = objCreo->getHomeLocation();
			if (home != nullptr) {
				cell = home->getCell();

				if (cell != nullptr) {
					cellid = cell->getCellNumber();
					ManagedReference<SceneObject*> building = cell->getParent().get();
					buildingTemplate = building->getServerObjectCRC();
				}

				msg << endl << "homeX = " << home->getPositionX() << ", homeZ = " << home->getPositionZ() << ", homeY = " << home->getPositionY()
						<< ", homeCell = " << cellid;

				if (buildingTemplate != 0)
					msg << endl << TemplateManager::instance()->getTemplateFile(buildingTemplate);
			}

			if (objCreo->getPatrolPointSize() > 0) {
				PatrolPoint nextPosition = objCreo->getNextPosition();
				cell = nextPosition.getCell();

				if (cell != nullptr) {
					cellid = cell->getCellNumber();
					ManagedReference<SceneObject*> building = cell->getParent().get();
					buildingTemplate = building->getServerObjectCRC();
				}

				msg << endl << "nextX = " << nextPosition.getPositionX() << ", nextZ = " << nextPosition.getPositionZ() << ", nextY = " << nextPosition.getPositionY()
						<< ", nextCell = " << cellid;

				if (buildingTemplate != 0)
					msg << endl << TemplateManager::instance()->getTemplateFile(buildingTemplate);
			}

			msg << endl << "numberOfPlayersInRange = " << objCreo->getNumberOfPlayersInRange();

			msg << endl << "spawnMobile(" << obj->getZone()->getZoneName() << ", " << obj->getObjectNameStringIdName() << ", 0, " << posX << ", " << posZ << ", " << posY << ", 0, (parentID + " << cellid << "))";
		}
		else
		{
			msg << endl << "spawnSceneObject(" << obj->getZone()->getZoneName() << ", " << obj->getObjectTemplate()->getFullTemplateString() << ", " << posX << ", " << posZ << ", " << posY << ", (parentID + " << cellid << "), 0)";
		}

		player->sendSystemMessage(msg.toString());

		ChatManager* chatManager = server->getZoneServer()->getChatManager();
		chatManager->sendMail("System", "dumpTargetInformation", msg.toString(), player->getFirstName());

		return SUCCESS;
	}

};

#endif //DUMPTARGETINFORMATIONCOMMAND_H_
