#include "../../Header/Global/ServiceLocator.h"

namespace Global {

    using namespace Graphics;
    using namespace Time;
    using namespace Event;
    using namespace Player;
    using namespace UI;

    ServiceLocator::ServiceLocator() {
        graphicService = nullptr;
        eventService = nullptr;
        playerService = nullptr;
        timeService = nullptr;
        uiService = nullptr;
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
    }

    void ServiceLocator::ClearAllService() {
        delete(graphicService);
        delete(eventService);
        delete(playerService);
        delete(timeService);
        delete(uiService);
    }

    ServiceLocator* ServiceLocator::GetInstance() {
        static ServiceLocator instance;
        return &instance;
    }

    void ServiceLocator::Initialize() {
        graphicService->Initialize();
        eventService->Initialize();
        playerService->Initialize();
        timeService->Initialize();
        uiService->Initialize();
    }

    void ServiceLocator::Update() {
        graphicService->Update();
        eventService->Update();
        playerService->Update();
        timeService->Update();
        uiService->Update();
    }

    void ServiceLocator::Render() {
        graphicService->Render();
        uiService->Render();
        playerService->Render();
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
}
