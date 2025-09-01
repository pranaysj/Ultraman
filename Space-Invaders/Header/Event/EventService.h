#pragma once
#include<SFML/Graphics.hpp>

namespace Event{
    using namespace sf;
    class EventService{
        private :
            sf::Event gameEvent;
            sf::RenderWindow *gameWindow;
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

}