#pragma once
#include "../../Header/Powerups/PoweupController.h"
#include "../../Header/Powerups/PowerupView.h"
#include "../../Header/Powerups/PowerupModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerController.h"

namespace Powerup
{
	using namespace Global;
	using namespace Player;

	PowerupController::PowerupController(PowerupType type)
	{
		powerupView = new PowerupView();
		powerupModel = new PowerupModel(type);
	}

	PowerupController::~PowerupController()
	{
		delete (powerupView);
		delete (powerupModel);
	}

	void PowerupController::Initialize(sf::Vector2f position)
	{
		powerupView->Initialize(this);
		powerupModel->Initialize(position);
	}

	void PowerupController::Update()
	{
		UpdatePowerupPosition();
		powerupView->Update();
	}

	void PowerupController::Render()
	{
		powerupView->Render();
	}

	void PowerupController::OnCollected()
	{
		ApplyPowerup();
	}

	void PowerupController::UpdatePowerupPosition()
	{
		sf::Vector2f currentPosition = powerupModel->GetPowerupPosition();
		currentPosition.y += powerupModel->GetMovementSpeed() * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		powerupModel->SetPowerupPosition(currentPosition);
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
		return powerupModel->GetPowerupPosition();
	}

	PowerupType PowerupController::GetPowerupType()
	{
		return powerupModel->GetPowerupType();
	}

	const sf::Sprite& PowerupController::GetColliderSprite()
	{
		return powerupView->GetPowerupSprite();;
	}

	void PowerupController::OnCollision(ICollider* other_collider)
	{
		PlayerController* player_controller = dynamic_cast<PlayerController*>(other_collider);

		if (player_controller)
		{
			OnCollected();
			ServiceLocator::GetInstance()->GetPowerupService()->DestroyPowerup(this);
		}
	}
}
