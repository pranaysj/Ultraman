#pragma once
#include <SFML/Graphics.hpp>
#include"../../Header/UI/UIElement/ImageView.h"


namespace Player {
	using namespace sf;

	class PlayerController;

	class PlayerView {
	private:

		PlayerController* playerController;
		RenderWindow* gameWindow;

		//const String playerTexturePath = "assets/textures/Ultraman.png";
		const float playerSpriteWidth = 50.0f;
		const float playerSpriteHeigh = 85.0f;

		Texture playerTexture;
		Sprite playerSprite;

		/*void InitializePlayerSprite();
		void ScalePlayerSprite();*/
		UI::UIElement::ImageView* player_image;

		void createUIElements();
		void initializeImage();
		sf::String getPlayerTexturePath();


	public:
		PlayerView();
		~PlayerView();

		void Initialize(PlayerController* controller);
		void Update();
		void Render();
	};
}
