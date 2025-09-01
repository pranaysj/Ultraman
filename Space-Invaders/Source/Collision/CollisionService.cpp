#include "../../Header/Collision/CollisionService.h"
#include"../../Header/Collision/ICollider.h"


namespace Collision {
	CollisionService::CollisionService() { }

	CollisionService::~CollisionService() { }

	void CollisionService::Initialize() { }

	void CollisionService::Update()
	{
		ProcessCollider();
	}

	void CollisionService::ProcessCollider()
	{
		for (int i = 0; i < colliderList.size(); i++)
		{
			for (int j = i + 1; j < colliderList.size(); j++)
			{
				DoCollison(i,j);
			}
		}
	}

	void CollisionService::DoCollison(int _indexI, int _indexJ)
	{
		if (colliderList[_indexI]->GetCollisionState() == CollisionState::DISABLED ||
			colliderList[_indexJ]->GetCollisionState() == CollisionState::DISABLED) {
			return;
		}

		if (HasCollisionOccured(_indexI, _indexJ)) {

			if (AreActiveColliders(_indexI, _indexJ)) {
				colliderList[_indexI]->OnCollision(colliderList[_indexJ]);
			}
			if (AreActiveColliders(_indexI, _indexJ)) {
				colliderList[_indexJ]->OnCollision(colliderList[_indexI]);
			}
		}
	}

	bool CollisionService::HasCollisionOccured(int _indexI, int _indexJ)
	{
		const sf::Sprite& colliderOneSprite = colliderList[_indexI]->GetColliderSprite();
		const sf::Sprite& colliderTwoSprite = colliderList[_indexJ]->GetColliderSprite();

		return colliderOneSprite.getGlobalBounds().intersects(colliderTwoSprite.getGlobalBounds());
	}

	bool CollisionService::AreActiveColliders(int _indexI, int _indexJ)
	{
		return (_indexI < colliderList.size() && _indexJ < colliderList.size() && colliderList[_indexI] != nullptr && colliderList[_indexJ] != nullptr);
	}


	void CollisionService::AddCollider(ICollider* _collider)
	{
		colliderList.push_back(_collider);
	}

	void CollisionService::RemoveCollider(ICollider* _collider)
	{
		colliderList.erase(std::remove(colliderList.begin(), colliderList.end(), _collider), colliderList.end());
	}

}
