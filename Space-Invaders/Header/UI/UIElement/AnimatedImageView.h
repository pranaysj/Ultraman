#pragma once
#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include <functional>

namespace UI
{
	namespace UIElement
	{
		enum class AnimationType
		{
			FADE_IN,
			FADE_OUT,
		};

		class AnimatedImageView : public ImageView
		{
		private:
			// Define a function pointer type for the callback function
			using CallbackFunction = std::function<void()>;

			// Store the callback function
			CallbackFunction callback_function = nullptr;

			void UpdateElapsedDuration();
			void HandleAnimationProgress();
			void UpdateAnimation();

		protected:
			const float default_animation_duration = 2.0f;

			AnimationType animation_type;
			float animation_duration;
			float elapsed_duration;
			sf::Clock clock;

			virtual void Reset();
			void SetAnimationDuration(float duration);
			void SetAnimationType(AnimationType type);

			virtual void FadeIn();
			virtual void FadeOut();

		public:
			AnimatedImageView();
			virtual ~AnimatedImageView();

			virtual void Initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position) override;
			virtual void Update() override;
			virtual void Render() override;

			virtual void PlayAnimation(AnimationType type, float duration, CallbackFunction animation_end_callback);

			void RegisterCallbackFuntion(CallbackFunction animation_end_callback);
		};
	}
}