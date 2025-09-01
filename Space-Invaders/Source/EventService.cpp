#include "../Header/EventService.h"
#include "../Header/ServiceLocator.h"

EventService::EventService(){
    gameWindow = nullptr;
}

EventService::~EventService() = default;

void EventService::Initialize(){
    gameWindow = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
}

void EventService::Update(){
}

void EventService::ProcessEvent(){
    if(IsGameWindowOpen()){ // M

        while(gameWindow->pollEvent(gameEvent)){ 

            if(HasQuitGame() || GameWindowWasClosed()){ // M || M

                gameWindow->close();
            }
        }
    }
}

bool EventService::IsKeyboardEvent(){
    return gameEvent.type == Event::KeyPressed;
    
}

bool EventService::PressedEscapeKey(){
    return gameEvent.key.code == Keyboard::Escape;
}

bool EventService::IsGameWindowOpen(){
    return gameWindow != nullptr;
}

bool EventService::HasQuitGame(){
    return (PressedEscapeKey && IsKeyboardEvent);
}

bool EventService::GameWindowWasClosed()
{
    return gameEvent.type == Event::Closed;
}

bool EventService::PressedLeftKey(){
    return gameEvent.key.code == Keyboard::Left;
}

bool EventService::PressedRightKey(){
    return gameEvent.key.code == Keyboard::Right;
}

