#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"

namespace Main {

    using namespace sf;
    //class ServiceLocator;
    

    class GameService {
    private:
        Global::ServiceLocator* serviceLocator;
        RenderWindow* gameWindow;

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
    };
}
