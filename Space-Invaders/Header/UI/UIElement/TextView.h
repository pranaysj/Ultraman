#pragma once
#include "../../header/UI/UIElement/UIView.h"

namespace UI
{
	namespace UIElement
	{
		enum class FontType
		{
			BUBBLE_BOBBLE,
			DS_DIGIB,
		};

		class TextView : public UIView
		{
		private:
			static const int defaultFontSize = 55;

			static sf::Font fontBubbleBobble;
			static sf::Font font_DS_DIGIB;

			sf::Text text;

			static void LoadFont();

			void SetFont(FontType font_type);
			void SetFontSize(int font_size);
			void SetTextPosition(sf::Vector2f position);
			void SetTextColor(sf::Color color);

		public:
			TextView();
			virtual ~TextView();

			static void InitializeTextView();

			virtual void Initialize(sf::String text_value, sf::Vector2f position, FontType font_type = FontType::BUBBLE_BOBBLE, int font_size = defaultFontSize, sf::Color color = sf::Color::White);
			virtual void Update() override;
			virtual void Render() override;

			void SetText(sf::String text_value);
			void SetTextCentreAligned();
		};
	}
}