#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/UI/UIElement/ImageView.h"

namespace Gameplay {
	using namespace sf;

	class GameplayView {
	private:
		RenderWindow* gameWindow;
		
		Texture backgroundTexture;
		Sprite backgroundSprite;

		UI::UIElement::ImageView* backgroundImage;

		void InitializeBackgroundImage();

	public:
		GameplayView();
		~GameplayView();

		void Initialize();
		void Update();
		void Render();
	};
}
