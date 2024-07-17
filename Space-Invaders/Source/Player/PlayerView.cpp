#include"../../Header/Player/PlayerView.h"
#include"../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"
#include "../../header/Graphics/GraphicService.h"
#include"../../Header/Global/Config.h"

namespace Player {
	using namespace Global;
	using namespace UI::UIElement;

	PlayerView::PlayerView() {
		createUIElements();
	}

	PlayerView::~PlayerView() {}

	void PlayerView::createUIElements()
	{
		player_image = new ImageView();
	}

	void PlayerView::Initialize(PlayerController* controller) {
		playerController = controller;
		initializeImage();
		
	}

	void PlayerView::initializeImage()
	{
		player_image->Initialize(getPlayerTexturePath(),
			playerSpriteWidth,
			playerSpriteHeigh,
			playerController->GetPlayerPosition());

	}

	sf::String PlayerView::getPlayerTexturePath()
	{
		if (playerTexture.loadFromFile(Config::player_texture_path)) {
			playerSprite.setTexture(playerTexture);
		}
	}

	void PlayerView::Update() {
		playerSprite.setPosition(playerController->GetPlayerPosition());
		player_image->Update();
	}

	void PlayerView::Render() {
		player_image->Render();
	}

}

