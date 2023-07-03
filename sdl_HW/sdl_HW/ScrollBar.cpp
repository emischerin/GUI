#include "ScrollBar.h"
#include "ScrollBarButton.h"
#include "ScrollBarCaret.h"
#include "Scene.h"

ScrollBar::ScrollBar(Scene* scene,ScrollBarPosition position) : Control(scene)
{
	_left_up = new ScrollBarButton(Triangle::TriangleDirection::UP, this);
	_right_down = new ScrollBarButton(Triangle::TriangleDirection::DOWN, this);
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