#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicService.h"


#pragma once
namespace Enemy {
	using namespace Global;

	void EnemyView::InitializeEnemySprite(){
		if (enemyTexture.loadFromFile(enemyTexturePath)) {
			enemySprite.setTexture(enemyTexture);
			ScaleEnemySprite();
		}
	}
	void EnemyView::ScaleEnemySprite(){
		enemySprite.setScale(
			static_cast<float>(enemySpriteWidth) / enemySprite.getTexture()->getSize().x,
			static_cast<float>(enemySpriteHeigh) / enemySprite.getTexture()->getSize().y

		);
	}

	Enemy::EnemyView::EnemyView()
	{
	}
	EnemyView::~EnemyView()
	{
	}

	void EnemyView::Initialize(EnemyController* _controller){
		enemyController = _controller;
		gameWindow = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
		InitializeEnemySprite();
	}

	void EnemyView::Update(){
		enemySprite.setPosition(enemyController->GetEnemyPosition());
	}

	void EnemyView::Render(){
		gameWindow->draw(enemySprite);
	}
}