#pragma once
#include<SFML/Graphics.hpp>
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"

namespace UI {
	namespace MainMenu {
		class MainMenuUIController : public Interface::IUIController {
		private:
			/*const sf::String backgroundTexturePath = "assets/textures/space_invaders_bg.png";
			const sf::String playButtonTexturePath = "assets/textures/PlayButton.png";
			const sf::String instructionsButtonTexturePath = "assets/textures/InstructionsButton.png";
			const sf::String quitButtonTexturePath = "assets/textures/QuitButton.png";*/

			const float button_width = 300.f;
			const float button_height = 140.f;

			/*sf::Texture backgroundTexture;
			sf::Sprite backgroundSprite;

			sf::Texture playButtonTexture;
			sf::Sprite playButtonSprite;

			sf::Texture instructionsButtonTexture;
			sf::Sprite instructionsButtonSprite;

			sf::Texture quitButtonTexture;
			sf::Sprite quitButtonSprite;

			sf::RenderWindow* gameWindow;*/

			const float play_button_y_position = 500.f;
			const float instructions_button_y_position = 700.f;
			const float quit_button_y_position = 900.f;

			const float background_alpha = 85.f;

			UIElement::ImageView* background_image;

			UIElement::ButtonView* play_button;
			UIElement::ButtonView* instructions_button;
			UIElement::ButtonView* quit_button;

			void createImage();
			void createButtons();

			void initializeBackgroundImage();
			void initializeButtons();

			void registerButtonCallback();
			void ScaleBackgroundImage();

			void playButtonCallback();
			void instructionsButtonCallback();
			void quitButtonCallback();

			void destroy();

			/*bool LoadButtonTextureFromFile();
			void SetButtonSprites();

			void ScaleAllButtons();
			void ScaleButton(sf::Sprite* buttonToScale);
			void PositionButtons();

			void ProcessButtonInteractions();
			bool ClickedButton(sf::Sprite*, sf::Vector2f);*/

		public:
			MainMenuUIController();
			~MainMenuUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;
			void Show() override;
		};
	}
}
