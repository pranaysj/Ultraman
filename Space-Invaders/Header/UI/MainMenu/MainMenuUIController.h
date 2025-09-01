#pragma once
#include<SFML/Graphics.hpp>
namespace UI {
	namespace MainMenu {
		class MainMenuUIController {
		private:
			const sf::String backgroundTexturePath = "assets/textures/space_invaders_bg.png";
			const sf::String playButtonTexturePath = "assets/textures/PlayButton.png";
			const sf::String instructionsButtonTexturePath = "assets/textures/InstructionsButton.png";
			const sf::String quitButtonTexturePath = "assets/textures/QuitButton.png";

			const float buttonWidth = 300.f;
			const float buttonHeight = 140.f;

			sf::Texture backgroundTexture;
			sf::Sprite backgroundSprite;

			sf::Texture playButtonTexture;
			sf::Sprite playButtonSprite;

			sf::Texture instructionsButtonTexture;
			sf::Sprite instructionsButtonSprite;

			sf::Texture quitButtonTexture;
			sf::Sprite quitButtonSprite;

			sf::RenderWindow* gameWindow;

			void InitializeBackgroundImage();
			void ScaleBackgroundImage();

			void InitializeButtons();
			bool LoadButtonTextureFromFile();
			void SetButtonSprites();

			void ScaleAllButtons();
			void ScaleButton(sf::Sprite* buttonToScale);
			void PositionButtons();

			void ProcessButtonInteractions();
			bool ClickedButton(sf::Sprite*, sf::Vector2f);

		public:
			MainMenuUIController();

			void Initialize();
			void Update();
			void Render();
		};
	}
}
