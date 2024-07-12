#pragma once
#include <SFML/Graphics.hpp>
#include "../Header/ServiceLocator.h"

class GameService{
    private :
        ServiceLocator *serviceLocator;
        RenderWindow *gameWindow;

        void Initialize();
        void InitializeVariable();
        void Destory();

    public :
        GameService();
        ~GameService();

        void Ignite();
        void Update();
        void Render();
        bool IsRunning();
};