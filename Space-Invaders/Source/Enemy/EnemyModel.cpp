#pragma once
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include <iostream>

namespace Enemy {
	Enemy::EnemyModel::EnemyModel(EnemyType _type){
		enemyType = _type;
	}

	EnemyModel::~EnemyModel(){

	}

	void EnemyModel::Initialize(){
		enemyCurrentPositon = enemyStartRefPositon; \
			enemyState = EnemyState::PATROLLING;
		//enemyMovement = MovementDirection::RIGHT;
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

	EnemyDirection EnemyModel::GetEnemyDirection(){
		return enemyDirection;
	}

	void EnemyModel::SetEnemyDirection(EnemyDirection _direction){
		enemyDirection = _direction;
	}


	/*void EnemyModel::SetEnemyMovement(MovementDirection _movement){
		enemyMovement = _movement;
	}

	MovementDirection EnemyModel::GetEnemyMovement(){
		return enemyMovement;
	}*/

}