#pragma once
#include<SFML/Graphics.hpp>

namespace Enemy {
	using namespace sf;

	class EnemyController;
	enum class EnemyType;
		
	class EnemyView {
	private:

		/*const String droneOneTexturePath = "assets/textures/Drone _1.png"; 
		const String droneTwoTexturePath = "assets/textures/Drone _2.png"; 
		const sf::String subzero_texture_path = "assets/textures/subzero.png";
		const sf::String zapper_texture_path = "assets/textures/zapper.png";*/

		const float enemySpriteWidth = 50.0f;
		const float enemySpriteHeigh = 50.0f;

		EnemyController* enemyController;
		RenderWindow* gameWindow;
		Texture enemyTexture;
		Sprite enemySprite;

		void InitializeEnemySprite(EnemyType _type);
		void ScaleEnemySprite();

	public:
		EnemyView();
		~EnemyView();

		void Initialize(EnemyController* _controller);
		void Update();
		void Render();
	};
}