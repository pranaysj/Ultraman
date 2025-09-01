#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy {
	
	class EnemyModel;
	class EnemyView;

	enum class EnemyState;
	enum class EnemyType;

	class EnemyController {

	protected:
		/*float verticalMovementSpeed;
		float horizontalMovementSpeed;*/

		//EnemyType enemytype;

		float rate_of_fire = 3.f; //we want to fire the bullet every 3 seconds
		float elapsed_fire_duration = 0.f;

		EnemyModel* enemyModel;
		EnemyView* enemyView;

		void UpdateFireTimer();
		void ProcessBulletFire();
		virtual void FireBullet() = 0;

		virtual void Move() = 0;

		sf::Vector2f GetRandomInitialPosition();
		void HandleOutOfBounds();

	public:

		EnemyController(EnemyType _type);
		virtual ~EnemyController();

		virtual void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();
		EnemyState GetEnemyState();
		EnemyType GetEnemyType();

		/*void SetEnemyType(EnemyType _type);
		EnemyType GetEnemyType();*/

		/*void SetVerticalMovSpeed(float _vspeed);
		float GetVerticalMovSpeed();

		void SetHorizontalMovSpeed(float _hspeed);
		float GtHorizontalMovSpeed();*/

	};
}