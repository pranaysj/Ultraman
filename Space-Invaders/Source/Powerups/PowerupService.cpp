#pragma
#include"../../Header/Powerups/PowerupService.h"
#include "../../Header/Powerups/PoweupController.h"
#include "../../Header/Powerups/PowerupConfig.h"
#include "../../Header/Collision/ICollider.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Powerups/Controllers/OutscalBombController.h"
#include "../../Header/Powerups/Controllers/RapidFireController.h"
#include "../../Header/Powerups/Controllers/ShieldController.h"
#include "../../Header/Powerups/Controllers/TrippleLaserController.h"

namespace Powerup {

	using namespace Global;
	using namespace Controller;
	using namespace Collectible;
	using namespace Collision;

	PowerupService::PowerupService() {}

	PowerupService::~PowerupService(){
		Destroy();
	}

	void PowerupService::Initialize() {}

	void PowerupService::Update(){
		for (int i = 0; i < powerupList.size(); i++) powerupList[i]->Update(); //loop and update
		DestroyFlaggedPowerup();
	}

	void PowerupService::Render(){
		for (int i = 0; i < powerupList.size(); i++) powerupList[i]->Render(); //loop and render
	}

	PowerupController* PowerupService::CreatePowerup(PowerupType powerup_type){
		switch (powerup_type)
		{
		case::Powerup::PowerupType::SHIELD:
			return new ShieldController(Powerup::PowerupType::SHIELD);

		case::Powerup::PowerupType::RAPID_FIRE:
			return new RapidFireController(Powerup::PowerupType::RAPID_FIRE);

		case::Powerup::PowerupType::TRIPPLE_LASER:
			return new TrippleLaserController(Powerup::PowerupType::TRIPPLE_LASER);

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return new OutscalBombController(Powerup::PowerupType::OUTSCAL_BOMB);
		}
	}

	void PowerupService::DestroyFlaggedPowerup()
	{
		for (Collectible::ICollectible* powerup : flaggedPowerupList)
			delete (powerup);

		flaggedPowerupList.clear();
	}

	PowerupController* PowerupService::SpawnPowerup(PowerupType powerup_type, sf::Vector2f position){
		
		PowerupController* powerup_controller = CreatePowerup(powerup_type);

		powerup_controller->Initialize(position);

		ServiceLocator::GetInstance()->GetCollisionService()->AddCollider(dynamic_cast<ICollider*>(powerup_controller));

		powerupList.push_back(powerup_controller);
		return powerup_controller;
	}

	void PowerupService::DestroyPowerup(PowerupController* powerup_controller){
		ServiceLocator::GetInstance()->GetCollisionService()->RemoveCollider(dynamic_cast<ICollider*>(powerup_controller));

		flaggedPowerupList.push_back(powerup_controller);
		
		powerupList.erase(std::remove(powerupList.begin(), powerupList.end(), powerup_controller), powerupList.end());
		//delete(powerup_controller);
	}

	void PowerupService::Destroy(){
		for (int i = 0; i < powerupList.size(); i++)
			delete (powerupList[i]);
	}
}