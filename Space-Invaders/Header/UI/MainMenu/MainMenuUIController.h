#pragma once
#include<SFML/Graphics.hpp>
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"

namespace UI {
	namespace MainMenu {
		class MainMenuUIController : public Interface::IUIController {
		private:
			
			const float buttonWidth = 300.f;
			const float buttonHeight = 140.f;


			const float playButton_Y_Position = 500.f;
			const float instructionsButton_Y_Position = 700.f;
			const float quit_Button_Y_Position = 900.f;

			//const float backgroundAlpha = 0.f;

			UIElement::ImageView* backgroundImage;

			UIElement::ButtonView* playButton;
			UIElement::ButtonView* instructionsButton;
			UIElement::ButtonView* quitButton;

			void CreateImage();
			void CreateButtons();

			void InitializeBackgroundImage();
			void InitializeButtons();

			void RegisterButtonCallback();

			void PlayButtonCallback();
			void InstructionsButtonCallback();
			void QuitButtonCallback();

			void Destroy();

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
