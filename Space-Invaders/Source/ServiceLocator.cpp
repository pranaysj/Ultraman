#include "../Header/ServiceLocator.h"

ServiceLocator::ServiceLocator(){
    graphicService = nullptr;
    eventService = nullptr;
    playerService = nullptr;
    CreateService();
}

ServiceLocator::~ServiceLocator(){
    ClearAllService();
}

void ServiceLocator::CreateService(){
    graphicService = new GraphicService();
    eventService = new EventService();
    playerService = new PlayerService;
}

void ServiceLocator::ClearAllService(){
    delete(graphicService);
    delete(eventService);
    delete(playerService);
}

ServiceLocator *ServiceLocator::GetInstance(){
    ServiceLocator instance;
    return &instance;
}

void ServiceLocator::Initialize(){
    graphicService->Initialize();
    eventService->Initialize();
    playerService->Initialize();
}

void ServiceLocator::Update(){
    graphicService->Update();
    eventService->Update();
    playerService->Update();
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