#pragma once
#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Bullet {

	using namespace Global;
	using namespace UI::UIElement;

	BulletView::BulletView(){
		CreateUIElements();
	}

	BulletView::~BulletView(){
		Destory();
	}

	void BulletView::Initialize(BulletController* _controller){
		bulletController = _controller;
		InitializeImage();
	}


	void BulletView::CreateUIElements()
	{
		bulletImage = new ImageView();
	}

	void BulletView::InitializeImage()
	{
		bulletImage->Initialize(GetBulletTexturePath(),
			bulletSpriteWidth,
			bulletSpriteHeight,
			bulletController->GetProjectilePosition());
	}

	sf::String BulletView::GetBulletTexturePath()
	{
		switch (bulletController->GetBulletType())
		{
		case::Bullet::BulletType::LASER_BULLET:
			return Config::laser_bullet_texture_path;

		case::Bullet::BulletType::FROST_BULLET:
			return Config::frost_beam_texture_path;

		case::Bullet::BulletType::TORPEDO:
			return Config::torpedoe_texture_path;
		}
	}

	void BulletView::Update(){
		bulletImage->SetPosition(bulletController->GetProjectilePosition());
		bulletImage->Update();
	}

	void BulletView::Render(){
		bulletImage->Render();
	}
	
	void BulletView::Destory()
	{
		delete(bulletImage);
	}

}

