#include "InputCaret.h"
InputCaret::InputCaret(int x, int y)
{
	this->_x = x;
	this->_y = y;
	SetRect();
}

InputCaret::InputCaret(int x, int y, int w,int h)
{
	this->_x = x;
	this->_y = y;
	this->_w = w;
	this->_h = h;
	SetRect();
}

void InputCaret::SetWidth(int w)
{
	this->_w = w;
	SetRect();
}

void InputCaret::SetHeight(int h)
{
	this->_h = h;
}

void InputCaret::SetColor(int r, int g, int b, int a)
{
	this->_r = r;
	this->_g = g;
	this->_b = b;
	this->_a = a;
}

void InputCaret::SetRect()
{
	this->_rect.x = _x;
	this->_rect.y = _y;
	this->_rect.w = _w;
	this->_rect.h = _h;
}

void InputCaret::SetInvisibilityColor(int r, int g, int b, int a)
{
	this->_inv_r = r;
	this->_inv_g = g;
	this->_inv_b = b;
	this->_inv_a = a;
}

void InputCaret::SetTimeout(int timeout)
{
	if (timeout <= 0) return;

	this->_timeout = timeout;
}

void InputCaret::SetDrawingColor()
{
	if (_this_state == VISIBLE)
		SetVisibleState();
	else {
		
	}
}

void InputCaret::ImplBehaviour()
{
	uint32_t current_ticks = SDL_GetTicks();

	if ((current_ticks - _last_tick) >= _timeout) {
		void _set_state();
		
	}

	SDL_RenderFillRect(_renderer,&_rect);

	_last_tick = current_ticks;
		
}

void InputCaret::SetVisibleState()
{
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	_this_state = VISIBLE;
	_set_state = SetInvisibleState;
}

 void InputCaret::SetInvisibleState()
{
	SDL_SetRenderDrawColor(_renderer, _inv_r, _inv_g, _inv_b, _inv_a);
	_this_state = INVISIBLE;
	_set_state = SetVisibleState;
}