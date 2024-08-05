#include "../../header/Animation/AnimationService.h"
#include "../../header/Animation/AnimationSystemConfigData.h"

namespace Animation
{
	AnimationService::AnimationService() { }

	AnimationService::~AnimationService() { Destroy(); }

	void AnimationService::Initialize() { }

	void AnimationService::Update()
	{
		for (AnimationSystem* animation_system : animationSystemList)
			animation_system->Update();

		DestroyFlaggedAnimationSystem();
	}

	void AnimationService::Render()
	{
		for (AnimationSystem* animation_system : animationSystemList)
			animation_system->Render();
	}

	void AnimationService::SpawnAnimationSystem(sf::Vector2f position, AnimationType animation_type)
	{
		AnimationSystem* animation_system = new AnimationSystem(GetAnimationSystemConfig(animation_type));
		animation_system->Initialize(position);
		animationSystemList.push_back(animation_system);
	}

	void AnimationService::DestroyAnimationSystem(AnimationSystem* animation_system)
	{
		flaggedanimationSystemlist.push_back(animation_system);
		animationSystemList.erase(std::remove(animationSystemList.begin(), animationSystemList.end(), animation_system), animationSystemList.end());
	}

	AnimationSystemConfig AnimationService::GetAnimationSystemConfig(AnimationType animation_type)
	{
		switch (animation_type)
		{
		case Animation::AnimationType::EXPLOSION:
			return explosionAnimationConfig;
		}
	}

	void AnimationService::DestroyFlaggedAnimationSystem()
	{
		for (AnimationSystem* particle_system : flaggedanimationSystemlist)
			delete (particle_system);

		flaggedanimationSystemlist.clear();
	}

	void AnimationService::Reset() { Destroy(); }

	void AnimationService::Destroy()
	{
		for (AnimationSystem* animation_system : animationSystemList)
			delete (animation_system);
	}
}