#pragma once
#include<vector>

namespace Collision {

	class ICollider;

	class CollisionService {
	private:
		std::vector<ICollider*> colliderList;

		void ProcessCollider();
		void DoCollison(int _indexI, int _indexJ);
		bool HasCollisionOccured(int _indexI, int _indexJ);
		bool AreActiveColliders(int _indexI, int _indexJ);

	public:
		CollisionService();
		~CollisionService();

		void Initialize();
		void Update();

		void AddCollider(ICollider* _collider);
		void RemoveCollider(ICollider* _collider);
	};
}