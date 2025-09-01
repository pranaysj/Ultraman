#pragma once
#include"../../Header/Bullet/BulletConfig.h"
#include"../../Header/Projectile/IProjectile.h"
#include"../../Header/Entity/EntityConfig.h"
#include"../../Header/Collision/ICollider.h"

namespace Bullet {
	class BulletModel;
	class BulletView;
	enum class BulletType;

    class BulletController : public Projectile::IProjectile, public Collision::ICollider {
    protected:
        BulletView* bulletView;
        BulletModel* bulletModel;

        void UpdateProjectilePosition() override;

        void ProcessBulletCollision(ICollider* other_collider);
        void ProcessEnemyCollision(ICollider* other_collider);
        void ProcessPlayerCollision(ICollider* other_collider);
        void ProcessBunkerCollision(ICollider* other_collider);

        void MoveUp();
        void MoveDown();
        void HandleOutOfBounds();

    public:
        BulletController(BulletType _type, Entity::EntityType _ownerType);
        virtual ~BulletController() override;

        void Initialize(sf::Vector2f _position, Bullet::MovementDirection _direction) override;
        void Update() override;
        void Render() override;

        sf::Vector2f GetProjectilePosition() override;
        BulletType GetBulletType();
        Entity::EntityType GetOwnerEntityType();

        const sf::Sprite& GetColliderSprite() override;
        void OnCollision(ICollider* other_collider) override;
	};
}