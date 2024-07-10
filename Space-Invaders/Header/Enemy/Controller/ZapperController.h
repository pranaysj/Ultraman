#pragma once
#include"../../Header/Enemy/EnemyController.h"

namespace Enemy{
	namespace Controller {
		class ZapperController : public EnemyController {
        private:
            float verticalTravelDistance = 100.f;
            const float zapper_fire_rate = 3.f;

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