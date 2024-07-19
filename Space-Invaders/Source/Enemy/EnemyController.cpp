#pragma once
#include"../../Header/Enemy/EnemyController.h"
#include"../../Header/Enemy/EnemyModel.h"
#include"../../Header/Enemy/EnemyView.h"
#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Bullet/BulletConfig.h"
#include <iostream>

namespace Enemy {

	using namespace Global;
	using namespace Bullet;
	
	EnemyController::EnemyController(EnemyType _type){
		enemyModel = new EnemyModel(_type);
		enemyView = new EnemyView();
	}

	EnemyController::~EnemyController(){
		delete(enemyModel);
		delete(enemyView);
	}

	void EnemyController::Initialize(){
		enemyModel->Initialize();
		enemyModel->SetEnemyPositon(GetRandomInitialPosition());
		enemyView->Initialize(this);
	}

	sf::Vector2f EnemyController::GetRandomInitialPosition()
	{
		float x_offset_distance = (std::rand() % static_cast<int>(enemyModel->rightMostPosition.x - enemyModel->leftMostPosition.x));

		float x_position = enemyModel->leftMostPosition.x + x_offset_distance;

		float y_position = enemyModel->leftMostPosition.y;

		return sf::Vector2f(x_position, y_position);
	}

	void EnemyController::Update(){
		Move();
		UpdateFireTimer();
		ProcessBulletFire();
		enemyView->Update();
		HandleOutOfBounds();
	}

	void EnemyController::Render(){
		enemyView->Render();
	}
	
	void EnemyController::UpdateFireTimer(){
		elapsedFireDuration += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}

	void EnemyController::ProcessBulletFire(){
		if (elapsedFireDuration >= rateOfFire)
		{
			FireBullet();
			elapsedFireDuration = 0.f; //set elapsed duration back to 0.
		}
	}

	void EnemyController::HandleOutOfBounds(){
		sf::Vector2f enemyPosition = GetEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow()->getSize();

		// Destroy the enemy if it goes out of bounds.
		if (enemyPosition.x < 0 || enemyPosition.x > windowSize.x ||
			enemyPosition.y < 0 || enemyPosition.y > windowSize.y)
		{
			ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this);
		}
	}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPositon();
	}

	EnemyState EnemyController::GetEnemyState()
	{
		return enemyModel->GetEnemyState();
	}

	EnemyType EnemyController::GetEnemyType()
	{
		return enemyModel->GetEnemyType();
	}
}