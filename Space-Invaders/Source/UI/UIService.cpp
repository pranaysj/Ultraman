
#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include"../../Header/UI/UIElement/TextView.h"

namespace UI{

	using namespace Main;
	using namespace MainMenu;
	using namespace Interface;
	using namespace UIElement;
	using namespace GameplayUI;

	UIService::UIService() {
		mainMenuController = nullptr;

		gameplay_ui_controller = nullptr;

		CreateControllers();
	}


	void UIService::CreateControllers() {
		mainMenuController = new MainMenuUIController();
		gameplay_ui_controller = new GameplayUIController();
	}

	UIService::~UIService() {
		Destroy();
	}

	void UIService::Initialize() {
		TextView::InitializeTextView();
		InitializeControllers();
	}

	void UIService::InitializeControllers() {
		mainMenuController->Initialize();
		gameplay_ui_controller->Initialize();
	}

	


	void UIService::Update() {

		IUIController* uiController = GetCurrentUIController();
		if (uiController)
		{
			uiController->Update();
		}
	}

	void UIService::Render() {

		IUIController* uiController = GetCurrentUIController();
		if (uiController)
		{
			uiController->Render();
		}
	}

	IUIController* UIService::GetCurrentUIController()
	{
		switch (GameService::GetGameState())
		{
		case GameState::MAIN_MENU:
			return mainMenuController;

		case GameState::GAMEPLAY:
			return gameplay_ui_controller;


		default:
			return nullptr;
		}
	}

	void UIService::Showscreen()
	{
		IUIController* uiController = GetCurrentUIController();
		if (uiController)
		{
			uiController->Show();
		}
	}

	void UIService::Destroy() {
		delete(mainMenuController);
		delete(gameplay_ui_controller);
	}
}