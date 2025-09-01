#pragma once
#include<vector>

namespace Enemy {
	class EnemyController;
	enum class EnemyType;

	class EnemyService {
	private:

		std::vector<EnemyController*> enemyList;

		const float spawnInterval = 2.0f;
		float spwanTimer;

		void UpdateSpawnTimer();
		void ProcessEnemySpawn();

		EnemyType GetRandomEnemyType();
		EnemyController* CreateEnemy(EnemyType _enemyType);

		void Destory();
	public:
		EnemyService();
		virtual ~EnemyService();

		void Initialize();
		void Update();
		void Render();

		EnemyController* SpawnEnemy();
		void DestroyEnemy(EnemyController* enemy_controller);
	};
}