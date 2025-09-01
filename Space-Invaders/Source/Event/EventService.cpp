#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Event {

    using namespace Global;
    using namespace sf;

    EventService::EventService() {
        gameWindow = nullptr;
    }

    EventService::~EventService() = default;

    void EventService::Initialize() {
        gameWindow = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
    }

    void EventService::Update() {
        UpdateMouseButtonsState(leftMouseButtonState, sf::Mouse::Left);
        UpdateMouseButtonsState(rightMouseButtonState, sf::Mouse::Right);
        UpdateKeyboardButtonsState(leftArrowButtonState, sf::Keyboard::Left);
        UpdateKeyboardButtonsState(rightArrowButtonState, sf::Keyboard::Right);
        UpdateKeyboardButtonsState(AButtonState, sf::Keyboard::A);
        UpdateKeyboardButtonsState(DButtonState, sf::Keyboard::D);
    }

    void EventService::ProcessEvent() {
        if (IsGameWindowOpen()) {

            while (gameWindow->pollEvent(gameEvent)) {

                if (HasQuitGame() || GameWindowWasClosed()) {

                    gameWindow->close();
                }
            }
        }
    }

    bool EventService::IsKeyboardEvent() {
        return gameEvent.type == sf::Event::KeyPressed;

    }

    bool EventService::PressedEscapeKey() {
        return gameEvent.key.code == Keyboard::Escape;
    }

    bool EventService::IsGameWindowOpen() {
        return gameWindow != nullptr;
    }

    bool EventService::HasQuitGame() {
        return (PressedEscapeKey() && IsKeyboardEvent());
    }

    bool EventService::GameWindowWasClosed()
    {
        return gameEvent.type == sf::Event::Closed;
    }

    void EventService::UpdateMouseButtonsState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton){
        if (sf::Mouse::isButtonPressed(mouseButton)) {
            switch (currentButtonState)
            {
            case ButtonState::RELEASED:
                currentButtonState = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                currentButtonState = ButtonState::HELD;
                break;
            }
        }
        else {
            currentButtonState = ButtonState::RELEASED;
        }
    }

    void EventService::UpdateKeyboardButtonsState(ButtonState& currentButtonState, sf::Keyboard::Key keyboardButton) {
        if (sf::Keyboard::isKeyPressed(keyboardButton)) {
            switch (currentButtonState)
            {
            case ButtonState::RELEASED:
                currentButtonState = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                currentButtonState = ButtonState::HELD;
                break;
            }
        }
        else {
            currentButtonState = ButtonState::RELEASED;
        }
    }

    bool EventService::PressedLeftKey() {
        //return gameEvent.key.code == Keyboard::Left;
        return leftArrowButtonState == ButtonState::HELD;
    }

    bool EventService::PressedRightKey() {
        //return gameEvent.key.code == Keyboard::Right;
        return rightArrowButtonState == ButtonState::HELD;
    }

    bool EventService::PressedLeftMouseButton() {
        //return gameEvent.type == sf::Event::MouseButtonPressed && gameEvent.mouseButton.button == sf::Mouse::Left;
        return leftMouseButtonState == ButtonState::PRESSED;
    }

    bool EventService::PressedRightMouseButton() {
        //return gameEvent.type == sf::Event::MouseButtonPressed && gameEvent.mouseButton.button == sf::Mouse::Right;
        return rightMouseButtonState == ButtonState::PRESSED;
    }

    bool EventService::PressedAKey()
    {
        return AButtonState == ButtonState::HELD;;
    }

    bool EventService::PressedDKey()
    {
        return DButtonState == ButtonState::HELD;;
    }

}
