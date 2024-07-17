#pragma
#include "../../header/UI/UIElement/UIView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicService.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Global;
		using namespace Graphics;

		UIView::UIView() = default;

		UIView::~UIView() = default;

		void UIView::Initialize()
		{
			game_window = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
			ui_state = UIState::VISIBLE;
		}

		void UIView::Update() { }

		void UIView::Render() { }

		void UIView::Show()
		{
			ui_state = UIState::VISIBLE;
		}

		void UIView::Hide()
		{
			ui_state = UIState::HIDDEN;
		}
	}
}