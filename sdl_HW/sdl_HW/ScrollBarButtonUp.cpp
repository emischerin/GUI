#include "ScrollBarButtonUp.h"
#include "Scene.h"

ScrollBarButtonUp::ScrollBarButtonUp(Triangle::TriangleDirection dir, BaseScrollBar* parent)
	: ScrollBarButton(dir, parent)
{

}

void ScrollBarButtonUp::ReactToEvents()
{
	CollisionDetector cd;

	if (cd.MouseInControl(this)) {
		uint32_t event_t = _my_parent_window->GetCurrentEventType();

		if (event_t == SDL_MOUSEBUTTONDOWN) {
			Uint8 mouse_btn_code = _my_parent_window->GetCurrentEventPtr()->button.button;
			if (mouse_btn_code == 1) { /*Left mouse button*/
				ControlMsg m = { Scene::_SCROLL_UP,0 };
				RightScrollBar* parent = (RightScrollBar*)GetParentControl();
				parent->ControlMessagingFunction(&m);
			}
		}
	}
}
