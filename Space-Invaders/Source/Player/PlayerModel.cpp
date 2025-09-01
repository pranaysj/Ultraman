#include"../../Header/Player/PlayerModel.h"

namespace Player {

    int PlayerModel::player_lives;
    int PlayerModel::enemies_killed;

    PlayerModel::PlayerModel() {}

    PlayerModel::~PlayerModel() {}

    void PlayerModel::Initialize() {
        Reset();
    }

    void PlayerModel::Reset() {
        playerState = PlayerState::ALIVE;
        playerPositon = initialPlayerPosition;

        player_lives = max_player_lives;
        enemies_killed = 0;

        boolShield = false;
        boolRapidFire = false;
        boolTrippleLaser = false;
    }

    Vector2f PlayerModel::GetPlayerPosition() {
        return playerPositon;
    }

    void PlayerModel::SetPlayerPosition(Vector2f position) {
        playerPositon = position;
    }

    PlayerState PlayerModel::GetPlayerState() {
        return playerState;
    }

    void PlayerModel::SetPlayerState(PlayerState _state) {
        playerState = _state;
    }

    Entity::EntityType PlayerModel::GetEntityType()
    {
        return entityType;
    }

    bool PlayerModel::IsShieldEnabled()
    {
        return boolShield;
    }

    bool PlayerModel::IsRapidFireEnabled()
    {
        return boolRapidFire;
    }

    bool PlayerModel::IsTrippleLaserEnabled()
    {
        return boolTrippleLaser;
    }

    void PlayerModel::SetShieldState(bool _value)
    {
        boolShield = _value;
    }

    void PlayerModel::SetRapidFireState(bool _value)
    {
        boolRapidFire = _value;
    }

    void PlayerModel::SetTrippleFireState(bool _value)
    {
        boolTrippleLaser = _value;
    }
}

