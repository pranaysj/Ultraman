#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy {
	
	class EnemyModel;
	class EnemyView;
	enum class EnemyState;

	class EnemyController {
	private:
		float verticalMovementSpeed;
		float horizontalMovementSpeed;

		EnemyModel* enemymodel;
		EnemyView* enemyView;

		virtual void Move();
		void MoveLeft();
		void MoveRight();
		void MoveDown();

		void GetRandomInitialPosition();
		void HandleOutOfBounds();

	public:
		EnemyController();
		virtual ~EnemyController();

		virtual void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();

		void SetVerticalMovSpeed(float _vspeed);
		float GetVerticalMovSpeed();

		void SetHorizontalMovSpeed(float _hspeed);
		float GtHorizontalMovSpeed();
	};
}