#pragma once
#include <SFML/Graphics.hpp>

namespace Bullet
{
    class BulletController;
    enum class BulletType;

    class BulletView
    {
    private:
        const float bulletSpriteWidth = 15.f;
        const float bulletSpriteHeight = 15.f;

        sf::RenderWindow* gameWindow;
        sf::Texture bulletTexture;
        sf::Sprite bulletSprite;

        BulletController* bulletController;

        void InitializeImage(BulletType _type);
        void ScaleImage();

    public:
        BulletView();
        ~BulletView();

        void Initialize(BulletController* _controller);
        void Update();
        void Render();
    };
}
