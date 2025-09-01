#pragma once
#include"../../Header/Enemy/Controller/SubZeroController.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy {
	using namespace Global;
	namespace Controller {
		SubZeroController::SubZeroController(EnemyType _type) : EnemyController(_type) {}

		SubZeroController::~SubZeroController() {}

		void SubZeroController::Initialize(){
			EnemyController::Initialize();
			enemyModel->SetMovementDirection(MovementDirection::DOWN);
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
			currentPosition.y += verticalMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			enemyModel->SetEnemyPositon(currentPosition);
		}

	}
}