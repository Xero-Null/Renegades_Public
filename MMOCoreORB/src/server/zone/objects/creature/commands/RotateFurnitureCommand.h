/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef ROTATEFURNITURECOMMAND_H_
#define ROTATEFURNITURECOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/tangible/components/EventPerkDataComponent.h"
#include "server/zone/objects/player/PlayerObject.h"

class RotateFurnitureCommand : public QueueCommand {
public:

	RotateFurnitureCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

		if (ghost == nullptr)
			return GENERALERROR;

		String dir;
		float degrees = 0.f;

		try {
			UnicodeTokenizer tokenizer(arguments.toString());
			tokenizer.getStringToken(dir);
			degrees = tokenizer.getFloatToken();

			dir = dir.toLowerCase();

			if (dir != "left" && dir != "right" && dir != "yaw" && dir != "roll" && dir != "pitch" && dir !="reset")
				throw Exception();

		} catch (Exception& e) {
			StringBuffer msg;
			msg << "incorrect format!" << endl << "@player_structure:formet_rotratefurniture_degrees" << " accepts >0 to 180" << endl
			<< "/rotateFurniture yaw pitch roll <degrees> accepts -360 to 360" << endl
			<< "/rotateFurnature reset 0, will reset rotation"
			<< "All arguments accept floating points! get that placement just right :D";
			creature->sendSystemMessage(msg.toString());
		return INVALIDPARAMETERS;
		}

		if ((dir == "left" || dir == "right") && (degrees < 0.f || degrees > 180.f)) {
			creature->sendSystemMessage("@player_structure:formet_rotratefurniture_degrees"); //Format: /rotateFurniture <LEFT/RIGHT> <degrees>
			return INVALIDPARAMETERS;
		}

		if((dir == "roll" || dir == "pitch" || dir == "yaw") && (degrees < -360.f || degrees > 360.f)) {
 			creature->sendSystemMessage("Format: /rotateFurniture <ROLL/PITCH/YAW> <-360 to 360 allowed>");
 			return INVALIDPARAMETERS;
 		}

		ZoneServer* zoneServer = creature->getZoneServer();
		ManagedReference<SceneObject*> obj = zoneServer->getObject(target);

		if (obj == nullptr || !obj->isTangibleObject() || obj->isPlayerCreature() || obj->isPet()) {
			creature->sendSystemMessage("@player_structure:rotate_what"); //What do you want to rotate?
			return GENERALERROR;
		}

		ManagedReference<SceneObject*> rootParent = creature->getRootParent();
		
		BuildingObject* buildingObject = rootParent != nullptr ? (rootParent->isBuildingObject() ? cast<BuildingObject*>( rootParent.get()) : nullptr) : nullptr;
		EventPerkDataComponent* data = cast<EventPerkDataComponent*>(obj->getDataObjectComponent()->get());

		if (data != nullptr) {
			EventPerkDeed* deed = data->getDeed();

			if (deed == nullptr) {
				return GENERALERROR;
			}

			ManagedReference<CreatureObject*> owner = deed->getOwner().get();

			if (owner != creature) {
				return GENERALERROR;
			}
		
		} else if (buildingObject == nullptr) {
				creature->sendSystemMessage("@player_structure:must_be_in_building"); //You must be in a building to do that.
				return GENERALERROR;
				
				} else {
			if (obj->isVendor() && !obj->checkContainerPermission(creature, ContainerPermissions::MOVEVENDOR)) {
				return GENERALERROR;
				}

				if (!obj->isVendor() && !buildingObject->isOnAdminList(creature)) {
					creature->sendSystemMessage("@player_structure:must_be_admin"); //You must be a building admin to do that.
					return GENERALERROR;
				}
				
				if (obj->getRootParent() != buildingObject || buildingObject->containsChildObject(obj)) {
					if(!ghost->isPrivileged() && obj->getRootParent() == buildingObject){
					creature->sendSystemMessage("@player_structure:rotate_what"); //What do you want to rotate?
					return GENERALERROR;
					}
				}

				if (buildingObject->isGCWBase()) {
					creature->sendSystemMessage("@player_structure:no_move_hq"); // You may not move or rotate objects inside a factional headquarters.
					return GENERALERROR;
				}
			}

 		if (dir == "right")
 			obj->rotate(-degrees);
 		else if(dir == "pitch")
 			obj->rotateY(degrees);
 		else if(dir == "roll")
 			obj->rotateX(degrees);
 		else if(dir == "reset")
 			obj->setDirection(1, 0, 0, 0);
 		else
 			obj->rotate(degrees);

		obj->incrementMovementCounter();

		ManagedReference<SceneObject*> objParent = obj->getParent().get();
		if (objParent != nullptr)
			obj->teleport(obj->getPositionX(), obj->getPositionZ(), obj->getPositionY(), objParent->getObjectID());
		else
			obj->teleport(obj->getPositionX(), obj->getPositionZ(), obj->getPositionY());

		return SUCCESS;
	}

};

#endif //ROTATEFURNITURECOMMAND_H_
