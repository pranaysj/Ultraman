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

        sf::Texture bulletTexture;
        sf::Sprite bulletSprite;

        BulletController* bulletController;
        UI::UIElement::ImageView* bulletImage;

        void CreateUIElements();
        void InitializeImage();
        sf::String GetBulletTexturePath();
        void Destory();

    public:
        BulletView();
        ~BulletView();

        void Initialize(BulletController* _controller);
        void Update();
        void Render();

        sf::Sprite& GetBulletSprite();
    };
}
