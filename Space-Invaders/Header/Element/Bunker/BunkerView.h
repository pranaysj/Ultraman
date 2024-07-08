#pragma once
#include<SFML/Graphics.hpp>

namespace Element {
	namespace Bunker {
		class  BunkerController;

		class BunkerView {
		private:
			const float bunkerSpriteWidth = 80.f;
			const float bunkerSpriteHeight = 80.f;

			BunkerController* bunkerController;
			sf::RenderWindow* gameWindow;

			sf::Texture bunkerTexture;
			sf::Sprite bunkerSprite;

			const sf::String bunkerTexturePath = "assets/textures/bunker.png";

			void InitializeImage();
			void ScaleSprite();

		public:
			BunkerView();
			~BunkerView();

			void Initialize(BunkerController* _controller);
			void Update();
			void Render();
		};
	}
}