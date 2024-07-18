#pragma
#include "../../header/UI/UIElement/TextView.h"
#include "../../header/Global/Config.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Global;

		sf::Font TextView::fontBubbleBobble;
		sf::Font TextView::font_DS_DIGIB;

		TextView::TextView() = default;

		TextView::~TextView() = default;

		void TextView::Initialize(sf::String text_value, sf::Vector2f position, FontType font_type, int font_size, sf::Color color)
		{
			UIView::Initialize();

			SetText(text_value);
			SetTextPosition(position);
			SetFont(font_type);
			SetFontSize(font_size);
			SetTextColor(color);
		}

		void TextView::Update()
		{
			UIView::Update();
		}

		void TextView::Render()
		{
			UIView::Render();

			if (uiState == UIState::VISIBLE)
			{
				gameWindow->draw(text);
			}
		}

		void TextView::InitializeTextView()
		{
			LoadFont();
		}

		void TextView::LoadFont()
		{
			fontBubbleBobble.loadFromFile(Config::bubble_bobble_font_path);
			font_DS_DIGIB.loadFromFile(Config::DS_DIGIB_font_path);
		}

		void TextView::SetText(sf::String text_value)
		{
			text.setString(text_value);
		}

		void TextView::SetFont(FontType font_type)
		{
			switch (font_type)
			{
			case FontType::BUBBLE_BOBBLE:
				text.setFont(fontBubbleBobble);
				break;
			case FontType::DS_DIGIB:
				text.setFont(font_DS_DIGIB);
				break;
			}
		}

		void TextView::SetFontSize(int font_size)
		{
			text.setCharacterSize(font_size);
		}

		void TextView::SetTextPosition(sf::Vector2f position)
		{
			text.setPosition(position);
		}

		void TextView::SetTextColor(sf::Color color)
		{
			text.setFillColor(color);
		}

		void TextView::SetTextCentreAligned()
		{
			float x_position = (gameWindow->getSize().x - text.getLocalBounds().width) / 2;
			float y_position = text.getGlobalBounds().getPosition().y;

			text.setPosition(sf::Vector2f(x_position, y_position));
		}
	}
}