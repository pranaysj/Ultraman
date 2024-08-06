
#include "../../Header/Main/GameService.h"
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/UI/UIService.h"

namespace Main{

    using namespace Global;
    using namespace Graphics;
    using namespace Event;
    using namespace UI;

    GameState GameService::currentState = GameState::BOOT;

    GameService::GameService() {
        serviceLocator = nullptr;
        //gameWindow = nullptr;
    }

    GameService::~GameService() {
        Destory();
    }



    void GameService::Ignite() {
        serviceLocator = Global::ServiceLocator::GetInstance();
        Initialize();
    }

    void GameService::Initialize() {
        serviceLocator->Initialize();
        InitializeVariable();
        ShowSplashScreen();
    }

    void GameService::InitializeVariable() {
        gameWindow = serviceLocator->GetGraphicsService()->GetGameWindow();
    }

    void GameService::ShowSplashScreen()
    {
        SetGameState(GameState::SPLASH_SCREEN);
        ServiceLocator::GetInstance()->GetUIService()->Showscreen();
    }

   /* void GameService::ShowMainMenu() {
        SetGameState(GameState::MAIN_MENU);
    }*/

    void GameService::Destory()
    {
        serviceLocator->DeleteServiceLocator();
    }

    void GameService::Update() {
        serviceLocator->GetEventService()->ProcessEvent();
        serviceLocator->Update();
    }

    void GameService::Render() {
        gameWindow->clear(Color(1, 116, 178, 255));
        serviceLocator->Render();
        gameWindow->display();
    }

    bool GameService::IsRunning() {
        return serviceLocator->GetGraphicsService()->IsGameWindowOpen();
    }

    void GameService::SetGameState(GameState _state){
        currentState = _state;
    }

    GameState GameService::GetGameState()
    {
        return currentState;;
    }

}

