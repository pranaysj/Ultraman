#include"../../Header/Player/PlayerView.h"
#include"../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"

namespace Player {
	using namespace Global;

	PlayerView::PlayerView() {}

	PlayerView::~PlayerView() {}

	void PlayerView::Initialize(PlayerController* controller) {
		//gameWindow
		//InitializePlayerSprite
		playerController = controller;
		gameWindow = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
		InitializePlayerSprite();
	}

	void PlayerView::InitializePlayerSprite() {
		if (playerTexture.loadFromFile(playerTexturePath)) {
			playerSprite.setTexture(playerTexture);
			ScalePlayerSprite();
		}

		//teture load
		//Sprite set
		//Scale the Sprite
	}

	void PlayerView::ScalePlayerSprite() {
		//scale the sprite using SetSCale method
		playerSprite.setScale(
			static_cast<float>(playerSpriteWidth) / playerSprite.getTexture()->getSize().x,
			static_cast<float>(playerSpriteHeigh) / playerSprite.getTexture()->getSize().y

		);
	}

	void PlayerView::Update() {
		//EMpty for now
		playerSprite.setPosition(playerController->GetPlayerPosition());
	}

	void PlayerView::Render() {
		//Draw the Sprite
		gameWindow->draw(playerSprite);
	}

}

