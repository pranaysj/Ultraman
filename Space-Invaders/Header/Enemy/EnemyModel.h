#pragma once
#include<SFML/Graphics.hpp>

namespace Enemy {
	using namespace sf;
	enum class EnemyType;
	enum class EnemyState;
	enum class EnemyDirection;

	/*enum class EnemyState
	{
		ALIVE,
		DEAD,
	};

	enum class MovementDirection {
		RIGHT,
		LEFT,
		DOWN
	};*/

	class EnemyModel {
	private:
		EnemyType enemyType;
		EnemyState enemyState;
		EnemyDirection enemyDirection;

		Vector2f enemyStartRefPositon = Vector2f(0.0f, 0.0f);
		Vector2f enemyCurrentPositon;

	public:
		const Vector2f leftMostPosition = Vector2f(10.0f, 950.0f);
		const Vector2f rightMostPosition = Vector2f(1800.0f, 950.0f);

		const float maximumSpeed = 250.0f;
		const float downwardMovement = 100.0f;

		EnemyModel(EnemyType _type);
		~EnemyModel();

		void Initialize();

		Vector2f GetEnemyPositon();
		void SetEnemyPositon(Vector2f _posiiton);
		
		Vector2f GetRefPositon();
		void SetRefPositon(Vector2f _posiiton);

		EnemyType GetEnemyType();
		void SetEnemyType(EnemyType _type);

		EnemyState GetEnemyState();
		void SetEnemyState(EnemyState _state);

		EnemyDirection GetEnemyDirection();
		void SetEnemyDirection(EnemyDirection _direction);
	};

}