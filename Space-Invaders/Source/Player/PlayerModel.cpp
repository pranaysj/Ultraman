#include"../../Header/Player/PlayerModel.h"

namespace Player {
    PlayerModel::PlayerModel() {}

    PlayerModel::~PlayerModel() {}

    void PlayerModel::Initialize() {
        Reset();
    }

    void PlayerModel::Reset() {
        playerState = PlayerState::ALIVE;
        playerPositon = initialPlayerPosition;
        playerScore = 0;

    }

    Vector2f PlayerModel::GetPlayerPosition()
    {
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

    int PlayerModel::GetPlayerScore()
    {
        return playerScore;
    }

    void PlayerModel::SetPlayerScore(int _score)
    {
        playerScore = _score;
    }
}

