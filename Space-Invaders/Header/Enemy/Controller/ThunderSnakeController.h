#pragma once
#include"../../Header/Enemy/EnemyController.h"

namespace Enemy {
	namespace Controller {
		class ThunderSnakeController : public EnemyController {
		private:
			const float thunderSnakeHorizontalMovementSpeed = 250.0f;
			const float thunderSnakeVerticalMovementSpeed = 60.0f;

			void Move() override;
			void MoveRight();
			void MoveLeft();

			void FireBullet() override;
			void Destroy() override;

		public:
			ThunderSnakeController(EnemyType _type);
			~ThunderSnakeController();

			void Initialize() override;
		};
	}
}