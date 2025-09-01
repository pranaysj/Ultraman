#include "../../Header/Player/PlayerController.h"
#include"../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Event/EventService.h"

namespace Player {
	using namespace Global;
	using namespace Event;

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


	Vector2f PlayerController::GetPlayerPosition() {

		return playerModel->GetPlayerPosition();
	}

}

