#include "../../Header/Player/PlayerController.h"
#include"../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Player {
	using namespace Global;
	using namespace Event;
	using namespace Bullet;

	PlayerController::PlayerController() {
		playerModel = new PlayerModel();
		playerView = new PlayerView();
	}

	PlayerController::~PlayerController() {
		delete(playerModel);
		delete(playerView);
	}

	void PlayerController::Initialize() {
		playerModel->Initialize();
		playerView->Initialize(this); //this
	}

	void PlayerController::Update() {
		ProcessPlayerInput();
		playerView->Update();
	}

	void PlayerController::Render() {
		playerView->Render();
	}

	void PlayerController::ProcessPlayerInput() {
		EventService* eventService = ServiceLocator::GetInstance()->GetEventService();

		if (eventService->PressedLeftKey() || eventService->PressedAKey()) {
			MoveLeft();
		}
		if (eventService->PressedRightKey() || eventService->PressedDKey()) {
			MoveRight();
		}

		if (eventService->PressedLeftMouseButton()) {
			FireBullet();
		}
	}

	void PlayerController::MoveLeft() {
		Vector2f currentPosition = playerModel->GetPlayerPosition();
		currentPosition.x -= playerModel->maximumSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		currentPosition.x = max(currentPosition.x, playerModel->leftMostPosition.x);
		playerModel->SetPlayerPosition(currentPosition);
	}

	void PlayerController::MoveRight() {
		Vector2f currentPosition = playerModel->GetPlayerPosition();
		currentPosition.x += playerModel->maximumSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		currentPosition.x = min(currentPosition.x, playerModel->rightMostPosition.x);
		playerModel->SetPlayerPosition(currentPosition);
	}

	void PlayerController::FireBullet(){
		ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(BulletType::LASER_BULLET,
			playerModel->GetPlayerPosition() + playerModel->barrel_position_offset,
			Bullet::MovementDirection::UP);
	}


	Vector2f PlayerController::GetPlayerPosition() {

		return playerModel->GetPlayerPosition();
	}

}

