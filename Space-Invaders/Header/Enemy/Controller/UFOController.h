#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Powerups/PowerupConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class UFOController : public EnemyController
        {
        private:
             
            const float UFOHorizontalMovementSpeed = 100.f;

            void Move() override;
            void MoveLeft();
            void MoveRight();

            void FireBullet() override;
            void Destroy() override;

            Powerup::PowerupType GetRandomPowerupType();

        public:
            UFOController(EnemyType type);
            ~UFOController();

            void Initialize() override;
            void OnCollision(ICollider* other_collider) override;
        };
    }
}