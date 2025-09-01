#pragma once
#include"../../Header/Bullet/BulletController.h"

namespace Bullet {

	enum class BulletType;

	namespace Controller {
		class FrostBulletController : public BulletController {
		private:
			const float frostMovementSpeed = 500.0f;



		public:
			FrostBulletController(BulletType _type);
			~FrostBulletController();

			void Initialize(sf::Vector2f _position, MovementDirection _direction) override;
		};
	}
}