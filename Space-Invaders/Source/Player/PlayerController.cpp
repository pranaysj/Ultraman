#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Player/PlayerModel.h"
#include"../../Header/Global/ServiceLocator.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Powerups/PoweupController.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Main/GameService.h"


namespace Player {
	using namespace Global;
	using namespace Event;
	using namespace Bullet;
	using namespace Entity;
	using namespace Enemy;
	using namespace Powerup;
	using namespace Sound;
	using namespace Main;
	using namespace Gameplay;


	PlayerController::PlayerController() {
		playerModel = new PlayerModel();
		playerView = new PlayerView();
	}

	PlayerController::~PlayerController() {
		delete(playerModel);
		delete(playerView);
	}

	void PlayerController::Initialize() {
		playerModel->Initialize();
		playerView->Initialize(this);
	}

	void PlayerController::Update() {
		switch (playerModel->GetPlayerState())
		{
		case::Player::PlayerState::ALIVE:
			ProcessPlayerInput();
			break;

		case::Player::PlayerState::FROZEN:
			UpdateFreezeDuration();
			break;
		}

		UpdatePowerupDuration();
		UpdateFireDuration();

		playerView->Update();
	}

	void PlayerController::Render() {
		playerView->Render();
	}

	void PlayerController::Reset()
	{
		playerModel->Reset();
	}

	void PlayerController::ProcessPlayerInput() {
		EventService* eventService = ServiceLocator::GetInstance()->GetEventService();

		if (eventService->PressedLeftKey() || eventService->PressedAKey()){
			MoveLeft();
		}

		if (eventService->PressedRightKey() || eventService->PressedDKey()) {
			MoveRight();
		}

		if (eventService->PressedLeftMouseButton()) {
			FireBullet();
		}
	}

	void PlayerController::MoveLeft() {
		Vector2f currentPosition = playerModel->GetPlayerPosition();
		currentPosition.x -= playerModel->playerMaximumSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		currentPosition.x = max(currentPosition.x, playerModel->leftMostPosition.x);
		playerModel->SetPlayerPosition(currentPosition);
	}

	void PlayerController::MoveRight() {
		Vector2f currentPosition = playerModel->GetPlayerPosition();
		currentPosition.x += playerModel->playerMaximumSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		currentPosition.x = min(currentPosition.x, playerModel->rightMostPosition.x);
		playerModel->SetPlayerPosition(currentPosition);
	}

	bool PlayerController::ProcessBulletCollision(ICollider* _collider)
	{
		if (playerModel->IsShieldEnabled())
			return false;

		BulletController* bulletController = dynamic_cast<BulletController*>(_collider);

		if (bulletController && bulletController->GetOwnerEntityType() != Entity::EntityType::PLAYER)
		{
			if (bulletController->GetBulletType() == BulletType::FROST_BULLET)
			{
				FreezePlayer();
				/*playerModel->SetPlayerState(PlayerState::FROZEN);
				playerModel->elapsedFreezeDuration = playerModel->freezeDuration;*/
			}
			else {
				DecreasePlayerLive();
			}
			return true;
		}

		return false;
	}

	bool PlayerController::ProcessPowerupCollision(ICollider* _collider)
	{
		PowerupController* powerupController = dynamic_cast<PowerupController*>(_collider);
		if (powerupController)
		{
			return true;
		}
		return false;

	}

	bool PlayerController::ProcessEnemyCollision(ICollider* _collider)
	{
		if (playerModel->IsShieldEnabled())
			return false;

		EnemyController* enemyController = dynamic_cast<EnemyController*>(_collider);

		if (enemyController)
		{
			/*ServiceLocator::GetInstance()->GetGameplayService()->Restart();*/
			DecreasePlayerLive();
			return true;
		}
		return false;
	}

	void PlayerController::UpdateFreezeDuration()
	{
		if(elapsed_freez_duration > 0)
		{
			elapsed_freez_duration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (elapsed_freez_duration <= 0) {
				playerModel->SetPlayerState(PlayerState::ALIVE);
				playerView->SetPlayerHighlight(false);

			}
		}
	}

	void PlayerController::FreezePlayer()
	{
		playerModel->SetPlayerState(PlayerState::FROZEN);
		elapsed_freez_duration = playerModel->freezeDuration;
		playerView->SetPlayerHighlight(true);
	}

