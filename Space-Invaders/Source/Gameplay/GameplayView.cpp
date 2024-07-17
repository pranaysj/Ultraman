#pragma once
#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Global/ServiceLocator.h"
#include"../../Header/Global/Config.h"


namespace Gameplay {
	using namespace Global;
	using namespace Graphics;
	using namespace UI::UIElement;

	void GameplayView::createUIElements()
	{
		gameplay_image = new ImageView();
	}

	void GameplayView::initializeImage()
	{
		gameplay_image->Initialize(getBackgroundTexturePath(),
			game_window->getSize().x,
			game_window->getSize().y,
			static_cast<sf::Vector2f>(game_window->getPosition()));
	}

	sf::String GameplayView::getBackgroundTexturePath()
	{
		if (background_texture.loadFromFile(Config::background_texture_path))
		{
			background_sprite.setTexture(background_texture);
		}
	}

	void GameplayView::Destory()
	{
		delete(gameplay_image);
	}

	GameplayView::GameplayView(){
		createUIElements();
	}

	GameplayView::~GameplayView(){
		Destory();
	}

	void GameplayView::Initialize(){
		initializeImage();
	}

	void GameplayView::Update(){

	}

	void GameplayView::Render(){
		gameplay_image->Render();
	}
}
