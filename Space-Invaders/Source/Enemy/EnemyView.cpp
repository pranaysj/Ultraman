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

	Enemy::EnemyView::EnemyView() {
		CreateUIElements();
	}

	EnemyView::~EnemyView() {
		delete(enemyImage);
	}

	void EnemyView::Initialize(EnemyController* _controller){
		enemyController = _controller;
		InitializeImage();
	}

	void EnemyView::CreateUIElements()
	{
		enemyImage = new ImageView();
	}

	void EnemyView::InitializeImage()
	{
		enemyImage->Initialize(GetEnemyTexturePath(),
			enemySpriteWidth,
			enemySpriteHeigh,
			enemyController->GetEnemyPosition());
	}

	sf::String EnemyView::GetEnemyTexturePath()
	{
		switch (enemyController->GetEnemyType())
		{
		case EnemyType::SUBZERO:
			return Config::subzero_texture_path;

		case::Enemy::EnemyType::ZAPPER:
			return Config::zapper_texture_path;

		case::Enemy::EnemyType::THUNDER_SNAKE:
			return Config::thunder_snake_texture_path;

		case::Enemy::EnemyType::UFO:
			return Config::ufo_texture_path;
		}
	}


	void EnemyView::Update(){
		enemyImage->SetPosition(enemyController->GetEnemyPosition());
		enemyImage->Update();
	}

	void EnemyView::Render(){
		enemyImage->Render();
	}
}