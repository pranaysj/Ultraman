#include "../../Header/Animation/AnimationSystem.h"
#include "../../Header/Animation/AnimationService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace Animation {
	using namespace Global;
	using namespace UI::UIElement;


	AnimationSystem::AnimationSystem(AnimationSystemConfig _config)
	{
		animationSystemConfig = _config;
		CreateUIElement();
	}

	AnimationSystem::~AnimationSystem()
	{
		delete(animationImage);
	}

	void AnimationSystem::Initialize(sf::Vector2f _position)
	{
		animationPostion = _position;
		currentFrame = 0;
		frameTime = sf::seconds(animationSystemConfig.frameDuration);
		printf("%d\n", animationSystemConfig.frameDuration);
		InitializeImage();
	}

	void AnimationSystem::CreateUIElement()
	{
		animationImage = new ImageView();
	}

	void AnimationSystem::InitializeImage()
	{
		animationImage->Initialize(Config::explosion_texture_path, 0, 0, animationPostion);
		animationImage->SetTextureRect(sf::IntRect(0, 0, animationSystemConfig.tileWidth, animationSystemConfig.tileHeight));
		animationImage->SetScale(animationSystemConfig.spriteSheetWidth, animationSystemConfig.spriteSheetHeight, animationSystemConfig.tileWidth, animationSystemConfig.tileHeight);
	}

	void AnimationSystem::Update()
	{
		if (clock.getElapsedTime() >= frameTime)
		{
			if (currentFrame + 1 >= animationSystemConfig.numberOfAnimationFrames)
			{
				Destory();
			}

			currentFrame = (currentFrame + 1) % animationSystemConfig.numberOfAnimationFrames;
			clock.restart();

			animationImage->SetTextureRect(sf::IntRect(currentFrame * animationSystemConfig.tileWidth, 0, animationSystemConfig.tileWidth, animationSystemConfig.tileHeight));
		}
		animationImage->Update();
	}

	void AnimationSystem::Render()
	{
		animationImage->Render();
	}

	void AnimationSystem::Destory()
	{
		ServiceLocator::GetInstance()->GetAnimationService()->DestroyAnimationSystem(this);

	}
}
