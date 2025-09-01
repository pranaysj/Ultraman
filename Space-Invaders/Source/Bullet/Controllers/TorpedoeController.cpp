#pragma once
#include "../../Header/Bullet/BulletModel.h"
#include"../../Header/Bullet/Controllers/TorpedoeController.h"

namespace Bullet
{
	namespace Controller
	{
		TorpedoController::TorpedoController(BulletType type) : BulletController(type) { }

		TorpedoController::~TorpedoController() { }

		void TorpedoController::Initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::Initialize(position, direction);
			bulletModel->SetMovementSpeed(torpedoMovementSpeed);
		}
	}
}
