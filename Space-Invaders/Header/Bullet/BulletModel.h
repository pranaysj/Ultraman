#pragma once
#include <SFML/Graphics.hpp>
#include"../../Header/Entity/EntityConfig.h"

namespace Bullet
{
    enum class BulletType;
    enum class MovementDirection;

    class BulletModel
    {
    private:
        float movementSpeed = 300.f;
        sf::Vector2f bulletPosition;

        BulletType bulletType;
        MovementDirection movementDirection;
        Entity::EntityType ownerType;

    public:
        BulletModel(BulletType _type, Entity::EntityType _ownerType);
        ~BulletModel();

        void Initialize(sf::Vector2f _position, MovementDirection _direction);

        sf::Vector2f GetBulletPosition();
        void SetBulletPosition(sf::Vector2f _position);

        BulletType GetBulletType();
        Entity::EntityType GetOwnerEntityType();

        MovementDirection GetMovementDirection();
        void SetMovementDirection(MovementDirection _direction);


        float GetMovementSpeed();
        void SetMovementSpeed(float _speed);

        //void SetBulletType(BulletType _type);



    };
}