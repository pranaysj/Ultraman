
#include "../../Header/Main/GameService.h"

namespace Main{

    using namespace Global;

    GameState GameService::currentState = GameState::BOOT;

    void GameService::ShowMainMenu() {
        SetGameState(GameState::MAIN_MENU);
    }

    void GameService::Initialize() {
        serviceLocator->Initialize();
        InitializeVariable();
        ShowMainMenu();
    }

    void GameService::InitializeVariable() {
        gameWindow = serviceLocator->GetGraphicsService()->GetGameWindow();
    }

    void GameService::Destory() {

    }

    GameService::GameService() {
        serviceLocator = nullptr;
        gameWindow = nullptr;
    }

    GameService::~GameService() {
        Destory();
    }

    void GameService::Ignite() {
        serviceLocator = Global::ServiceLocator::GetInstance();
        Initialize();
    }

    void GameService::Update() {
        serviceLocator->GetEventService()->ProcessEvent();
        serviceLocator->Update();
    }

    void GameService::Render() {
        gameWindow->clear(serviceLocator->GetGraphicsService()->getColorWindow());
        serviceLocator->Render();
        gameWindow->display();
    }

    bool GameService::IsRunning() {
        return serviceLocator->GetGraphicsService()->isGameWindowOpen();
    }

    void GameService::SetGameState(GameState _state){
        currentState = _state;
    }

    GameState GameService::GetGameState()
    {
        return currentState;;
    }

}

