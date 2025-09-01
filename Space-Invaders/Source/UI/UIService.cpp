
#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"

namespace UI{

	using namespace Main;
	using namespace MainMenu;

	void UIService::CreateControllers() {
		mainMenuController = new MainMenuUIController();
	}

	void UIService::InitializeControllers() {
		mainMenuController->Initialize();
	}

	void UIService::Destroy() {
		delete(mainMenuController);
	}

	UIService::UIService() {
		mainMenuController = nullptr;
		CreateControllers();
	}

	UIService::~UIService() {
		Destroy();
	}

	void UIService::Initialize() {
		InitializeControllers();
	}

	void UIService::Update() {

		switch (GameService::GetGameState())
		{
			case GameState::MAIN_MENU:
				return mainMenuController->Update();
			break;
		}
	}

	void UIService::Render() {
		switch (GameService::GetGameState())
		{
			case GameState::MAIN_MENU:
				return mainMenuController->Render();
			break;
		}
	}
}