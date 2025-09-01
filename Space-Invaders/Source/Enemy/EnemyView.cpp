#pragma once
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicService.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Global/Config.h"

namespace Enemy {
	using namespace Global;

	Enemy::EnemyView::EnemyView() {}

	EnemyView::~EnemyView() {}

	void EnemyView::Initialize(EnemyController* _controller){
		enemyController = _controller;
		gameWindow = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
		InitializeEnemySprite(enemyController->GetEnemyType());
	}
	
	void EnemyView::InitializeEnemySprite(EnemyType _type){
		switch (_type)
		{
		case EnemyType::SUBZERO:
			if (enemyTexture.loadFromFile(Config::subzero_texture_path))
			{
				enemySprite.setTexture(enemyTexture);
				ScaleEnemySprite();
			}
			break;
		case::Enemy::EnemyType::ZAPPER:
			if (enemyTexture.loadFromFile(Config::zapper_texture_path))
			{
				enemySprite.setTexture(enemyTexture);
				ScaleEnemySprite();
			}
			break;
		}
	}
	void EnemyView::ScaleEnemySprite(){
		enemySprite.setScale(
			static_cast<float>(enemySpriteWidth) / enemySprite.getTexture()->getSize().x,
			static_cast<float>(enemySpriteHeigh) / enemySprite.getTexture()->getSize().y

		);
	}



	void EnemyView::Update(){
		enemySprite.setPosition(enemyController->GetEnemyPosition());
	}

	void EnemyView::Render(){
		gameWindow->draw(enemySprite);
	}
}