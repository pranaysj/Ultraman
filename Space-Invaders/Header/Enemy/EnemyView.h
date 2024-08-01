#pragma once
#include<SFML/Graphics.hpp>
#include"../../Header/UI/UIElement/ImageView.h"

namespace Enemy {
	using namespace sf;

	class EnemyController;
	enum class EnemyType;
		
	class EnemyView {
	private:

		const float enemySpriteWidth = 50.0f;
		const float enemySpriteHeigh = 50.0f;

		EnemyController* enemyController;
		RenderWindow* gameWindow;

		Texture enemyTexture;
		Sprite enemySprite;

		UI::UIElement::ImageView* enemyImage;

		void CreateUIElements();
		void InitializeImage();
		sf::String GetEnemyTexturePath();

	public:
		EnemyView();
		~EnemyView();

		void Initialize(EnemyController* _controller);
		void Update();
		void Render();

		const sf::Sprite& GetEnemySprite();
	};
}