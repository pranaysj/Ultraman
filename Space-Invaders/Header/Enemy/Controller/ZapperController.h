#pragma once
#include"../../Header/Enemy/EnemyController.h"

namespace Enemy{
	namespace Controller {
		class ZapperController : public EnemyController {
        private:
            const float zapperHoritonalMovementSpeed = 250.f;
            const float zapperVerticalTravelDistance = 100.f;
            const float zapperFireRate = 3.f;

            void Move() override;
            void MoveLeft();
            void MoveRight();
            void MoveDown();

            void FireBullet() override;

        public:
            ZapperController(EnemyType _type);
            ~ZapperController();

            void Initialize() override;
		};
	}
}