#pragma once
#include <SFML/Graphics.hpp>
#include"../../Header/UI/UIElement/ImageView.h"

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

        UI::UIElement::ImageView* bullet_image;

        void createUIElements();
        void initializeImage();
        sf::String getBulletTexturePath();
        void Destory();

    public:
        BulletView();
        ~BulletView();

        void Initialize(BulletController* _controller);
        void Update();
        void Render();
    };
}
