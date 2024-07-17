#pragma once
#include"../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../Header/UI/Interface/IUIController.h"

namespace UI {

	class UIService {
	private:
		IUIController* GetCurrentUIController();

		MainMenu::MainMenuUIController* mainMenuController;

		void CreateControllers();
		void InitializeControllers();
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