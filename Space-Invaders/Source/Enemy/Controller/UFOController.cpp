#pragma
#include "../../Header/Enemy/Controller/UFOController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Global/ServiceLocator.h"
#include "../../../Header/Bullet/BulletController.h"



namespace Enemy {
	namespace Controller {

		using namespace Bullet;
		using namespace Entity;
		using namespace Global;

		UFOController::UFOController(EnemyType _type) : EnemyController(_type){}

		UFOController::~UFOController(){}

		void UFOController::Initialize()
		{
			EnemyController::Initialize();
		}

		void UFOController::OnCollision(ICollider* other_collider)
		{
			EnemyController::OnCollision(other_collider);

			BulletController* bulletController = dynamic_cast<BulletController*>(other_collider);

			if (bulletController && bulletController->GetOwnerEntityType() != EntityType::ENEMY)
			{
				ServiceLocator::GetInstance()->GetPowerupService()->SpawnPowerup(GetRandomPowerupType(), enemyModel->GetEnemyPositon());
				return;
			}
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

			currentPositon.x -= UFOHorizontalMovementSpeed * Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

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

			currentPositon.x += UFOHorizontalMovementSpeed * Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

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