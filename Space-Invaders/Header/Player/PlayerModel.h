#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/Entity/EntityConfig.h"

namespace Player {
    using namespace sf;

    enum class PlayerState {
        ALIVE,
        FROZEN,
        DEAD
    };

    class PlayerModel {
    private:

        Vector2f initialPlayerPosition = Vector2f(950.0f, 930.0f);
        
        Vector2f playerPositon;
        PlayerState playerState;
        Entity::EntityType entityType;
        int playerScore;

        bool boolShield;
        bool boolRapidFire;
        bool boolTrippleLaser;

    public:

        const Vector2f leftMostPosition = Vector2f(0.0f, 950.0f);
        const Vector2f rightMostPosition = Vector2f(1850.0f, 950.0f);
        const Vector2f barrelpositionOffset = Vector2f(-5.f, -2.f);
        const Vector2f secondWeaponPositionOffset = sf::Vector2f(45.f, 0.f);
        const Vector2f thirdWeaponPositionOffset = sf::Vector2f(-45.f, 0.f);
        
        const float shiledPowerUpDuration = 10.f;
        const float rapidFirePowerUpDuration = 10.f;
        const float trippleLaserPowerUpDuration = 10.f;

        const float freezeDuration = 2.f;

        const float fireCooldownDuration = 0.2f;
        const float rapidFireCooldownDuration = 0.05f;
        const float trippleLaserPositionOffset = 30.f;

        float elapsedShieldDuration;
        float elapsedRapidFireDuration;
        float elapsedTrippleLaserDuration;

        float elapsedFireDuration;
        float elapsedFreezeDuration;

        const float playerMaximumSpeed = 350.0f;

        PlayerModel();
        ~PlayerModel();

        void Initialize();
        void Reset();

        Vector2f GetPlayerPosition();
        void SetPlayerPosition(Vector2f _position);

        int GetPlayerScore();
        void SetPlayerScore(int _score);

        PlayerState GetPlayerState();
        void SetPlayerState(PlayerState _state);

        Entity::EntityType GetEntityType();

        bool IsShieldEnabled();
        bool IsRapidFireEnabled();
        bool IsTrippleLaserEnabled();

        void SetShieldState(bool _value);
        void SetRapidFireState(bool _value);
        void SetTrippleFireState(bool _value);
    };
}

