#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Event/EventService.h"
#include "../../header/Sound/SoundService.h"

namespace UI
{
    namespace UIElement
    {
        using namespace Event;
        using namespace Global;

        ButtonView::ButtonView() = default;

        ButtonView::~ButtonView() = default;

        void ButtonView::Initialize(sf::String title, sf::String texture_path, float button_width, float button_height, sf::Vector2f position)
        {
            ImageView::Initialize(texture_path, button_width, button_height, position);
            button_title = title;
        }

        void ButtonView::registerCallbackFuntion(CallbackFunction button_callback)
        {
            callback_function = button_callback;
        }

        void ButtonView::Update()
        {
            ImageView::Update();

            if (ui_state == UIState::VISIBLE)
            {
                handleButtonInteraction();
            }
        }

        void ButtonView::Render()
        {
            ImageView::Render();
        }

        void ButtonView::handleButtonInteraction()
        {
            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            if (clickedButton(&image_sprite, mouse_position))
            {
                if (callback_function) {
                    callback_function();
                }
            }
        }

        bool ButtonView::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            return ServiceLocator::GetInstance()->GetEventService()->PressedLeftMouseButton() &&
                button_sprite->getGlobalBounds().contains(mouse_position);
        }

        void ButtonView::printButtonClicked()
        {
            printf("Clicked %s\n", button_title.toAnsiString().c_str());
        }
    }
}
