#pragma once
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletModel.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Bullet {
	using namespace Global;
	BulletController::BulletController(BulletType _type){
		bulletView = new BulletView();
		bulletModel = new BulletModel(_type);
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
		currentPosition.y -= bulletModel->GetMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bulletModel->SetBulletPosition(currentPosition);
	}

	void BulletController::MoveDown(){

	}

	void BulletController::HandleOutOfBounds(){

	}

	sf::Vector2f BulletController::GetProjectilePosition(){
		return sf::Vector2f();
	}

	BulletType BulletController::GetBulletType(){
		return BulletType();
	}
}


