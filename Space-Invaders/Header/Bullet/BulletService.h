#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "../../Header/Projectile/IProjectile.h"

namespace Bullet
{
	class BulletController;
	enum class BulletType;
	enum class MovementDirection;

	class BulletService
	{
	private:
		std::vector<Projectile::IProjectile*> bulletList;

		BulletController* CreateBullet(BulletType _type, Entity::EntityType _ownerType);
		void Destroy();

	public:
		BulletService();
		virtual ~BulletService();

		void Initialize();
		void Update();
		void Render();

		BulletController* SpawnBullet(BulletType _type, sf::Vector2f _position, MovementDirection _direction, Entity::EntityType _ownerType);
		void DestroyBullet(BulletController* _controller);
	};
}
