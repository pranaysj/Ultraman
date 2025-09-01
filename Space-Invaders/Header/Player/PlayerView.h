#pragma once
#include <SFML/Graphics.hpp>


namespace Player {
	using namespace sf;

	class PlayerController;

	class PlayerView {
	private:

		PlayerController* playerController;

		const String playerTexturePath = "assets/textures/Ultraman.png";
		const float playerSpriteWidth = 80.0f;
		const float playerSpriteHeigh = 135.0f;

		RenderWindow* gameWindow;

		Texture playerTexture;
		Sprite playerSprite;

		void InitializePlayerSprite();
		void ScalePlayerSprite();

	public:
		PlayerView();
		~PlayerView();

		void Initialize(PlayerController* controller);
		void Update();
		void Render();
	};
}
