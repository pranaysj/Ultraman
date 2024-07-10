#pragma once

#include"../../Header/Bullet/BulletConfig.h"
#include"../../Header/Projectile/IProjectile.h"

namespace Bullet {
	class BulletModel;
	class BulletView;
	enum class BulletType;

	class BulletController : public Projectile::IProjectile {
    protected:
        BulletView* bulletView;
        BulletModel* bulletModel;

        void UpdateProjectilePosition() override;
        void MoveUp();
        void MoveDown();
        void HandleOutOfBounds();

    public:
        BulletController(BulletType _type);
        virtual ~BulletController() override;

        void Initialize(sf::Vector2f _position, Bullet::MovementDirection _direction) override;
        void Update() override;
        void Render() override;

        sf::Vector2f GetProjectilePosition() override;
        BulletType GetBulletType();
	};
}