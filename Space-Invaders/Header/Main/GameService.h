#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"

namespace Main {

    using namespace sf;

    enum class GameState {
        BOOT,
        MAIN_MENU,
        GAMEPLAY
    };

    class GameService {
    private:
        static GameState currentState;

        Global::ServiceLocator* serviceLocator;
        RenderWindow* gameWindow;

        void ShowMainMenu();

        void Initialize();
        void InitializeVariable();
        void Destory();

    public:
        GameService();
        ~GameService();

        void Ignite();
        void Update();
        void Render();
        bool IsRunning();

        static void SetGameState(GameState _state);
        static GameState GetGameState();
    };
}
