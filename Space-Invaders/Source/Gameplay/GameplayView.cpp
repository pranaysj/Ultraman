#pragma once
#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Global/ServiceLocator.h"
#include"../../Header/Global/Config.h"


namespace Gameplay {
	using namespace Global;
	using namespace Graphics;
	using namespace UI::UIElement;


	GameplayView::GameplayView(){
		backgroundImage = new ImageView();
	}

	GameplayView::~GameplayView(){
		delete(backgroundImage);
	}

	void GameplayView::Initialize(){
		InitializeBackgroundImage();
	}

	void GameplayView::InitializeBackgroundImage()
	{
		gameWindow = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
		
		backgroundImage->Initialize(Config::background_texture_path,
			gameWindow->getSize().x,
			gameWindow->getSize().y,
			static_cast<sf::Vector2f>(gameWindow->getPosition()));
	}

	void GameplayView::Update(){
		backgroundImage->Update();
	}

	void GameplayView::Render(){
		backgroundImage->Render();
	}
}
