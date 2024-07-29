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

		bool ProcessBulletCollision(ICollider* _collider);
		bool ProcessPowerupCollision(ICollider* _collider);
		bool ProcessEnemyCollision(ICollider* _collider);

		void UpdateFreezeDuration();
		void FreezePlayer();

		void UpdateFireDuration();
		void ProcessBulletFire();
		void FireBullet(bool boolTrippleLaser = false);
		void FireBullet(sf::Vector2f _position);

		void UpdatePowerupDuration();

		void DisableShield();
		void DisableRapidFire();
		void DisableTrippleLaser();

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
		int GetPlayerScore();
		PlayerState GetPlayerState();

		const sf::Sprite& GetColliderSprite() override;
		void OnCollision(ICollider* _collider) override;
	};
}

