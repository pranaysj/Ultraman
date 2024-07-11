#pragma
#include"../../Header/Powerups/PowerupService.h"

#include "../../Header/Powerups/PoweupController.h"
#include "../../Header/Powerups/PowerupConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Powerups/Controllers/OutscalBombController.h"
#include "../../Header/Powerups/Controllers/RapidFireController.h"
#include "../../Header/Powerups/Controllers/ShieldController.h"
#include "../../Header/Powerups/Controllers/TrippleLaserController.h"

namespace Powerup {

	using namespace Global;
	using namespace Controller;
	using namespace Collectible;

	PowerupService::PowerupService(){

	}

	PowerupService::~PowerupService(){
		Destroy();
	}

	void PowerupService::Initialize(){

	}

	void PowerupService::Update(){
		for (int i = 0; i < powerup_list.size(); i++) powerup_list[i]->Update(); //loop and update
	}

	void PowerupService::Render(){
		for (int i = 0; i < powerup_list.size(); i++) powerup_list[i]->Render(); //loop and render
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

	PowerupController* PowerupService::SpawnPowerup(PowerupType powerup_type, sf::Vector2f position){
		PowerupController* powerup_controller = CreatePowerup(powerup_type);

		powerup_controller->Initialize(position);
		powerup_list.push_back(powerup_controller);
		return powerup_controller;
	}

	void PowerupService::DestroyPowerup(PowerupController* powerup_controller){
		powerup_list.erase(std::remove(powerup_list.begin(), powerup_list.end(), powerup_controller), powerup_list.end());
		delete(powerup_controller);
	}

	void PowerupService::Destroy(){
		for (int i = 0; i < powerup_list.size(); i++) delete (powerup_list[i]);
	}
}