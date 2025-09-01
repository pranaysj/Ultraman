#pragma once
#include"../../Header/UI/MainMenu/MainMenuUIController.h"

namespace UI {

	class UIService {
	private:
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

	};
}