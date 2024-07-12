#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class PlayerService{
    private :

        int health = 3;
        Vector2f position = Vector2f(200.0f, 100.0f);
        float movementSpeed = 100;
        int playerScore = 0;

        const String playerTexturePath = "assets/textures/player_ship.png";

        RenderWindow *gameWindow;

        Texture playerTexture;
        Sprite playerSprite;

        void InitiallayerSprite();
        void ProcessPlayerInput();

    public :

        PlayerService();
        ~PlayerService();

        void Initialize();
        void Update();
        void Render();

        void MoveLeft();
        void MoveRight();
        //void Move(float offset);
        int GetMovementSpeed();
        Vector2f GetPosition();

        // void takeDamage();
        // void shootBullets();
};