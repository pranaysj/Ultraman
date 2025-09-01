#pragma once
#include"../../Header/Enemy/EnemyService.h"
#include"../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controller/ZapperController.h"
#include "../../Header/Enemy/Controller/SubZeroController.h"
#include "../../Header/Enemy/Controller/ThunderSnakeController.h"
#include "../../Header/Enemy/Controller/UFOController.h"

namespace Enemy {
	using namespace Time;
	using namespace Global;
	using namespace Controller;

	EnemyService::EnemyService() {
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService() {
		Destory();
	}

	void EnemyService::Destory(){
		for (int i = 0; i < enemyList.size(); i++)
		{
			delete(enemyList[i]);
		}
	}

	void EnemyService::Initialize() {
		spwanTimer = spawnInterval;
	}

	void EnemyService::Update(){

		UpdateSpawnTimer();
		ProcessEnemySpawn();

		for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->Update();
		}
	}

	void EnemyService::UpdateSpawnTimer() {
		spwanTimer += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}

	void EnemyService::ProcessEnemySpawn() {
		if (spwanTimer >= spawnInterval) {
			SpawnEnemy();
			spwanTimer = 0;
		}
	}

	EnemyController* EnemyService::SpawnEnemy(){
		EnemyController* enemyController = CreateEnemy(GetRandomEnemyType());

		enemyController->Initialize();
		enemyList.push_back(enemyController);

		return enemyController;
	}

	void EnemyService::Render(){

		for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->Render();
		}
	}

	void EnemyService::DestroyEnemy(EnemyController* _enemyController){
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), _enemyController), enemyList.end());
		delete(_enemyController);
	}

	EnemyType EnemyService::GetRandomEnemyType()
	{
		int randomType = std::rand() % 4;
		return static_cast<EnemyType>(randomType);
	}

	EnemyController* EnemyService::CreateEnemy(EnemyType _enemyType)
	{
		switch (_enemyType)
		{
		case EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER);

		case EnemyType::THUNDER_SNAKE:
			return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);

		case EnemyType::SUBZERO:
			return new SubZeroController(Enemy::EnemyType::SUBZERO);

		case::Enemy::EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO);
		}
	}
}