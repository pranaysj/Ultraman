#include"../../Header/Player/PlayerView.h"
#include"../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"
#include "../../header/Graphics/GraphicService.h"
#include"../../Header/Global/Config.h"

namespace Player {
	using namespace Global;
	using namespace UI::UIElement;

	PlayerView::PlayerView() {
		CreateUIElements();
	}

	void PlayerView::CreateUIElements()
	{
		playerImage = new ImageView();
	}

	PlayerView::~PlayerView() {
		delete(playerImage);
	}

	void PlayerView::Initialize(PlayerController* controller) {
		playerController = controller;
		InitializeImage();
	}

	void PlayerView::InitializeImage()
	{
		playerImage->Initialize(Config::player_texture_path,
			playerSpriteWidth,
			playerSpriteHeigh,
			playerController->GetPlayerPosition());
	}

	void PlayerView::Update() {
		playerImage->SetPosition(playerController->GetPlayerPosition());
		playerImage->Update();
	}

	void PlayerView::Render() {
		playerImage->Render();
	}

}

