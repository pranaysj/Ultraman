#include "../../Header/Player/PlayerController.h"
#include"../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Powerups/PoweupController.h"
#include "../../Header/Enemy/EnemyController.h"


namespace Player {
	using namespace Global;
	using namespace Event;
	using namespace Bullet;
	using namespace Enemy;
	using namespace Powerup;


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
				playerModel->SetPlayerState(PlayerState::FROZEN);
				playerModel->elapsedFreezeDuration = playerModel->freezeDuration;
			}
			else ServiceLocator::GetInstance()->GetGameplayService()->Restart();
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
			ServiceLocator::GetInstance()->GetGameplayService()->Restart();
			return true;
		}
		return false;
	}

	void PlayerController::UpdateFreezeDuration()
	{
		if(playerModel->elapsedFreezeDuration > 0)
		{
			playerModel->elapsedFreezeDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (playerModel->elapsedFreezeDuration <= 0)
				playerModel->SetPlayerState(PlayerState::ALIVE);
		}
	}

	void PlayerController::FreezePlayer()
	{
	}

	void PlayerController::UpdateFireDuration()
	{
		if (playerModel->elapsedFireDuration >= 0)
		{
			playerModel->elapsedFireDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		}
	}

	void PlayerController::ProcessBulletFire()
	{
		if (playerModel->elapsedFireDuration > 0) return;

		if (playerModel->IsTrippleLaserEnabled())
			FireBullet(true);

		else FireBullet();

		if (playerModel->IsRapidFireEnabled())
			playerModel->elapsedFireDuration = playerModel->rapidFireCooldownDuration;

		else playerModel->elapsedFireDuration = playerModel->fireCooldownDuration;
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
		if (playerModel->elapsedShieldDuration > 0)
		{
			playerModel->elapsedShieldDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (playerModel->elapsedShieldDuration <= 0)
				DisableShield();
		}

		if (playerModel->elapsedRapidFireDuration > 0)
		{
			playerModel->elapsedRapidFireDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (playerModel->elapsedRapidFireDuration <= 0)
				DisableRapidFire();
		}

		if (playerModel->elapsedTrippleLaserDuration > 0)
		{
			playerModel->elapsedTrippleLaserDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (playerModel->elapsedTrippleLaserDuration <= 0)
				DisableTrippleLaser();
		}
	}

	void PlayerController::DisableShield()
	{
		playerModel->SetShieldState(false);
	}

	void PlayerController::DisableRapidFire()
	{
		playerModel->SetRapidFireState(false);
	}

	void PlayerController::DisableTrippleLaser()
	{
		playerModel->SetTrippleFireState(false);
	}

	/*void PlayerController::FireBullet(){
		ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(BulletType::LASER_BULLET,
			playerModel->GetPlayerPosition() + playerModel->barrel_position_offset,
			Bullet::MovementDirection::UP);
	}*/


	void PlayerController::Reset()
	{
		playerModel->Reset();
	}

	void PlayerController::EnableShield()
	{
		playerModel->elapsedShieldDuration = playerModel->shiledPowerUpDuration;
		playerModel->SetShieldState(true);
	}

	void PlayerController::EnableRapidFire()
	{
		playerModel->elapsedRapidFireDuration = playerModel->rapidFirePowerUpDuration;
		playerModel->SetRapidFireState(true);
	}

	void PlayerController::EnableTrippleLaser()
	{
		playerModel->elapsedTrippleLaserDuration = playerModel->trippleLaserPowerUpDuration;
		playerModel->SetTrippleFireState(true);
	}

	Vector2f PlayerController::GetPlayerPosition() {

		return playerModel->GetPlayerPosition();
	}

	int PlayerController::GetPlayerScore()
	{
		return playerModel->GetPlayerScore();
	}

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

