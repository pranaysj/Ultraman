#pragma once
#include "../../Header/Bullet/BulletModel.h"
namespace Bullet {
	Bullet::BulletModel::BulletModel(BulletType _type, Entity::EntityType _ownerType){
		bulletType = _type;
		ownerType = _ownerType;
	}

	BulletModel::~BulletModel(){

	}

	void BulletModel::Initialize(sf::Vector2f _position, MovementDirection _direction){
		bulletPosition = _position;
		movementDirection = _direction;
	}

	float BulletModel::GetMovementSpeed(){
		return movementSpeed;
	}

	void BulletModel::SetMovementSpeed(float _speed){
		movementSpeed = _speed;
	}

	sf::Vector2f BulletModel::GetBulletPosition(){
		return bulletPosition;
	}

	void BulletModel::SetBulletPosition(sf::Vector2f _position){
		bulletPosition = _position;
	}

	BulletType BulletModel::GetBulletType(){
		return bulletType;
	}

	/*void BulletModel::SetBulletType(BulletType _type){
		bulletType = _type;
	}*/

	MovementDirection BulletModel::GetMovementDirection(){
		return movementDirection;
	}

	void BulletModel::SetMovementDirection(MovementDirection _direction){
		movementDirection = _direction;
	}
	Entity::EntityType BulletModel::GetOwnerEntityType()
	{
		return ownerType;
	}
}

