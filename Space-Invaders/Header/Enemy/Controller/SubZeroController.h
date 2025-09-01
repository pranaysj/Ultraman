#pragma once
#include"../../Header/Enemy/EnemyController.h"

namespace Enemy {
	namespace Controller {
		class SubZeroController : public EnemyController {
        private:

            float subZeroVerticalMovementSpeed = 100.f;
            const float subzeroFireRate = 3.f;

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