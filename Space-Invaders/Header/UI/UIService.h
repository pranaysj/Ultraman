#pragma once
#include"../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/GameplayUIController/GameplayUIController.h"
#include "../../Header/UI/SplashScreen/SplashScreenUIController .h"

namespace UI {

	class UIService {
	private:

		MainMenu::MainMenuUIController* mainMenuController;
		GameplayUI::GameplayUIController* gameplay_ui_controller;
		SplashScreen::SplashScreenUIController* splashScreenUIController;

		void CreateControllers();
		void InitializeControllers();

		Interface::IUIController* GetCurrentUIController();

		void Destroy();

	public:
		UIService();
		~UIService();

		void Initialize();
		void Update();
		void Render();

		void Showscreen();

	};
}