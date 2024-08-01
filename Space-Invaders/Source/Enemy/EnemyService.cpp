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
#include "../../Header/Collision/ICollider.h"

namespace Enemy {
	using namespace Time;
	using namespace Global;
	using namespace Controller;
	using namespace Collision;

	EnemyService::EnemyService() {
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService() {
		Destory();
	}

	void EnemyService::Initialize() {
		spwanTimer = spawnInterval;
	}

	void EnemyService::Update() {

		UpdateSpawnTimer();
		ProcessEnemySpawn();

		for (EnemyController* enemy : enemyList)
			enemy->Update();

		DestroyFlaggedEnemies();
	}

	void EnemyService::Render() {

		for (EnemyController* enemy : enemyList)
			enemy->Render();
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

		ServiceLocator::GetInstance()->GetCollisionService()->AddCollider(dynamic_cast<ICollider*>(enemyController));

		enemyList.push_back(enemyController);

		return enemyController;
	}


	EnemyType EnemyService::GetRandomEnemyType()
	{
		int randomType = std::rand() % 4;
		//int randomType = std::rand() % (static_cast<int>(Enemy::EnemyType::UFO) + 1);
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


	void EnemyService::DestroyFlaggedEnemies()
	{
		for (int i = 0; i < flaggedEnemyList.size(); i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()->RemoveCollider(dynamic_cast<ICollider*>(flaggedEnemyList[i]));
			delete (flaggedEnemyList[i]);
		}
		flaggedEnemyList.clear();
	}

	void EnemyService::DestroyEnemy(EnemyController* _enemyController) {

		dynamic_cast<ICollider*>(_enemyController)->DisableCollision();
		flaggedEnemyList.push_back(_enemyController);

		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), _enemyController), enemyList.end());
		//delete(_enemyController);
	}

	void EnemyService::Destory() {
		for (int i = 0; i < enemyList.size(); i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()->RemoveCollider(dynamic_cast<ICollider*>(enemyList[i]));
			delete(enemyList[i]);
		}
		enemyList.clear();
	}


	void EnemyService::Reset()
	{
		Destory();
		spwanTimer = 0.0f;
	}
}