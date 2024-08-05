#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../Header/Animation/AnimationSystem.h"

namespace Animation
{
	enum class AnimationType
	{
		EXPLOSION,
	};

	class AnimationService
	{
	private:
		std::vector<AnimationSystem*> animationSystemList;
		std::vector<AnimationSystem*> flaggedanimationSystemlist;

		AnimationSystemConfig GetAnimationSystemConfig(AnimationType animation_type);
		void DestroyFlaggedAnimationSystem();
		void Destroy();

	public:
		AnimationService();
		virtual ~AnimationService();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		void SpawnAnimationSystem(sf::Vector2f position, AnimationType animation_type);
		void DestroyAnimationSystem(AnimationSystem* animation_system);
	};
}