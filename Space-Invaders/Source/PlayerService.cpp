#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"

PlayerService::PlayerService(){
    gameWindow = nullptr;
}

PlayerService::~PlayerService() = default;

void PlayerService::Initialize(){
    gameWindow = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
    InitiallayerSprite();
}

void PlayerService::Update(){
    ProcessPlayerInput();
    playerSprite.setPosition(GetPosition());
}

void PlayerService::Render(){
    gameWindow->draw(playerSprite);
}

void PlayerService::InitiallayerSprite(){
    if(playerTexture.loadFromFile(playerTexturePath)){
        playerSprite.setTexture(playerTexture);
    }
}

void PlayerService::ProcessPlayerInput(){

    EventService *eventService = ServiceLocator::GetInstance()->GetEventService();
    
    if (eventService->IsKeyboardEvent()) {
        if (eventService->PressedLeftKey()) {
            MoveLeft();
        }
        if (eventService->PressedRightKey()) {
            MoveRight();
        }
    }
}


void PlayerService::MoveLeft(){
    position.x -= movementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
}

void PlayerService::MoveRight(){
    position.x += movementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
}

Vector2f PlayerService::GetPosition(){
    return position;
}
