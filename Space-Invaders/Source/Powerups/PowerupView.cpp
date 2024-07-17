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

	PowerupView::PowerupView() { createUIElements(); }

	PowerupView::~PowerupView() { destroy(); }

	void PowerupView::initialize(PowerupController* controller)
	{
		powerup_controller = controller;
		initializeImage();
	}


	void PowerupView::createUIElements()
	{
		powerup_image = new ImageView();
	}

	void PowerupView::initializeImage()
	{
		powerup_image->Initialize(getPowerupTexturePath(),
			powerup_sprite_width,
			powerup_sprite_height,
			powerup_controller->GetCollectiblePosition());
		
	}

	sf::String PowerupView::getPowerupTexturePath()
	{
		switch (powerup_controller->GetPowerupType())
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

	void PowerupView::destroy()
	{
		delete(powerup_image);
	}

	void PowerupView::update()
	{
		powerup_sprite.setPosition(powerup_controller->GetCollectiblePosition());
		powerup_image->Update();
	}

	void PowerupView::render()
	{
		powerup_image->Render();
	}
}
