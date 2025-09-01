#pragma once
#include <SFML/Graphics.hpp>

namespace Powerup
{
    enum class PowerupType;

    class PowerupModel
    {
    private:
        float movement_speed = 300.f;

        sf::Vector2f powerup_position;
        PowerupType powerup_type;

    public:
        PowerupModel(PowerupType type);
        ~PowerupModel();

        void initialize(sf::Vector2f position);

        sf::Vector2f GetPowerupPosition();
        void SetPowerupPosition(sf::Vector2f position);

        PowerupType GetPowerupType();
        void SetPowerupType(PowerupType type);

        float GetMovementSpeed();
        void SetMovementSpeed(float speed);
    };
}