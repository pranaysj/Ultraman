#include "../../Header/Gameplay/GameplayController.h"
#include "../../Header/Gameplay/GameplayView.h"
#pragma once
namespace Gameplay {
	Gameplay::GameplayController::GameplayController(){
		gameplayView = new GameplayView();
	}

	GameplayController::~GameplayController(){
		delete(gameplayView);
	}

	void GameplayController::Initialize(){
		gameplayView->Initialize();
	}

	void GameplayController::Update(){
		gameplayView->Update();
	}

	void GameplayController::Render(){
		gameplayView->Render();
	}
}
