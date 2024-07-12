#include"Header/GameService.h"

int main() {

    GameService *gameService = new GameService();
    
    gameService->Ignite();
    
    while (gameService->IsRunning())
    {
        
        gameService->Update();
        gameService->Render();
    }
     
    return 0;
}