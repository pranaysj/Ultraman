#pragma once
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/AnimatedImageView.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float splash_screen_duration = 2.0f;
			const float logo_width = 600.f;
			const float logo_height = 134.f;

			UIElement::AnimatedImageView* outscalLogoView;

			void InitializeOutscalLogo();
			void FadeInAnimationCallback();
			void FadeOutAnimationCallback();
			sf::Vector2f GetLogoPosition();

		public:

			SplashScreenUIController();
			~SplashScreenUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;
			void Show() override;
		};
	}
}
