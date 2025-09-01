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
			gameWindow = ServiceLocator::GetInstance()->GetGraphicsService()->GetGameWindow();
			uiState = UIState::VISIBLE;
		}

		void UIView::Update() { }

		void UIView::Render() { }

		void UIView::Show()
		{
			uiState = UIState::VISIBLE;
		}

		void UIView::Hide()
		{
			uiState = UIState::HIDDEN;
		}
	}
}