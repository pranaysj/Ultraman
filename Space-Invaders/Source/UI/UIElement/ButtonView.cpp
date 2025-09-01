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
            buttonTitle = title;
        }

        void ButtonView::RegisterCallbackFuntion(CallbackFunction button_callback)
        {
            callbackFunction = button_callback;
        }

        void ButtonView::Update()
        {
            ImageView::Update();

            if (uiState == UIState::VISIBLE)
            {
                HandleButtonInteraction();
            }
        }

        void ButtonView::Render()
        {
            ImageView::Render();
        }

        void ButtonView::HandleButtonInteraction()
        {
            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));

            if (ClickedButton(&imageSprite, mouse_position))
            {
                if (callbackFunction) {
                    callbackFunction();
                }
            }
        }

        bool ButtonView::ClickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            return ServiceLocator::GetInstance()->GetEventService()->PressedLeftMouseButton() &&
                button_sprite->getGlobalBounds().contains(mouse_position);
        }

        void ButtonView::printButtonClicked()
        {
            printf("Clicked %s\n", buttonTitle.toAnsiString().c_str());
        }
    }
}
