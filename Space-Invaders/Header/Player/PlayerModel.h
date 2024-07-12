#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class PlayerModel{
    private:
        Vector2f initialPlayerPosition = Vector2f(500.0f, 500.0f);
        Vector2f playerPositon;
        bool playerAlive;

    public:

        const Vector2f leftMostPosition = Vector2f (50.0f,0.0f);
        const Vector2f rightMostPosition = Vector2f (7000.0f, 0.0f);

        const float maximumSpeed = 200.0f;

        PlayerModel();
        ~PlayerModel();

        void Initialize();
        void Reset();

        Vector2f GetPlayerPosition();
        void SetPlayerPosition(Vector2f position);

        bool GetPlayerAlive();
        void SetPlayerAlive(bool alive);

};