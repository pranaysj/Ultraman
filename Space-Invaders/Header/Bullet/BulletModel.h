#pragma once
#include <SFML/Graphics.hpp>

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

    public:
        BulletModel(BulletType _type);
        ~BulletModel();

        void Initialize(sf::Vector2f _position, MovementDirection _direction);

        float GetMovementSpeed();
        void SetMovementSpeed(float _speed);

        sf::Vector2f GetBulletPosition();
        void SetBulletPosition(sf::Vector2f _position);

        BulletType GetBulletType();
        void SetBulletType(BulletType _type);

        MovementDirection GetMovementDirection();
        void SetMovementDirection(MovementDirection _direction);

    };
}