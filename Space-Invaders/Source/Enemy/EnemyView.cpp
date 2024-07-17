#pragma once
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicService.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Global/Config.h"

namespace Enemy {
	using namespace Global;
	using namespace UI::UIElement;

	void EnemyView::createUIElements()
	{
		enemy_image = new ImageView();
	}

	void EnemyView::initializeImage()
	{
		enemy_image->Initialize(getEnemyTexturePath(),
			enemySpriteWidth,
			enemySpriteHeigh,
			enemyController->GetEnemyPosition());
	}

	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemyController->GetEnemyType())
		{
		case EnemyType::SUBZERO:
			if (enemyTexture.loadFromFile(Config::subzero_texture_path))
			{
				enemySprite.setTexture(enemyTexture);
			}
			break;
		case::Enemy::EnemyType::ZAPPER:
			if (enemyTexture.loadFromFile(Config::zapper_texture_path))
			{
				enemySprite.setTexture(enemyTexture);
			}
			break;
		case::Enemy::EnemyType::THUNDER_SNAKE:
			if (enemyTexture.loadFromFile(Config::thunder_snake_texture_path))
			{
				enemySprite.setTexture(enemyTexture);
			}
			break;
		case::Enemy::EnemyType::UFO:
			if (enemyTexture.loadFromFile(Config::ufo_texture_path))
			{
				enemySprite.setTexture(enemyTexture);
			}
			break;
		}
	}

	void EnemyView::Destory()
	{
		delete(enemy_image);
	}

	Enemy::EnemyView::EnemyView() {
		createUIElements();
	}

	EnemyView::~EnemyView() {
		Destory();
	}

	void EnemyView::Initialize(EnemyController* _controller){
		enemyController = _controller;
		initializeImage();
	}

	void EnemyView::Update(){
		enemySprite.setPosition(enemyController->GetEnemyPosition());
		enemy_image->Update();
	}

	void EnemyView::Render(){
		enemy_image->Render();
	}
}