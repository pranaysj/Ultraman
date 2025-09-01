#pragma
#include "../../Header/Bullet/Controllers/FrostBulletController.h"
#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
    namespace Controller
    {
        FrostBulletController::FrostBulletController(BulletType _type, Entity::EntityType owner_type) : BulletController(_type, owner_type) {}

        FrostBulletController::~FrostBulletController() {}

        void FrostBulletController::Initialize(sf::Vector2f _position, MovementDirection _direction) {
            BulletController::Initialize(_position, _direction);
            bulletModel->SetMovementSpeed(frostMovementSpeed);
        }

    }
}
