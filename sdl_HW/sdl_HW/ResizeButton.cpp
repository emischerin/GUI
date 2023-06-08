#include "ResizeButton.h"
#include "MainWindow.h"

ResizeButton::ResizeButton()
{
	_color.r = 146;
	_color.g = 7;
	_color.b = 173;
	_color.a = 1;

	
	this->SetWidthAndHeight(20, 20);
}

ResizeButton::ResizeButton(Control* parent) : Control(parent)
{
	_color.r = 146;
	_color.g = 7;
	_color.b = 173;
	_color.a = 1;


	
}

void ResizeButton::ReactToEvents()
{
	SDL_Event* ev = AppGlobals::event;
	if (!ev) return;

	CollisionDetector cd;

	if (cd.MouseInWindow(AppGlobals::main_window) && cd.MouseInControl(this)) {
		

		if (ev->type == SDL_MOUSEBUTTONDOWN)
			if (ev->button.button == 1) { /*left mouse button*/
				MainWindow* w = AppGlobals::my_main_window;
				
				if (w->GetSizeState() == MainWindow::MAXIMIZED)
					w->SetSizeState(MainWindow::MY_SIZE);
				else if (w->GetSizeState() == MainWindow::MY_SIZE)
					w->SetSizeState(MainWindow::MAXIMIZED);
				
			}

		

		
	}

}

void ResizeButton::SetParentControl(Control* parent)
{
	this->_parent_control = parent;

	

	SDL_Rect* p_rect = _parent_control->GetBoundingRect();
	p_rect->w -= _bounding_rect.w;
}

void ResizeButton::Draw()
{
	CollisionDetector cd;



	if (cd.MouseInWindow(AppGlobals::main_window) && cd.MouseInControl(this)) {
		SDL_SetRenderDrawColor(AppGlobals::main_render, _mouse_over_r, _mouse_over_g, _mouse_over_b, _mouse_over_a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		
	}
	else {
		SDL_Color* parent_color = _parent_control->GetColor();

		SDL_SetRenderDrawColor(AppGlobals::main_render, parent_color->r, parent_color->g, parent_color->b, parent_color->a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);

	}

	MainWindow* w = AppGlobals::my_main_window;

	if (w->GetSizeState() == MainWindow::WindowSizeState::MY_SIZE)
		this->DrawMaximizeButton();
	else if (w->GetSizeState() == MainWindow::WindowSizeState::MAXIMIZED)
		this->DrawSetMySizeButton();

	
}

void ResizeButton::DrawMaximizeButton()
{
	SDL_Rect r;
	r.x = GetX() + 10;
	r.y = GetY() + 10;
	r.w = 15;
	r.h = 15;

	SDL_SetRenderDrawColor(AppGlobals::main_render, 255, 255, 255, 1);
	SDL_RenderDrawRect(AppGlobals::main_render, &r);
	SDL_RenderDrawLine(AppGlobals::main_render, r.x, r.y + 1, r.x + r.w - 1, r.y + 1);
}

void ResizeButton::DrawSetMySizeButton()
{
	SDL_Rect r;
	r.x = GetX() + 12;
	r.y = GetY() + 12;
	r.w = 10;
	r.h = 10;

	SDL_SetRenderDrawColor(AppGlobals::main_render, 255, 255, 255, 1);
	SDL_RenderDrawRect(AppGlobals::main_render, &r);

	r.x -= 2;
	r.y += 2;

	SDL_RenderDrawRect(AppGlobals::main_render, &r);

	SDL_Color* _parent_color = _parent_control->GetColor();

	r.x += 1;
	r.y += 1;
	r.w -= 2;
	r.h -= 2;
	SDL_SetRenderDrawColor(AppGlobals::main_render, _parent_color->r, _parent_color->g, _parent_color->b, _parent_color->a);
	SDL_RenderFillRect(AppGlobals::main_render, &r);
}
