#pragma
#include "../../Header/Powerups/PowerupView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include"../../Header/Powerups/PoweupController.h"
#include "../../Header/Powerups/PowerupConfig.h"

namespace Powerup
{
	using namespace Global;
	using namespace UI::UIElement;

	PowerupView::PowerupView() { CreateUIElements(); }

	PowerupView::~PowerupView() { delete(powerupImage); }
		

	void PowerupView::Initialize(PowerupController* controller)
	{
		powerupController = controller;
		InitializeImage();
	}


	void PowerupView::CreateUIElements()
	{
		powerupImage = new ImageView();
	}

	void PowerupView::InitializeImage()
	{
		powerupImage->Initialize(GetPowerupTexturePath(),
			powerupSpriteWidth,
			powerupSpriteHeight,
			powerupController->GetCollectiblePosition());
		
	}

	sf::String PowerupView::GetPowerupTexturePath()
	{
		switch (powerupController->GetPowerupType())
		{
		case::Powerup::PowerupType::SHIELD:
			return Config::shield_texture_path;

		case::Powerup::PowerupType::TRIPPLE_LASER:
			return Config::tripple_laser_texture_path;

		case::Powerup::PowerupType::RAPID_FIRE:
			return Config::rapid_fire_texture_path;

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return Config::outscal_bomb_texture_path;
		}
	}

	void PowerupView::Destroy()
	{
		delete(powerupImage);
	}

	void PowerupView::Update()
	{
		powerupImage->SetPosition(powerupController->GetCollectiblePosition());
		powerupImage->Update();
	}

	void PowerupView::Render()
	{
		powerupImage->Render();
	}

	const sf::Sprite& PowerupView::GetPowerupSprite()
	{
		return powerupImage->GetSprite();
	}
}
