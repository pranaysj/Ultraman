#pragma once
#include<SFML/Graphics.hpp>

namespace Enemy {
	using namespace sf;
	enum class EnemyType;
	enum class EnemyState;
	enum class MovementDirection;

	class EnemyModel {
	private:
		EnemyType enemyType;
		EnemyState enemyState;
		MovementDirection movementDirection;

		Vector2f enemyStartRefPositon = Vector2f(0.0f, 0.0f);
		Vector2f enemyCurrentPositon;

	public:
		const Vector2f leftMostPosition = Vector2f(10.0f, 50.0f);
		const Vector2f rightMostPosition = Vector2f(1800.0f, 50.0f);
		
		const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 50.f); // we add this offset variable

		const float verticalTravelDistance = 100.f;

		float verticalMovementSpeed = 30.0f;
		float horizontalMovementSpeed = 100.0f;

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

		MovementDirection GetMovementDirection();
		void SetMovementDirection(MovementDirection _direction);
	};

}