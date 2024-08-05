#pragma once
#include<SFML/Graphics.hpp>
#include "../../Header/Animation/AnimationSystemConfig.h"
#include "../../Header/UI/UIElement/ImageView.h"

namespace Animation{
	class AnimationSystem {
	private:
		AnimationSystemConfig animationSystemConfig;

		sf::Vector2f animationPostion;
		UI::UIElement::ImageView* animationImage;

		void CreateUIElement();
		void InitializeImage();

		int currentFrame;
		sf::Clock clock;
		sf::Time frameTime;

	public:
		
		AnimationSystem(AnimationSystemConfig _config);
		~AnimationSystem();

		void Initialize(sf::Vector2f _position);
		void Update();
		void Render();

		void Destory();
	};
}