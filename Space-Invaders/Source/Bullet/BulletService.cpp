#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/Controllers/FrostBulletController.h"
#include "../../Header/Bullet/Controllers/LaserBulletController.h"
#include "../../Header/Bullet/Controllers/TorpedoeController.h"
#include "../../Header/Collision/ICollider.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Bullet
{
	using namespace Controller;
	using namespace Projectile;
	using namespace Global;
	using namespace Collision;

	BulletService::BulletService() { }

	BulletService::~BulletService() { 
		Destroy(); 
	}

	void BulletService::Initialize() {
		bulletList.clear();
		flaggedBulletList.clear();
	}

	void BulletService::Update()
	{
		for (int i = 0; i < bulletList.size(); i++) {
			bulletList[i]->Update();
		}
		
		DestroyFlaggedBullets();
	}

	void BulletService::Render()
	{
		for (int i = 0; i < bulletList.size(); i++) {
			bulletList[i]->Render();
		}
	}

	BulletController* BulletService::CreateBullet(BulletType bullet_type, Entity::EntityType _ownerType)
	{
		switch (bullet_type)
		{
		case::Bullet::BulletType::LASER_BULLET:
			return new LaserBulletController(Bullet::BulletType::LASER_BULLET, _ownerType);

		case::Bullet::BulletType::FROST_BULLET:
			return new FrostBulletController(Bullet::BulletType::FROST_BULLET, _ownerType);

		case::Bullet::BulletType::TORPEDO:
			return new TorpedoController(Bullet::BulletType::TORPEDO, _ownerType);
		}
	}

	bool BulletService::IsValidBullet(int _index_i, std::vector<Projectile::IProjectile*>& bullet_list)
	{
		return _index_i >= 0 && _index_i < bullet_list.size() && bullet_list[_index_i] != nullptr;
	}

	void BulletService::DestroyFlaggedBullets()
	{
		for (int i = 0; i < flaggedBulletList.size(); i++)
		{
			if (!IsValidBullet(i, flaggedBulletList)) continue;

			ServiceLocator::GetInstance()->GetCollisionService()->RemoveCollider(dynamic_cast<ICollider*>(flaggedBulletList[i]));
			delete (flaggedBulletList[i]);
		}
		flaggedBulletList.clear();
	}

	void BulletService::Destroy()
	{
		for (int i = 0; i < bulletList.size(); i++) {
			if(!IsValidBullet(i, bulletList)) continue;

			ServiceLocator::GetInstance()->GetCollisionService()->RemoveCollider(dynamic_cast<ICollider*>(bulletList[i]));
			delete (bulletList[i]);
		}
		bulletList.clear();
	}

	BulletController* BulletService::SpawnBullet(BulletType bullet_type, sf::Vector2f position, MovementDirection direction, Entity::EntityType _ownerType)
	{
		BulletController* bullet_controller = CreateBullet(bullet_type, _ownerType);

		bullet_controller->Initialize(position, direction);

		ServiceLocator::GetInstance()->GetCollisionService()->AddCollider(dynamic_cast<ICollider*>(bullet_controller));
		bulletList.push_back(bullet_controller);

		return bullet_controller;
	}

	void BulletService::DestroyBullet(BulletController* bullet_controller)
	{
		//if (std::find(flaggedBulletList.begin(), flaggedBulletList.end(), bullet_controller) == flaggedBulletList.end())
		//{
		//	flaggedBulletList.push_back(bullet_controller);
		//	bulletList.erase(std::remove(bulletList.begin(), bulletList.end(), bullet_controller), bulletList.end());
		//}

		//bulletList.erase(std::remove(bulletList.begin(), bulletList.end(), bullet_controller), bulletList.end());
		//
		////delete(bullet_controller);

		dynamic_cast<ICollider*>(bullet_controller)->DisableCollision();
		flaggedBulletList.push_back(bullet_controller);
		bulletList.erase(std::remove(bulletList.begin(), bulletList.end(), bullet_controller), bulletList.end());
	}

	void BulletService::Reset()
	{
		Destroy();
	}
}