	void PlayerController::UpdateFireDuration()
	{
		if (elapsed_fire_duration >= 0)
		{
			elapsed_fire_duration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		}
	}

	void PlayerController::ProcessBulletFire()
	{
		if (elapsed_fire_duration > 0) return;

		if (playerModel->IsTrippleLaserEnabled())
			FireBullet(true);

		else FireBullet();

		if (playerModel->IsRapidFireEnabled())
			elapsed_fire_duration = playerModel->rapidFireCooldownDuration;

		else elapsed_fire_duration = playerModel->fireCooldownDuration;
	}

	void PlayerController::FireBullet(bool _boolTrippleLaser)
	{
		sf::Vector2f bullet_position = playerModel->GetPlayerPosition() + playerModel->barrelpositionOffset;

		FireBullet(bullet_position);

		if (_boolTrippleLaser)
		{
			FireBullet(bullet_position + playerModel->secondWeaponPositionOffset);
			FireBullet(bullet_position + playerModel->thirdWeaponPositionOffset);
		}

		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BULLET_FIRE);
	}

	void PlayerController::FireBullet(sf::Vector2f _position)
	{
		ServiceLocator::GetInstance()->GetBulletService()
			->SpawnBullet(BulletType::LASER_BULLET,
				_position,
				Bullet::MovementDirection::UP,
				playerModel->GetEntityType());
	}

	void PlayerController::UpdatePowerupDuration()
	{
		if (elapsed_shield_duration > 0)
		{
			elapsed_shield_duration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (elapsed_shield_duration <= 0)
				DisableShield();
		}

		if (elapsed_rapid_fire_duration > 0)
		{
			elapsed_rapid_fire_duration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (elapsed_rapid_fire_duration <= 0)
				DisableRapidFire();
		}

		if (elapsed_tripple_laser_duration > 0)
		{
			elapsed_tripple_laser_duration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (elapsed_tripple_laser_duration <= 0)
				DisableTrippleLaser();
		}
	}

	void PlayerController::EnableShield()
	{
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::POWERUP_ENABLED);
		elapsed_shield_duration = playerModel->shiledPowerUpDuration;
		playerModel->SetShieldState(true);
		playerView->SetPlayerHighlight(true);
	}

	void PlayerController::DisableShield()
	{
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::POWERUP_DISABLED);
		playerView->SetPlayerHighlight(false);
		playerModel->SetShieldState(false);
	}

	void PlayerController::EnableRapidFire()
	{
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::POWERUP_ENABLED);
		elapsed_rapid_fire_duration = playerModel->rapidFirePowerUpDuration;
		playerModel->SetRapidFireState(true);
	}

	void PlayerController::DisableRapidFire()
	{
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::POWERUP_DISABLED);
		playerModel->SetRapidFireState(false);
	}

	void PlayerController::EnableTrippleLaser()
	{
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::POWERUP_ENABLED);
		elapsed_tripple_laser_duration = playerModel->trippleLaserPowerUpDuration;
		playerModel->SetTrippleFireState(true);
	}

	void PlayerController::DisableTrippleLaser()
	{
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::POWERUP_DISABLED);
		playerModel->SetTrippleFireState(false);
	}

	/*void PlayerController::FireBullet(){
		ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(BulletType::LASER_BULLET,
			playerModel->GetPlayerPosition() + playerModel->barrel_position_offset,
			Bullet::MovementDirection::UP);
	}*/


	void PlayerController::DecreasePlayerLive()
	{
		PlayerModel::player_lives -= 1;
		if (PlayerModel::player_lives <= 0)
		{
			Reset();
		}
	}

	Vector2f PlayerController::GetPlayerPosition() {

		return playerModel->GetPlayerPosition();
	}

	/*int PlayerController::GetPlayerScore()
	{
		return playerModel->GetPlayerScore();
	}*/

	PlayerState PlayerController::GetPlayerState()
	{
		return playerModel->GetPlayerState();
	}

	const sf::Sprite& PlayerController::GetColliderSprite()
	{
		return playerView->GetPlayerSprite();
	}

	void PlayerController::OnCollision(ICollider* _collider)
	{
		if (ProcessPowerupCollision(_collider))
			return;

		if (ProcessBulletCollision(_collider))
			return;

		ProcessEnemyCollision(_collider);
	}

}

