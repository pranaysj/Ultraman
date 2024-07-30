#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet
{
	class BulletController;
	enum class BulletType;
	enum class MovementDirection;

	class BulletService
	{
	private:
		std::vector<Projectile::IProjectile*> flaggedBulletList;
		std::vector<Projectile::IProjectile*> bulletList;

		BulletController* CreateBullet(BulletType _type, Entity::EntityType _ownerType);

		bool IsValidBullet(int index_i, std::vector<Projectile::IProjectile*>& bullet_list);
		void DestroyFlaggedBullets();

		void Destroy();

	public:
		BulletService();
		virtual ~BulletService();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		BulletController* SpawnBullet(BulletType _type, sf::Vector2f _position, MovementDirection _direction, Entity::EntityType _ownerType);
		void DestroyBullet(BulletController* _controller);
	};
}
