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
        Vector2f initialPlayerPosition = Vector2f(500.0f, 500.0f);
        Vector2f playerPositon;
        PlayerState playerState;
        int playerScore;

    public:

        const Vector2f leftMostPosition = Vector2f(40.0f, 0.0f);
        const Vector2f rightMostPosition = Vector2f(700.0f, 0.0f);

        const float maximumSpeed = 200.0f;

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

