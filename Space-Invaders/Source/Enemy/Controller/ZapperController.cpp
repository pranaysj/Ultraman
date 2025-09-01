#pragma
#include"../../Header/Enemy/Controller/ZapperController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy {
	using namespace Global;
	namespace Controller {
		ZapperController::ZapperController(EnemyType _type) : EnemyController(_type) {}

		ZapperController::~ZapperController() {}

		void ZapperController::Initialize() {
			EnemyController::Initialize();
		}

		void ZapperController::Move(){
			switch (enemyModel->GetMovementDirection())
			{
			case::Enemy::MovementDirection::LEFT:
				MoveLeft();
				break;
			case::Enemy::MovementDirection::RIGHT:
				MoveRight();
				break;
			case::Enemy::MovementDirection::DOWN:
				MoveDown();
				break;
			}
		}

		void ZapperController::MoveLeft(){
			sf::Vector2f currentPosition = enemyModel->GetEnemyPositon();

			currentPosition.x -= enemyModel->maximumSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPosition.x <= enemyModel->leftMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::DOWN);
				enemyModel->SetRefPositon(currentPosition);
			}
			else
			{
				enemyModel->SetEnemyPositon(currentPosition);
			}
		}

		void ZapperController::MoveRight(){
			sf::Vector2f currentPositoin = enemyModel->GetEnemyPositon();

			currentPositoin.x += enemyModel->maximumSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPositoin.x >= enemyModel->rightMostPosition.x) {
				enemyModel->SetMovementDirection(MovementDirection::DOWN);
				enemyModel->SetRefPositon(currentPositoin);
			}
			else
			{
				enemyModel->SetEnemyPositon(currentPositoin);
			}
		}

		void ZapperController::MoveDown(){
			sf::Vector2f currentPosition = enemyModel->GetEnemyPositon();

			currentPosition.y += enemyModel->maximumSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPosition.y >= enemyModel->GetRefPositon().y + verticalTravelDistance)
			{
				if (enemyModel->GetRefPositon().x <= enemyModel->leftMostPosition.x)
				{
					enemyModel->SetMovementDirection(MovementDirection::RIGHT);
				}
				else
				{
					enemyModel->SetMovementDirection(MovementDirection::LEFT);
				}
			}
			else
			{
				enemyModel->SetEnemyPositon(currentPosition);
			}
		}
	}
}


