#pragma once
#include<SFML/Graphics.hpp>

namespace Player {
    using namespace sf;

    enum class PlayerState {
        ALIVE,
        DEAD
    };

    class PlayerModel {
    private:
        Vector2f initialPlayerPosition = Vector2f(950.0f, 930.0f);
        Vector2f playerPositon;
        PlayerState playerState;
        int playerScore;

    public:

        const Vector2f leftMostPosition = Vector2f(50.0f, 950.0f);
        const Vector2f rightMostPosition = Vector2f(1800.0f, 950.0f);

        const float maximumSpeed = 350.0f;

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



    };
}

