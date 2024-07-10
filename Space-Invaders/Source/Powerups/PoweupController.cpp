#pragma once
#include "../../Header/Powerups/PoweupController.h"
#include "../../Header/Powerups/PowerupView.h"
#include "../../Header/Powerups/PowerupModel.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	PowerupController::PowerupController(PowerupType type)
	{
		powerup_view = new PowerupView();
		powerup_model = new PowerupModel(type);
	}

	PowerupController::~PowerupController()
	{
		delete (powerup_view);
		delete (powerup_model);
	}

	void PowerupController::Initialize(sf::Vector2f position)
	{
		powerup_model->initialize(position);
		powerup_view->initialize(this);
	}

	void PowerupController::Update()
	{
		UpdatePowerupPosition();
		powerup_view->update();
	}

	void PowerupController::Render()
	{
		powerup_view->render();
	}

	void PowerupController::OnCollected()
	{
	}

	void PowerupController::UpdatePowerupPosition()
	{
		sf::Vector2f currentPosition = powerup_model->GetPowerupPosition();
		currentPosition.y += powerup_model->GetMovementSpeed() * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		powerup_model->SetPowerupPosition(currentPosition);
	}

	void PowerupController::HandleOutOfBounds()
	{
		sf::Vector2f powerupPosition = GetCollectiblePosition();
		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow()->getSize();

		if (powerupPosition.x < 0 || powerupPosition.x > windowSize.x ||
			powerupPosition.y < 0 || powerupPosition.y > windowSize.y)
		{
			ServiceLocator::GetInstance()->GetPowerupService()->DestroyPowerup(this);
		}
	}

	sf::Vector2f PowerupController::GetCollectiblePosition()
	{
		return powerup_model->GetPowerupPosition();
	}

	PowerupType PowerupController::GetPowerupType()
	{
		return powerup_model->GetPowerupType();
	}
}
