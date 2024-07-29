#include "../../Header/Player/PlayerService.h"
//#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"

namespace Player {
    PlayerService::PlayerService() {
        playerController = new PlayerController();
    }

    PlayerService::~PlayerService() {
        delete(playerController);
    }

    void PlayerService::Initialize() {
        playerController->Initialize();
    }

    void PlayerService::Update() {
        //Detect the GameState then Update
        playerController->Update();
    }

    void PlayerService::Render() {
        //Detect the GameState then Render
        playerController->Render();
    }

    void PlayerService::EnableShield()
    {
        playerController -> EnableShield();
    }

    void PlayerService::EnableRapidFire()
    {
        playerController -> EnableRapidFire();
    }

    void PlayerService::EnableTrippleLaser()
    {
        playerController -> EnableTrippleLaser();
    }

    void PlayerService::Reset()
    {
        playerController->Reset();
    }

}

