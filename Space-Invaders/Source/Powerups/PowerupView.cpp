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
		//game_window = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
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
		/*switch (type)
		{
		case::Powerup::PowerupType::TRIPPLE_LASER:
			if (powerup_texture.loadFromFile(Config::tripple_laser_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleImage();
			}
			break;
		case::Powerup::PowerupType::SHIELD:
			if (powerup_texture.loadFromFile(Config::shield_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleImage();
			}
			break;
		case::Powerup::PowerupType::RAPID_FIRE:
			if (powerup_texture.loadFromFile(Config::rapid_fire_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleImage();
			}
			break;
		case::Powerup::PowerupType::OUTSCAL_BOMB:
			if (powerup_texture.loadFromFile(Config::outscal_bomb_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleImage();
			}
			break;
		}*/
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

	/*void PowerupView::scaleImage()
	{
		powerup_sprite.setScale(
			static_cast<float>(powerup_sprite_width) / powerup_sprite.getTexture()->getSize().x,
			static_cast<float>(powerup_sprite_height) / powerup_sprite.getTexture()->getSize().y
		);
	}*/

	void PowerupView::update()
	{
		powerup_sprite.setPosition(powerup_controller->GetCollectiblePosition());
		powerup_image->Update();
	}

	void PowerupView::render()
	{
		//game_window->draw(powerup_sprite);
		powerup_image->Render();
	}
}
