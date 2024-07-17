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
		createUIElements();
	}

	BulletView::~BulletView(){
		Destory();
	}

	void BulletView::Initialize(BulletController* _controller){
		bulletController = _controller;
		initializeImage();
	}


	void BulletView::createUIElements()
	{
		bullet_image = new ImageView();
	}

	void BulletView::initializeImage()
	{
		bullet_image->Initialize(getBulletTexturePath(),
			bulletSpriteWidth,
			bulletSpriteHeight,
			bulletController->GetProjectilePosition());
	}

	sf::String BulletView::getBulletTexturePath()
	{
		switch (bulletController->GetBulletType())
		{
		case::Bullet::BulletType::LASER_BULLET:
			if (bulletTexture.loadFromFile(Config::laser_bullet_texture_path))
			{
				bulletSprite.setTexture(bulletTexture);
			}
			break;
		case::Bullet::BulletType::FROST_BULLET:
			if (bulletTexture.loadFromFile(Config::frost_beam_texture_path))
			{
				bulletSprite.setTexture(bulletTexture);
			}
			break;
		case::Bullet::BulletType::TORPEDO:
			if (bulletTexture.loadFromFile(Config::torpedoe_texture_path))
			{
				bulletSprite.setTexture(bulletTexture);
			}
			break;
		}
	}

	void BulletView::Update(){
		bulletSprite.setPosition(bulletController->GetProjectilePosition());
		bullet_image->Update();
	}

	void BulletView::Render(){
		bullet_image->Render();
	}
	
	void BulletView::Destory()
	{
		delete(bullet_image);
	}

}

