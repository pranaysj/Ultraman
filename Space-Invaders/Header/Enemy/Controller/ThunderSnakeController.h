#pragma once
#include"../../Header/Enemy/EnemyController.h"

namespace Enemy {
	namespace Controller {
		class ThunderSnakeController : public EnemyController {
		private:
			const float maximumDropSpeed = 10.0f;

			void Move() override;
			void MoveRight();
			void MoveLeft();

			void FireBullet() override;

		public:
			ThunderSnakeController(EnemyType _type);
			~ThunderSnakeController();

			void Initialize() override;
		};
	}
}