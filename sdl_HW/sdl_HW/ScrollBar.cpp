#include "ScrollBar.h"
#include "ScrollBarButton.h"
#include "ScrollBarCaret.h"
#include "Scene.h"

ScrollBar::ScrollBar(Scene* scene,ScrollBarPosition position) : Control(scene)
{
	_left_up = new ScrollBarButton(Triangle::TriangleDirection::UP, this);
	_right_down = new ScrollBarButton(Triangle::TriangleDirection::DOWN, this);
	_caret = new ScrollBarCaret(this);



}

void ScrollBar::SetWidthAndHeight(int width, int height)
{
	Control::SetWidthAndHeight(width, height);
	_left_up->SetWidthAndHeight(width, width);
	_right_down->SetWidthAndHeight(width, width);


}

void ScrollBar::SetPosition(int x, int y)
{
	Control::SetPosition(x, y);

	_left_up->SetPosition(x, y);

	_right_down->SetPosition(this->GetX(), (this->GetY() + this->GetHeight()) - 20);
}

void ScrollBar::ReactToEvents()
{

}
void ScrollBar::Draw()
{
	SDL_SetRenderDrawColor(_render, 0, 0, 0, 0);
	SDL_RenderFillRect(_render, &_bounding_rect);

	Control::Draw();

	
}

ScrollBar::~ScrollBar()
{
	
}