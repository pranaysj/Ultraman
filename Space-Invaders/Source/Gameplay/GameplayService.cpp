#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Gameplay/GameplayController.h"
#include "../../Header/Global/ServiceLocator.h"

#pragma once
namespace Gameplay {
	using namespace Global;

	Gameplay::GameplayService::GameplayService(){
		gameplayController = new GameplayController();
	}

	GameplayService::~GameplayService(){
		delete(gameplayController);
	}

	void GameplayService::Initialize(){
		gameplayController->Initialize();
	}

	void GameplayService::Update(){
		gameplayController->Update();
	}

	void GameplayService::Render(){
		gameplayController->Render();
	}

	void GameplayService::Restart()
	{
		ServiceLocator::GetInstance()->GetPlayerService()->Reset();
		ServiceLocator::GetInstance()->GetEnemyService()->Reset();
		ServiceLocator::GetInstance()->GetBulletService()->Reset();
		ServiceLocator::GetInstance()->GetElementService()->Reset();
	}
}
