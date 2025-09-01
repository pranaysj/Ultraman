#pragma once
#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Bullet {

	using namespace Global;

	BulletView::BulletView(){

	}

	BulletView::~BulletView(){

	}

	void BulletView::Initialize(BulletController* _controller){
		bulletController = _controller;
		gameWindow = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
		InitializeImage(bulletController->GetBulletType());
	}


	void BulletView::InitializeImage(BulletType _type){
		switch (_type)
		{
		case::Bullet::BulletType::LASER_BULLET:
			if (bulletTexture.loadFromFile(Config::laser_bullet_texture_path))
			{
				bulletSprite.setTexture(bulletTexture);
				ScaleImage();
			}
			break;
		case::Bullet::BulletType::FROST_BULLET:
			if (bulletTexture.loadFromFile(Config::frost_beam_texture_path))
			{
				bulletSprite.setTexture(bulletTexture);
				ScaleImage();
			}
			break;
		case::Bullet::BulletType::TORPEDO:
			if (bulletTexture.loadFromFile(Config::torpedoe_texture_path))
			{
				bulletSprite.setTexture(bulletTexture);
				ScaleImage();
			}
			break;
		}
	}

	void BulletView::ScaleImage(){
		bulletSprite.setScale(
			static_cast<float>(bulletSpriteWidth) / bulletSprite.getTexture()->getSize().x,
			static_cast<float>(bulletSpriteHeight) / bulletSprite.getTexture()->getSize().y
		);
	}

	void BulletView::Update(){
		bulletSprite.setPosition(bulletController->GetProjectilePosition());
	}

	void BulletView::Render(){
		gameWindow->draw(bulletSprite);
	}
}

