#include "../../Header/UI/UIElement/AnimatedImageView.h"

namespace UI {
	namespace UIElement {
		AnimatedImageView::AnimatedImageView() = default;

		AnimatedImageView::~AnimatedImageView() = default;

		void AnimatedImageView::Initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position)
		{
			ImageView::Initialize(texture_path, image_width, image_height, position);
		}

		void AnimatedImageView::RegisterCallbackFuntion(CallbackFunction animation_end_callback)
		{
			callback_function = animation_end_callback;
		}

		void AnimatedImageView::Update()
		{
			ImageView::Update();

			if (uiState == UIState::VISIBLE) {
				UpdateElapsedDuration();
				HandleAnimationProgress();
				UpdateAnimation();
			}
		}

		void AnimatedImageView::Render()
		{
			ImageView::Render();
		}

		void AnimatedImageView::PlayAnimation(AnimationType type, float duration, CallbackFunction animation_end_callback)
		{
			ImageView::Show();
			Reset();
			SetAnimationType(type);
			SetAnimationDuration(duration);
			RegisterCallbackFuntion(animation_end_callback);
		}

		void AnimatedImageView::UpdateElapsedDuration()
		{
			float deltaTime = clock.restart().asSeconds();
			elapsed_duration += deltaTime;
		}

		void AnimatedImageView::HandleAnimationProgress()
		{
			if (elapsed_duration >= animation_duration && callback_function) {
				callback_function();
			}
		}

		void AnimatedImageView::UpdateAnimation()
		{
			switch (animation_type)
			{
			case AnimationType::FADE_IN:
				FadeIn();
				break;
			case AnimationType::FADE_OUT:
				FadeOut();
				break;
			}
		}

		void AnimatedImageView::SetAnimationDuration(float duration)
		{
			animation_duration = duration;
		}

		void AnimatedImageView::SetAnimationType(AnimationType type)
		{
			animation_type = type;
		}

		void AnimatedImageView::FadeIn()
		{
			float alpha = std::min(1.f, elapsed_duration/animation_duration);
			imageSprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
		}

		void AnimatedImageView::FadeOut()
		{
			float alpha = std::max(0.0f, 1.0f - (elapsed_duration / animation_duration));
			imageSprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
		}

		void AnimatedImageView::Reset()
		{
			animation_duration = default_animation_duration;
			animation_type = AnimationType::FADE_IN;
			clock.restart();
			elapsed_duration = 0.0f;
		}

	}
}