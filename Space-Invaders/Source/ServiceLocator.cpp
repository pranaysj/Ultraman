#include "../Header/ServiceLocator.h"

ServiceLocator::ServiceLocator(){
    graphicService = nullptr;
    eventService = nullptr;
    playerService = nullptr;
    timeService = nullptr;
    CreateService();
}

ServiceLocator::~ServiceLocator(){
    ClearAllService();
}

void ServiceLocator::CreateService(){
    graphicService = new GraphicService();
    eventService = new EventService();
    playerService = new PlayerService();
    timeService = new TimeService();
}

void ServiceLocator::ClearAllService(){
    delete(graphicService);
    delete(eventService);
    delete(playerService);
    delete(timeService);
}

ServiceLocator *ServiceLocator::GetInstance(){
    static ServiceLocator instance;
    return &instance;
}

void ServiceLocator::Initialize(){
    graphicService->Initialize();
    eventService->Initialize();
    playerService->Initialize();
    timeService->Initialize();
}

void ServiceLocator::Update(){
    graphicService->Update();
    eventService->Update();
    playerService->Update();
    timeService->Update();
}

void ServiceLocator::Render(){
    graphicService->Render();
    playerService->Render();
}

GraphicService *ServiceLocator::GetGraphicsService(){
    return graphicService;
}

EventService *ServiceLocator::GetEventService(){
    return eventService;
}

PlayerService *ServiceLocator::GetPlayerService(){
    return playerService;
}

TimeService *ServiceLocator::GetTimeService(){
    return timeService;
}