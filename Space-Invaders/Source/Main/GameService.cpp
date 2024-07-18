
#include "../../Header/Main/GameService.h"
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Event/EventService.h"

namespace Main{

    using namespace Global;

    GameState GameService::currentState = GameState::BOOT;

    GameService::GameService() {
        serviceLocator = nullptr;
        gameWindow = nullptr;
    }

    GameService::~GameService() {
        Destory();
    }

    void GameService::Destory() {
        serviceLocator->DeleteServiceLocator();
    }

    void GameService::Ignite() {
        serviceLocator = Global::ServiceLocator::GetInstance();
        Initialize();
    }

    void GameService::Initialize() {
        serviceLocator->Initialize();
        InitializeVariable();
        ShowMainMenu();
    }

    void GameService::InitializeVariable() {
        gameWindow = serviceLocator->GetGraphicsService()->GetGameWindow();
    }

    void GameService::ShowMainMenu() {
        SetGameState(GameState::MAIN_MENU);
    }

    void GameService::Update() {
        serviceLocator->GetEventService()->ProcessEvent();
        serviceLocator->Update();
    }

    void GameService::Render() {
        gameWindow->clear(serviceLocator->GetGraphicsService()->GetColorWindow());
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

