#pragma once
#include"../../Header/Enemy/EnemyService.h"
#include"../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controller/ZapperController.h"
#include "../../Header/Enemy/Controller/SubZeroController.h"

namespace Enemy {
	using namespace Time;
	using namespace Global;
	using namespace Controller;

	void EnemyService::UpdateSpawnTimer(){
		spwanTimer += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}

	void EnemyService::ProcessEnemySpawn(){
		if (spwanTimer >= spawnInterval) {
			SpawnEnemy();
			spwanTimer = 0;
		}
	}

	EnemyType EnemyService::GetRandomEnemyType()
	{
		int randomType = std::rand() % 2;
		return static_cast<EnemyType>(randomType);
	}

	EnemyController* EnemyService::CreateEnemy(EnemyType _enemyType)
	{
		switch (_enemyType)
		{
		case EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER);

			/*case::Enemy::EnemyType::THUNDER_SNAKE:
				return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);*/

		case EnemyType::SUBZERO:
			return new SubZeroController(Enemy::EnemyType::SUBZERO);

			/*case::Enemy::EnemyType::UFO:
				return new UFOController(Enemy::EnemyType::UFO);*/
		}
	}

	void EnemyService::Destory(){
		for (int i = 0; i < enemyList.size(); i++)
		{
			delete(enemyList[i]);
		}
	}

	EnemyService::EnemyService(){
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService(){
		Destory();
	}

	void EnemyService::Initialize(){
		spwanTimer = spawnInterval;
	}

	void EnemyService::Update(){
		/*Detect the GameState then Update*/

		UpdateSpawnTimer();
		ProcessEnemySpawn();

		for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->Update();
		}
	}

	void EnemyService::Render(){
		/*Detect the GameState then Render*/
		for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->Render();
		}
	}

	EnemyController* EnemyService::SpawnEnemy(){
		EnemyController* enemyController = CreateEnemy(GetRandomEnemyType());

		enemyController->Initialize();
		enemyList.push_back(enemyController);

		return enemyController;
	}

	void EnemyService::DestroyEnemy(EnemyController* _enemyController){
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), _enemyController), enemyList.end());
		delete(_enemyController);
	}
}