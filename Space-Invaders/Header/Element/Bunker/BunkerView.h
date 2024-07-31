#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/UI/UIElement/ImageView.h"

namespace Element {
	namespace Bunker {
		class  BunkerController;

		class BunkerView {
		private:
			const float bunkerSpriteWidth = 70.f;
			const float bunkerSpriteHeight = 70.f;

			BunkerController* bunkerController;
			sf::RenderWindow* gameWindow;

			sf::Texture bunkerTexture;
			sf::Sprite bunkerSprite;

			//const sf::String bunkerTexturePath = "assets/textures/bunker.png";
			UI::UIElement::ImageView* bunkerImage;

			void createUIElements();
			void initializeImage();

			void Destory();

		public:
			BunkerView();
			~BunkerView();

			void Initialize(BunkerController* _controller);
			void Update();
			void Render();

			const sf::Sprite& GetBunkerSprite();
		};
	}
}