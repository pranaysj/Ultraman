#pragma once
namespace Enemy {
	enum class EnemyType {
		ZAPPER,
		SUBZERO,
		UFO,
		THUNDER_SNAKE,
	};

	enum class EnemyState {
		PATROLLING,
		ATTACK,
		DEAD,
	};

	enum class EnemyDirection {
		LEFT,
		RIGHT,
		DOWN,
	};
}