#include "../../header/UI/MainMenu/MainMenuUIController.h"
#include "../../header/Main/GameService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Global/Config.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Event/EventService.h"
#include <iostream>

namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;
        using namespace Sound;

        MainMenuUIController::MainMenuUIController()
        {
            CreateImage();
            CreateButtons();
        }

        MainMenuUIController::~MainMenuUIController()
        {
            Destroy();
        }

        void MainMenuUIController::Initialize()
        {
            InitializeBackgroundImage();
            InitializeButtons();
            RegisterButtonCallback();
        }

        void MainMenuUIController::CreateImage()
        {
            backgroundImage = new ImageView();
        }

        void MainMenuUIController::CreateButtons()
        {
            playButton = new ButtonView();
            instructionsButton = new ButtonView();
            quitButton = new ButtonView();
        }

        void MainMenuUIController::InitializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();

            backgroundImage->Initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            //backgroundImage->SetImageAlpha(backgroundAlpha);
        }

        void MainMenuUIController::InitializeButtons()
        {
            playButton->Initialize("Play Button", Config::play_button_texture_path, buttonWidth, buttonHeight, sf::Vector2f(0, playButton_Y_Position));
            instructionsButton->Initialize("Instructions Button", Config::instructions_button_texture_path, buttonWidth, buttonHeight, sf::Vector2f(0, instructionsButton_Y_Position));
            quitButton->Initialize("Quit Button", Config::quit_button_texture_path, buttonWidth, buttonHeight, sf::Vector2f(0, quit_Button_Y_Position));

            playButton->SetCentreAlinged();
            instructionsButton->SetCentreAlinged();
            quitButton->SetCentreAlinged();
        }

        void MainMenuUIController::RegisterButtonCallback()
        {
            playButton->RegisterCallbackFuntion(std::bind(&MainMenuUIController::PlayButtonCallback, this));
            instructionsButton->RegisterCallbackFuntion(std::bind(&MainMenuUIController::InstructionsButtonCallback, this));
            quitButton->RegisterCallbackFuntion(std::bind(&MainMenuUIController::QuitButtonCallback, this));
        }

        void MainMenuUIController::PlayButtonCallback()
        {
            ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
            GameService::SetGameState(GameState::GAMEPLAY);
        }

        void MainMenuUIController::InstructionsButtonCallback()
        {
            ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
        }

        void MainMenuUIController::QuitButtonCallback()
        {
            ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow()->close();
        }

        void MainMenuUIController::Update()
        {
            backgroundImage->Update();
            playButton->Update();
            instructionsButton->Update();
            quitButton->Update();
        }

        void MainMenuUIController::Render()
        {
            backgroundImage->Render();
            playButton->Render();
            instructionsButton->Render();
            quitButton->Render();
        }

        void MainMenuUIController::Show()
        {
            backgroundImage->Show();
            playButton->Show();
            instructionsButton->Show();
            quitButton->Show();

            ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();

            std::cout << "Image Draw" << std::endl;
        }

        void MainMenuUIController::Destroy()
        {
            delete (playButton);
            delete (instructionsButton);
            delete (quitButton);
            delete (backgroundImage);
        }
    }
}
