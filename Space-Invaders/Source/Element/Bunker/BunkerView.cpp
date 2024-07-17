#pragma once
#include"../../Header/Element/Bunker/BunkerView.h"
#include"../../Header/Element/Bunker/BunkerController.h"
#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Global/Config.h"

namespace Element {
	namespace Bunker {

		using namespace Global;
		using namespace UI::UIElement;

		void BunkerView::createUIElements()
		{
			bunker_image = new ImageView();
		}

		void BunkerView::initializeImage()
		{
			bunker_image->Initialize(getBunkerTexturePath(),
				bunkerSpriteWidth,
				bunkerSpriteHeight,
				bunkerController->GetBunkerPosition());
		}

		sf::String BunkerView::getBunkerTexturePath()
		{
			if (bunkerTexture.loadFromFile(Config::bunker_texture_path))
			{
				bunkerSprite.setTexture(bunkerTexture);
			}
		}

		void BunkerView::Destory()
		{
			delete(bunker_image);
		}

		BunkerView::BunkerView(){
			createUIElements();
		}

		BunkerView::~BunkerView(){
			Destory();
		}

		void BunkerView::Initialize(BunkerController* _controller){
			bunkerController = _controller;
			initializeImage();

		}

		void BunkerView::Update(){
			bunkerSprite.setPosition(bunkerController->GetBunkerPosition());
			bunker_image->Update();
		}

		void BunkerView::Render(){
			bunker_image->Render();
		}
	}
}