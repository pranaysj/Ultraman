#pragma
#include "../../Header/Enemy/Controller/ThunderSnakeController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Enemy {
	namespace Controller {
		ThunderSnakeController::ThunderSnakeController(EnemyType _type) : EnemyController(_type){}

		ThunderSnakeController::~ThunderSnakeController(){}

		void ThunderSnakeController::Initialize()
		{
			EnemyController::Initialize();
			enemyModel->horizontalMovementSpeed = thunderSnakeHorizontalMovementSpeed;
			enemyModel->verticalMovementSpeed = thunderSnakeVerticalMovementSpeed;
		}

		void ThunderSnakeController::Move()
		{
			switch (enemyModel->GetMovementDirection())
			{
			case::Enemy::MovementDirection::LEFT:
				MoveLeft();
				break;
			case::Enemy::MovementDirection::RIGHT:
				MoveRight();
				break;
			}
		}

		void ThunderSnakeController::MoveRight()
		{
			sf::Vector2f currentPositoin = enemyModel->GetEnemyPositon();

			currentPositoin.x += enemyModel->horizontalMovementSpeed * Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			currentPositoin.y += enemyModel->verticalMovementSpeed * Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPositoin.x >= enemyModel->rightMostPosition.x) {
				enemyModel->SetMovementDirection(MovementDirection::LEFT);
			}
			else
			{
				enemyModel->SetEnemyPositon(currentPositoin);
			}
		}

		void ThunderSnakeController::MoveLeft()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPositon();

			currentPosition.x -= enemyModel->horizontalMovementSpeed * Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			currentPosition.y += enemyModel->verticalMovementSpeed * Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();


			if (currentPosition.x <= enemyModel->leftMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::RIGHT);
			}
			else
			{
				enemyModel->SetEnemyPositon(currentPosition);
			}
		}

		void ThunderSnakeController::FireBullet()
		{
			Global::ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(Bullet::BulletType::TORPEDO,
			enemyModel->GetEnemyPositon() + enemyModel->barrel_position_offset,
			Bullet::MovementDirection::DOWN);
		}
	}
}