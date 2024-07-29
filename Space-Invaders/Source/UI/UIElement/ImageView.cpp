#include "../../header/UI/UIElement/ImageView.h"
#include<iostream>

namespace UI
{
    namespace UIElement
    {
        ImageView::ImageView() = default;

        ImageView::~ImageView() = default;

        void ImageView::Initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position)
        {
            UIView::Initialize();
            SetTexture(texture_path);
            SetScale(image_width, image_height);
            SetPosition(position);
        }

        void ImageView::Update()
        {
            UIView::Update();
        }

        void ImageView::Render()
        {
            UIView::Render();

            if (uiState == UIState::VISIBLE)
            {
                gameWindow->draw(imageSprite);
            }
        }

        void ImageView::SetTexture(sf::String texture_path)
        {
            if (imageTexture.loadFromFile(texture_path))
            {
                imageSprite.setTexture(imageTexture);

            }
        }

        void ImageView::SetScale(float width, float height)
        {
            float scale_x = width / imageSprite.getTexture()->getSize().x;
            float scale_y = height / imageSprite.getTexture()->getSize().y;

            imageSprite.setScale(scale_x, scale_y);
        }

        void ImageView::SetPosition(sf::Vector2f position)
        {
            imageSprite.setPosition(position);

        }

        void ImageView::SetRotation(float rotation_angle)
        {
            imageSprite.setRotation(rotation_angle);
        }

        void ImageView::SetOriginAtCentre()
        {
            imageSprite.setOrigin(imageSprite.getLocalBounds().width / 2, imageSprite.getLocalBounds().height / 2);
        }

        void ImageView::SetImageAlpha(float alpha)
        {
            sf::Color color = imageSprite.getColor();
            color.a = alpha;
            imageSprite.setColor(color);
        }

        void ImageView::SetCentreAlinged()
        {
            float x_position = (gameWindow->getSize().x / 2) - (imageSprite.getGlobalBounds().width / 2);
            float y_position = imageSprite.getGlobalBounds().getPosition().y;

            imageSprite.setPosition(x_position, y_position);
        }
        const sf::Sprite& ImageView::GetSprite()
        {
            return imageSprite;
        }
    }
}