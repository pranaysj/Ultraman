#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Collision/ICollider.h"
#include "../../Header/Powerups/PowerupConfig.h"
#include "../../Header/Player/PlayerModel.h"

namespace Player {
	using namespace sf;

	enum class PlayerState;
	
	//class PlayerModel;

	class PlayerView;

	class PlayerController : public Collision::ICollider {
	private:

		float elapsed_shield_duration;
		float elapsed_rapid_fire_duration;
		float elapsed_tripple_laser_duration;

		float elapsed_fire_duration;
		float elapsed_freez_duration;

		PlayerModel* playerModel;
		PlayerView* playerView;

		void ProcessPlayerInput();
		void MoveLeft();
		void MoveRight();

		bool ProcessBulletCollision(ICollider* _ollider);
		bool ProcessPowerupCollision(ICollider* _collider);
		bool ProcessEnemyCollision(ICollider* _collider);

		void UpdateFreezDuration();
		void FreezPlayer();

		void UpdateFireDuration();
		void ProcessBulletFire();
		void FireBullet(bool b_tripple_laser = false);
		void FireBullet(sf::Vector2f position);

		void UpdatePowerupDuration();

		void DisableShield();
		void DisableRapidFire();
		void DisableTrippleLaser();

		void FireBullet();

	public:
		PlayerController();
		~PlayerController();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		void EnableShield();
		void EnableRapidFire();
		void EnableTrippleLaser();

		Vector2f GetPlayerPosition();
		PlayerState GetPlayerState();

		const sf::Sprite& GetColliderSprite() override;
		void OnCollision(ICollider* _collider) override;
	};
}

