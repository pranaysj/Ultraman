#pragma once
#include<vector>

namespace Enemy {
	class EnemyController;
	enum class EnemyType;

	class EnemyService {
	private:
		std::vector<EnemyController*> enemyList;
		std::vector<EnemyController*> flaggedEnemyList;

		const float spawnInterval = 3.0f;
		float spwanTimer;

		void UpdateSpawnTimer();
		void ProcessEnemySpawn();

		EnemyType GetRandomEnemyType();
		EnemyController* CreateEnemy(EnemyType _enemyType);

		void DestroyFlaggedEnemies();
		void Destory();
	public:
		EnemyService();
		virtual ~EnemyService();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		EnemyController* SpawnEnemy();
		void DestroyEnemy(EnemyController* enemy_controller);
	};
}