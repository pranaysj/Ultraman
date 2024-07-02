#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace Global {

    using namespace Main;
    using namespace Graphics;
    using namespace Time;
    using namespace Event;
    using namespace Player;
    using namespace UI;
    using namespace Enemy;
    using namespace Gameplay;

    ServiceLocator::ServiceLocator() {
        graphicService = nullptr;
        eventService = nullptr;
        playerService = nullptr;
        timeService = nullptr;
        uiService = nullptr;
        enemyService = nullptr;
        gameplayService = nullptr;
        CreateService();
    }

    ServiceLocator::~ServiceLocator() {
        ClearAllService();
    }

    void ServiceLocator::CreateService() {
        graphicService = new GraphicService();
        eventService = new EventService();
        playerService = new PlayerService();
        timeService = new TimeService();
        uiService = new UIService();
        enemyService = new EnemyService();
        gameplayService = new GameplayService();
    }

    void ServiceLocator::ClearAllService() {
        delete(graphicService);
        delete(eventService);
        delete(playerService);
        delete(timeService);
        delete(uiService);
        delete(enemyService);
        delete(gameplayService);
    }

    ServiceLocator* ServiceLocator::GetInstance() {
        static ServiceLocator instance;
        return &instance;
    }

    void ServiceLocator::Initialize() {
        graphicService->Initialize();
        timeService->Initialize();
        eventService->Initialize();
        gameplayService->Initialize();
        playerService->Initialize();
        enemyService->Initialize();
        uiService->Initialize();
    }

    void ServiceLocator::Update() {
        graphicService->Update();
        timeService->Update();
        eventService->Update();

        if (GameService::GetGameState() == GameState::GAMEPLAY) {
            gameplayService->Update();
            playerService->Update();
            enemyService->Update();
        }

        uiService->Update();
    }

    void ServiceLocator::Render() {
        graphicService->Render();

        if (GameService::GetGameState() == GameState::GAMEPLAY) {
            gameplayService->Render();
            playerService->Render();
            enemyService->Render();
        }

        uiService->Render();
    }

    GraphicService* ServiceLocator::GetGraphicsService() {
        return graphicService;
    }

    EventService* ServiceLocator::GetEventService() {
        return eventService;
    }

    PlayerService* ServiceLocator::GetPlayerService() {
        return playerService;
    }

    TimeService* ServiceLocator::GetTimeService() {
        return timeService;
    }

    UIService* ServiceLocator::GetUIService() {
        return uiService;
    }
    Enemy::EnemyService* ServiceLocator::GetEnemyService()
    {
        return enemyService;
    }
    Gameplay::GameplayService* ServiceLocator::GetGameplayService()
    {
        return gameplayService;;
    }
    void ServiceLocator::DeleteServiceLocator(){
        delete(this);
    }
}
