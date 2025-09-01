#pragma once
#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Gameplay {
	using namespace Global;
	using namespace Graphics;

	void Gameplay::GameplayView::InitializeBackgroundSprite(){
		if (background_texture.loadFromFile(background_texture_path))
		{
			background_sprite.setTexture(background_texture);
			ScaleBackgroundSprite();
		}
	}

	void GameplayView::ScaleBackgroundSprite(){
		background_sprite.setScale(
			static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
			static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
		);
	}

	GameplayView::GameplayView(){

	}

	GameplayView::~GameplayView(){

	}

	void GameplayView::Initialize(){
		game_window = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
		InitializeBackgroundSprite();
	}

	void GameplayView::Update(){

	}

	void GameplayView::Render(){
		game_window->draw(background_sprite);
	}
}
