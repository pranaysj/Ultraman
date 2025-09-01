#pragma once
#include<SFML/Graphics.hpp>

namespace Gameplay {
	using namespace sf;

	class GameplayView {
	private:
		const String background_texture_path = "assets/textures/space_invaders_bg.png";
		
		RenderWindow* game_window;
		
		Texture background_texture;
		Sprite background_sprite;

		void InitializeBackgroundSprite();
		void ScaleBackgroundSprite();

	public:
		GameplayView();
		~GameplayView();

		void Initialize();
		void Update();
		void Render();
	};
}
