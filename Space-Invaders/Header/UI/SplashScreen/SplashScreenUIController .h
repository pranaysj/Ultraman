#pragma once
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ImageView.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float splash_screen_duration = 2.0f;
			float elapsed_duration = 0.0f;
			const float logo_width = 600.f;
			const float logo_height = 134.f;

			UIElement::ImageView* outscal_logo_view;

			void InitializeOutscalLogo();
			void UpdateTimer();
			void ShowMainMenu();
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
