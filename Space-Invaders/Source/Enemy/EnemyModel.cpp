#pragma once
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include <iostream>

namespace Enemy {
	EnemyModel::EnemyModel(EnemyType _type){
		enemyType = _type;
		entity_type = Entity::EntityType::ENEMY;
	}

	EnemyModel::~EnemyModel(){}

	void EnemyModel::Initialize(){
		enemyState = EnemyState::PATROLLING;
		movementDirection = MovementDirection::RIGHT;
		enemyCurrentPositon = enemyStartRefPositon; 
	}
	
	Vector2f EnemyModel::GetEnemyPositon() {
		return enemyCurrentPositon;
	}

	void EnemyModel::SetEnemyPositon(Vector2f _posiiton){
		enemyCurrentPositon = _posiiton;
	}

	Vector2f Enemy::EnemyModel::GetRefPositon(){
		return enemyStartRefPositon;;
	}

	void EnemyModel::SetRefPositon(Vector2f _posiiton) {
		enemyStartRefPositon = _posiiton;
	}

	EnemyType EnemyModel::GetEnemyType(){
		return enemyType;
	}

	void EnemyModel::SetEnemyType(EnemyType _type){
		enemyType = _type;
	}

	EnemyState EnemyModel::GetEnemyState(){
		return enemyState;
	}

	void EnemyModel::SetEnemyState(EnemyState _state){
		enemyState = _state;
	}

	MovementDirection EnemyModel::GetMovementDirection(){
		return movementDirection;
	}

	void EnemyModel::SetMovementDirection(MovementDirection _direction){
		movementDirection = _direction;
	}

	Entity::EntityType EnemyModel::GetEntityType()
	{
		return entity_type;
	}
}