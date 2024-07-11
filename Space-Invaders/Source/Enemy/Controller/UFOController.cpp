#pragma
#include "../../Header/Enemy/Controller/UFOController.h"

namespace Enemy {
	namespace Controller {
		void Enemy::Controller::UFOController::Move()
		{
		}

		void Enemy::Controller::UFOController::MoveLeft()
		{
		}

		void Enemy::Controller::UFOController::MoveRight()
		{
		}

		void Enemy::Controller::UFOController::FireBullet()
		{
		}

		Powerup::PowerupType Enemy::Controller::UFOController::GetRandomPowerupType()
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			//We add '1'  to OutscalBomb below because enum has a 0 index, making the bomb number 3, we need to add 1 to make it 4 

			int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
			return static_cast<Powerup::PowerupType>(random_value);
		}

		Enemy::Controller::UFOController::UFOController(EnemyType type)
		{
		}

		Enemy::Controller::UFOController::~UFOController()
		{
		}

		void Enemy::Controller::UFOController::Initialize()
		{
		}

	}
}