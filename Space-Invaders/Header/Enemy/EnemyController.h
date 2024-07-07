#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy {
	
	class EnemyModel;
	class EnemyView;

	enum class EnemyState;
	enum class EnemyType;

	class EnemyController {

	private:
		float verticalMovementSpeed;
		float horizontalMovementSpeed;

		EnemyType enemytype;

		virtual void Move() = 0;
		/*void MoveLeft();
		void MoveRight();
		void MoveDown();*/

		void GetRandomInitialPosition();
		void HandleOutOfBounds();

	public:
		EnemyModel* enemyModel;
		EnemyView* enemyView;

		EnemyController(EnemyType _type);
		virtual ~EnemyController();

		virtual void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();

		void SetEnemyType(EnemyType _type);
		EnemyType GetEnemyType();

		void SetVerticalMovSpeed(float _vspeed);
		float GetVerticalMovSpeed();

		void SetHorizontalMovSpeed(float _hspeed);
		float GtHorizontalMovSpeed();
	};
}