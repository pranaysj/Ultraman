#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class EventService{
    private :
        RenderWindow *gameWindow;
        Event gameEvent;
        bool IsGameWindowOpen();
        bool HasQuitGame();
        bool GameWindowWasClosed();
        
    public :
        EventService();
        ~EventService();

        void Initialize();
        void Update();
        void ProcessEvent();
        bool PressedEscapeKey();
        bool IsKeyboardEvent();

        bool PressedLeftKey();
        bool PressedRightKey();

};