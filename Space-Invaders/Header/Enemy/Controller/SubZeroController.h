#pragma once
#include"../../Header/Enemy/EnemyController.h"

namespace Enemy {
	namespace Controller {
		class SubZeroController : public EnemyController {
        private:
            float verticalMovementSpeed = 100.f;
            const float subzero_fire_rate = 3.f;

            void Move() override;
            void MoveDown();

            void FireBullet() override;

        public:
            SubZeroController(EnemyType _type);
            ~SubZeroController();

            void Initialize() override;

		};
	}
}