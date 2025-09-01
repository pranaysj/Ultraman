#pragma once
#include "../../header/UI/UIElement/UIView.h"

namespace UI
{
	namespace UIElement
	{
		class ImageView : public UIView
		{
		protected:
			sf::Texture imageTexture;
			sf::Sprite imageSprite;

		public:
			ImageView();
			virtual ~ImageView();

			virtual void Initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position);
			virtual void Update() override;
			virtual void Render() override;

			virtual void SetTexture(sf::String texture_path);
			virtual void SetScale(float width, float height);
			virtual void SetPosition(sf::Vector2f position);
			virtual void SetRotation(float rotation_angle);
			virtual void SetOriginAtCentre();
			virtual void SetImageAlpha(float alpha);
			virtual void SetCentreAlinged();

			const virtual sf::Sprite& GetSprite();
		};
	}
}