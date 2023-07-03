#include "ScrollBar.h"
#include "ScrollBarButton.h"
#include "ScrollBarCaret.h"
#include "Scene.h"

ScrollBar::ScrollBar(Scene* scene,ScrollBarPosition position) : Control(scene)
{

}

void ScrollBar::ReactToEvents()
{

}
void ScrollBar::Draw()
{

}

ScrollBar::~ScrollBar()
{
	delete _left_up;
	delete _right_down;
	delete _caret;
}