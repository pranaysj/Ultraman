
#include "../../Header/UI/SplashScreen/SplashScreenUIController .h"
#include "../../header/Main/GameService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Global/Config.h"

namespace UI
{
    namespace SplashScreen
    {
        using namespace Main;
        using namespace Graphics;
        using namespace Global;
        using namespace UIElement;
        using namespace Sound;

        SplashScreenUIController::SplashScreenUIController()
        {
            outscalLogoView = new AnimatedImageView();
        }

        SplashScreenUIController::~SplashScreenUIController()
        {
            delete (outscalLogoView);
        }

        void SplashScreenUIController::Initialize()
        {
            InitializeOutscalLogo();
        }

        void SplashScreenUIController::Update()
        {
            outscalLogoView->Update();
        }

        void SplashScreenUIController::Render()
        {
            outscalLogoView->Render();
        }

        void SplashScreenUIController::InitializeOutscalLogo()
        {
            sf::Vector2f position = GetLogoPosition();
            outscalLogoView->Initialize(Config::outscal_logo_texture_path, logo_width, logo_height, position);
        }

        void SplashScreenUIController::FadeInAnimationCallback()
        {
            outscalLogoView->PlayAnimation(AnimationType::FADE_OUT, splash_screen_duration, std::bind(&SplashScreenUIController::FadeOutAnimationCallback, this));
        }

        void SplashScreenUIController::FadeOutAnimationCallback()
        {
            ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
            GameService::SetGameState(GameState::MAIN_MENU);
        }

        sf::Vector2f SplashScreenUIController::GetLogoPosition()
        {
            sf::RenderWindow* game_window = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();

            float x_position = (game_window->getSize().x - logo_width) / 2.0f;
            float y_position = (game_window->getSize().y - logo_height) / 2.0f;

            return sf::Vector2f(x_position, y_position);
        }

        void SplashScreenUIController::Show()
        {
            outscalLogoView->PlayAnimation(AnimationType::FADE_IN, splash_screen_duration, std::bind(&SplashScreenUIController::FadeInAnimationCallback, this));
        }
    }
}
