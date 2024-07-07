#pragma once
#include"../../Header/Enemy/EnemyController.h"

namespace Enemy{
	namespace Controller {
		class ZapperController : public EnemyController {
        private:
            float vertical_travel_distance = 100.f;

            void Move() override;
            void moveLeft();
            void moveRight();
            void moveDown();

        public:
            ZapperController();
            ~ZapperController();

            void Initialize() override;
		};
	}
}