#pragma once
#include"../../Header/Enemy/Controller/SubZeroController.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletConfig.h"
#include <iostream>

namespace Enemy {
	using namespace Global;
	using namespace Bullet;
	
	namespace Controller {
		SubZeroController::SubZeroController(EnemyType _type) : EnemyController(_type) {}

		SubZeroController::~SubZeroController() {}

		void SubZeroController::Initialize(){
			EnemyController::Initialize();
			enemyModel->SetMovementDirection(MovementDirection::DOWN);
			//rateOfFire = subzeroFireRate;

		}

		void SubZeroController::Move(){ 
			switch (enemyModel->GetMovementDirection())
			{
			case::Enemy::MovementDirection::DOWN:
				MoveDown();
				break;
			}
		}

		void SubZeroController::MoveDown(){
			sf::Vector2f currentPosition = enemyModel->GetEnemyPositon();
			currentPosition.y += subZeroVerticalMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			enemyModel->SetEnemyPositon(currentPosition);
		}

		void SubZeroController::FireBullet(){
			ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(BulletType::FROST_BULLET,
				enemyModel->GetEnemyPositon() + enemyModel->barrel_position_offset,
				Bullet::MovementDirection::DOWN);
		}

	}
}