#pragma once
#include <SFML/Graphics.hpp>
#include"../../Header/Collision/ICollider.h"

namespace Enemy {
	
	class EnemyModel;
	class EnemyView;

	enum class EnemyState;
	enum class EnemyType;

	class EnemyController : public Collision::ICollider{
	protected:

		float rateOfFire = 3.f; //we want to fire the bullet every 3 seconds
		float elapsedFireDuration = 0.f;

		EnemyModel* enemyModel;
		EnemyView* enemyView;

		void UpdateFireTimer();
		void ProcessBulletFire();
		virtual void FireBullet() = 0;

		virtual void Move() = 0;

		sf::Vector2f GetRandomInitialPosition();
		virtual void Destroy();
		//void HandleOutOfBounds();

	public:

		EnemyController(EnemyType _type);
		virtual ~EnemyController();

		virtual void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();
		EnemyState GetEnemyState();
		EnemyType GetEnemyType();


		const sf::Sprite& GetColliderSprite() override;
		virtual void OnCollision(ICollider* other_collider) override;

	};
}