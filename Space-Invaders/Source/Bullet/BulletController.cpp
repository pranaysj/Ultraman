#pragma once
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletModel.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet {
	using namespace Global;
	using namespace Enemy;
	using namespace Player;
	using namespace Element::Bunker;
	using namespace Entity;

	BulletController::BulletController(BulletType _type, Entity::EntityType _ownerType){
		bulletView = new BulletView();
		bulletModel = new BulletModel(_type, _ownerType);
	}

	BulletController::~BulletController(){
		delete(bulletView);
		delete(bulletModel);
	}

	void BulletController::Initialize(sf::Vector2f _position, Bullet::MovementDirection _direction){
		bulletView->Initialize(this);
		bulletModel->Initialize(_position,_direction);
	}

	void BulletController::Update(){
		UpdateProjectilePosition();
		bulletView->Update();
		HandleOutOfBounds();
	}

	void BulletController::Render(){
		bulletView->Render();
	}

	void Bullet::BulletController::UpdateProjectilePosition(){
		switch (bulletModel->GetMovementDirection())
		{
		case::Bullet::MovementDirection::UP:
			MoveUp();
			break;

		case::Bullet::MovementDirection::DOWN:
			MoveDown();
			break;
		}

	}


	void BulletController::MoveUp(){
		sf::Vector2f currentPosition = bulletModel->GetBulletPosition();
		currentPosition.y -= bulletModel->GetMovementSpeed() * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		bulletModel->SetBulletPosition(currentPosition);
	}

	void BulletController::MoveDown(){
		sf::Vector2f currentPosition = bulletModel->GetBulletPosition();

		currentPosition.y += bulletModel->GetMovementSpeed() * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		bulletModel->SetBulletPosition(currentPosition);
	}

	void BulletController::HandleOutOfBounds(){
		sf::Vector2f bulletPosition = GetProjectilePosition();
		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow()->getSize();

		if (bulletPosition.x < 0 || bulletPosition.x > windowSize.x ||
			bulletPosition.y < 0 || bulletPosition.y > windowSize.y)
		{
			ServiceLocator::GetInstance()->GetBulletService()->DestroyBullet(this);
		}
	}

	sf::Vector2f BulletController::GetProjectilePosition(){
		return bulletModel->GetBulletPosition();
	}

	BulletType BulletController::GetBulletType(){
		return bulletModel->GetBulletType();
	}

	Entity::EntityType BulletController::GetOwnerEntityType()
	{
		return bulletModel->GetOwnerEntityType();
	}

	const sf::Sprite& BulletController::GetColliderSprite()
	{
		return bulletView->GetBulletSprite();
	}

	void BulletController::OnCollision(ICollider* other_collider)
	{
		ProcessPlayerCollision(other_collider);
		ProcessEnemyCollision(other_collider);
		ProcessBunkerCollision(other_collider);
		ProcessBulletCollision(other_collider);
	}

	void BulletController::ProcessBulletCollision(ICollider* other_collider)
	{
		BulletController* bulletController = dynamic_cast<BulletController*>(other_collider);

		if (bulletController)
			ServiceLocator::GetInstance()->GetBulletService()->DestroyBullet(this);
	}

	void BulletController::ProcessEnemyCollision(ICollider* other_collider)
	{
		EnemyController* enemyController = dynamic_cast<EnemyController*>(other_collider);

		if (enemyController && GetOwnerEntityType() != EntityType::ENEMY)
		{
			ServiceLocator::GetInstance()->GetBulletService()->DestroyBullet(this);
		}
	}

	void BulletController::ProcessPlayerCollision(ICollider* other_collider)
	{
		PlayerController* playerController = dynamic_cast<PlayerController*>(other_collider);

		if (playerController && GetOwnerEntityType() != EntityType::PLAYER)
		{
			ServiceLocator::GetInstance()->GetBulletService()->DestroyBullet(this);
		}
	}

	void BulletController::ProcessBunkerCollision(ICollider* other_collider)
	{
		BunkerController* bunkerController = dynamic_cast<BunkerController*>(other_collider);

		if (bunkerController)
			ServiceLocator::GetInstance()->GetBulletService()->DestroyBullet(this);
	}
}


