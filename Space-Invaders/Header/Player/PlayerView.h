#pragma once
#include <SFML/Graphics.hpp>
#include"../../Header/UI/UIElement/ImageView.h"


namespace Player {
	using namespace sf;

	class PlayerController;

	class PlayerView {
	private:

		const float playerSpriteWidth = 60.0f;
		const float playerSpriteHeigh = 100.0f;

		/*Texture playerTexture;
		Sprite playerSprite;*/

		PlayerController* playerController;
		UI::UIElement::ImageView* playerImage;

		void CreateUIElements();
		void InitializeImage();

		void Destory();

	public:
		PlayerView();
		~PlayerView();

		void Initialize(PlayerController* controller);
		void Update();
		void Render();

		void SetPlayerHighlight(bool b_highlight);
		const sf::Sprite& GetPlayerSprite();
	};
}
