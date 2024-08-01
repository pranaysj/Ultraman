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
		Destory();
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

	void PlayerView::Destory()
	{
		playerImage = new ImageView();
	}

	void PlayerView::Update() {
		playerImage->SetPosition(playerController->GetPlayerPosition());
		playerImage->Update();
	}

	void PlayerView::Render() {
		playerImage->Render();
	}

	void PlayerView::SetPlayerHighlight(bool b_highlight)
	{
		if (b_highlight)
		{
			playerImage->SetImageAlpha(PlayerModel::invincible_player_alpha);
		}
		else
		{
			playerImage->SetImageAlpha(255);
		}
	}

	const sf::Sprite& PlayerView::GetPlayerSprite()
	{
		return playerImage->GetSprite();
	}
}

