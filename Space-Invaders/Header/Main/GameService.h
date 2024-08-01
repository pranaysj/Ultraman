#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"

namespace Main {

    using namespace sf;

    enum class GameState {
        BOOT,
        SPLASH_SCREEN,
        MAIN_MENU,
        INSTRUCTIONS,
        GAMEPLAY,
        CREDITS,
    };

    class GameService {
    private:
        static GameState currentState;

        Global::ServiceLocator* serviceLocator;
        RenderWindow* gameWindow;

        void Initialize();
        void InitializeVariable();
        void ShowSplashScreen();
        void Destory();

    public:
        GameService();
        virtual ~GameService();

        void Ignite();
        void Update();
        void Render();
        bool IsRunning();

        static void SetGameState(GameState _state);
        static GameState GetGameState();
    };
}
