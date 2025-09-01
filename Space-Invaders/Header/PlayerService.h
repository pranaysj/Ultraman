#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class PlayerService{
    private :

        int health = 3;
        Vector2f position = Vector2f(200.0f, 100.0f);
        int movement_speed = 5;
        int player_score = 0;
        const string playerTexturePath = "assets/textures/player_ship.png";

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

        void Move(float offset);
        int GetMovementSpeed();
        Vector2f GetPosition();

        // void takeDamage();
        // void shootBullets();
};