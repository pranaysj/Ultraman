
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
            outscal_logo_view = new ImageView();
        }

        SplashScreenUIController::~SplashScreenUIController()
        {
            delete (outscal_logo_view);
        }

        void SplashScreenUIController::Initialize()
        {
            InitializeOutscalLogo();
        }

        void SplashScreenUIController::Update()
        {
            UpdateTimer();
            ShowMainMenu();
        }

        void SplashScreenUIController::Render()
        {
            outscal_logo_view->Render();
        }

        void SplashScreenUIController::InitializeOutscalLogo()
        {
            sf::Vector2f position = GetLogoPosition();
            outscal_logo_view->Initialize(Config::outscal_logo_texture_path, logo_width, logo_height, position);

        }

        void SplashScreenUIController::ShowMainMenu()
        {
            if (elapsed_duration >= splash_screen_duration)
            {
                ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
                GameService::SetGameState(GameState::MAIN_MENU);
            }

        }

        void SplashScreenUIController::UpdateTimer()
        {
            elapsed_duration += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
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

        }
    }
}
