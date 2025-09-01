#pragma once
#include"../../Header/Element/Bunker/BunkerView.h"
#include"../../Header/Element/Bunker/BunkerController.h"
#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Global/Config.h"

namespace Element {
	namespace Bunker {

		using namespace Global;
		using namespace UI::UIElement;

		BunkerView::BunkerView(){
			createUIElements();
		}

		BunkerView::~BunkerView(){
			delete(bunkerImage);
		}

		void BunkerView::Initialize(BunkerController* _controller){
			bunkerController = _controller;
			initializeImage();

		}

		void BunkerView::createUIElements()
		{
			bunkerImage = new ImageView();
		}

		void BunkerView::initializeImage()
		{
			bunkerImage->Initialize(Config::bunker_texture_path,
				bunkerSpriteWidth,
				bunkerSpriteHeight,
				bunkerController->GetBunkerPosition());
		}

		void BunkerView::Destory()
		{
		}


		void BunkerView::Update(){
			bunkerImage->Update();
		}

		void BunkerView::Render(){
			bunkerImage->Render();
		}

		const sf::Sprite& BunkerView::GetBunkerSprite()
		{
			return bunkerImage->GetSprite();
		}
	}
}