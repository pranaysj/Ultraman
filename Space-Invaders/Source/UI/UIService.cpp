
#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include"../../Header/UI/UIElement/TextView.h"

namespace UI{

	using namespace Main;
	using namespace MainMenu;
	using namespace Interface;
	using namespace UIElement;

	UIService::UIService() {
		mainMenuController = nullptr;
		CreateControllers();
	}


	void UIService::CreateControllers() {
		mainMenuController = new MainMenuUIController();
	}

	UIService::~UIService() {
		Destroy();
	}

	void UIService::Initialize() {
		TextView::initializeTextView();
		InitializeControllers();
	}

	void UIService::InitializeControllers() {
		mainMenuController->Initialize();
	}

	void UIService::Destroy() {
		delete(mainMenuController);
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
			break;
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
}