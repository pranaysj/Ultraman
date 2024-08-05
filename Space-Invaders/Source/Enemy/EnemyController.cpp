#pragma once
#include <iostream>
#include"../../Header/Enemy/EnemyController.h"
#include"../../Header/Enemy/EnemyModel.h"
#include"../../Header/Enemy/EnemyView.h"
#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Bullet/BulletConfig.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Animation/AnimationSystem.h"

namespace Enemy {

	using namespace Global;
	using namespace Time;
	using namespace Bullet;
	using namespace Collision;
	using namespace Entity;
	using namespace Player;
	using namespace Sound;
	using namespace Animation;
	
	EnemyController::EnemyController(EnemyType _type){
		enemyModel = new EnemyModel(_type);
		enemyView = new EnemyView();
	}

	EnemyController::~EnemyController(){
		delete(enemyModel);
		delete(enemyView);
	}

	void EnemyController::Initialize(){
		enemyModel->Initialize();
		enemyModel->SetEnemyPositon(GetRandomInitialPosition());
		enemyView->Initialize(this);
	}

	sf::Vector2f EnemyController::GetRandomInitialPosition()
	{
		float x_offset_distance = (std::rand() % static_cast<int>(enemyModel->rightMostPosition.x - enemyModel->leftMostPosition.x));

		float x_position = enemyModel->leftMostPosition.x + x_offset_distance;

		float y_position = enemyModel->leftMostPosition.y;

		return sf::Vector2f(x_position, y_position);
	}

	void EnemyController::Update(){
		Move();
		UpdateFireTimer();
		ProcessBulletFire();
		//HandleOutOfBounds();
		enemyView->Update();
	}

	void EnemyController::Render(){
		enemyView->Render();
	}
	
	void EnemyController::UpdateFireTimer(){
		elapsedFireDuration += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}

	void EnemyController::ProcessBulletFire(){
		if (elapsedFireDuration >= rateOfFire)
		{
			FireBullet();
			elapsedFireDuration = 0.f; //set elapsed duration back to 0.
		}
	}

	//void EnemyController::HandleOutOfBounds(){
	//	sf::Vector2f enemyPosition = GetEnemyPosition();
	//	sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow()->getSize();
	//	// Destroy the enemy if it goes out of bounds.
	//	if (enemyPosition.x < 0 || enemyPosition.x > windowSize.x ||
	//		enemyPosition.y < 0 || enemyPosition.y > windowSize.y)
	//	{
	//		ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this);
	//	}
	//}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPositon();
	}

	EnemyState EnemyController::GetEnemyState()
	{
		return enemyModel->GetEnemyState();
	}

	EnemyType EnemyController::GetEnemyType()
	{
		return enemyModel->GetEnemyType();
	}

	const sf::Sprite& EnemyController::GetColliderSprite()
	{
		return enemyView->GetEnemySprite();
	}

	void EnemyController::OnCollision(ICollider* other_collider)
	{
		BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);
		if (bullet_controller && bullet_controller->GetOwnerEntityType() != EntityType::ENEMY)
		{
			Destroy();
			return;
		}

		PlayerController* player_controller = dynamic_cast<PlayerController*>(other_collider);
		if (player_controller)
		{
			Destroy();
			return;
		}
	}

	void EnemyController::Destroy()
	{
		ServiceLocator::GetInstance()->GetAnimationService()->SpawnAnimationSystem(enemyModel->GetEnemyPositon(), Animation::AnimationType::EXPLOSION);
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::EXPLOSION);

		ServiceLocator::GetInstance()->GetPlayerService()->IncreaseEnemiesKilled(1);
		ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this);
	}
}