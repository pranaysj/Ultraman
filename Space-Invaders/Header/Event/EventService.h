#pragma once
#include<SFML/Graphics.hpp>

namespace Event{
    enum class ButtonState
    {
        PRESSED,
        HELD,
        RELEASED,
    };
    class EventService{
        private :
            ButtonState leftMouseButtonState;
            ButtonState rightMouseButtonState;
            ButtonState leftArrowButtonState;
            ButtonState rightArrowButtonState;
            ButtonState AButtonState;
            ButtonState DButtonState;

            sf::Event gameEvent;
            sf::RenderWindow *gameWindow;
            bool IsGameWindowOpen();
            bool HasQuitGame();
            bool GameWindowWasClosed();

            void UpdateMouseButtonsState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton);
            void UpdateKeyboardButtonsState(ButtonState& currentButtonState, sf::Keyboard::Key keyboardButton);
        
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

            bool PressedLeftMouseButton();
            bool PressedRightMouseButton();

            bool PressedAKey();
            bool PressedDKey();


    };

}