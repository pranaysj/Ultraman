#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/UI/UIElement/ImageView.h"

namespace Gameplay {
	using namespace sf;

	class GameplayView {
	private:
		RenderWindow* game_window;
		
		Texture background_texture;
		Sprite background_sprite;

		UI::UIElement::ImageView* gameplay_image;

		void createUIElements();
		void initializeImage();
		sf::String getBackgroundTexturePath();

		void Destory();

	public:
		GameplayView();
		~GameplayView();

		void Initialize();
		void Update();
		void Render();
	};
}
