#pragma
#include "../../Header/Enemy/Controller/UFOController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Global/ServiceLocator.h"



namespace Enemy {
	namespace Controller {
		UFOController::UFOController(EnemyType _type) : EnemyController(_type){}

		UFOController::~UFOController(){}

		void UFOController::Initialize()
		{
			EnemyController::Initialize();
		}

		Powerup::PowerupType UFOController::GetRandomPowerupType()
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			//We add '1'  to OutscalBomb below because enum has a 0 index, making the bomb number 3, we need to add 1 to make it 4 

			int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
			return static_cast<Powerup::PowerupType>(random_value);
		}

		void UFOController::Move()
		{
			switch (enemyModel->GetMovementDirection())
			{
			case MovementDirection::RIGHT:
				MoveRight();
				break;
			case MovementDirection::LEFT:
				MoveLeft();
				break;
			}
		}

		void UFOController::MoveLeft()
		{
			sf::Vector2f currentPositon = enemyModel->GetEnemyPositon();

			currentPositon.x -= enemyModel->maximumSpeed * Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPositon.x <= enemyModel->leftMostPosition.x) 
			{
				enemyModel->SetMovementDirection(MovementDirection::RIGHT);
			}
			else
			{
				enemyModel->SetEnemyPositon(currentPositon);
			}
		}

		void UFOController::MoveRight()
		{
			sf::Vector2f currentPositon = enemyModel->GetEnemyPositon();

			currentPositon.x += enemyModel->maximumSpeed * Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPositon.x >= enemyModel->rightMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::LEFT);
			}
			else
			{
				enemyModel->SetEnemyPositon(currentPositon);
			}
		}

		void UFOController::FireBullet()
		{
			//make it empty
		}

	}
}