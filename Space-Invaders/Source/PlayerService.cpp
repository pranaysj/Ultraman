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

    if(eventService->PressedLeftKey()){
        Move(-1.0 * GetMovementSpeed());
    }
    if(eventService->PressedRightKey()){
        Move(1.0 * GetMovementSpeed());
    }
}

void PlayerService::Move(float offset){
    position.x += offset;
}

int PlayerService::GetMovementSpeed(){
    return movement_speed;
}

Vector2f PlayerService::GetPosition(){
    return position;
}
