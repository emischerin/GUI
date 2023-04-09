#include "FatRect.h"

FatRect::FatRect(int x, int y, int w, int h)
{
	this->_x = x;
	this->_y = y;
	this->_w = w;
	this->_h = h;

	this->_rect.x = _x;
	this->_rect.y = _y;
	this->_rect.w = _w;
	this->_rect.h = _h;

}

void FatRect::Draw()
{
	int rects_num = 3;
	DrawRects(rects_num);
}

void FatRect::SetColor(int r, int g, int b, int a)
{
	this->_r = r;
	this->_g = g;
	this->_b = b;
	this->_a = a;
}

void FatRect::DrawRects(int rects_count)
{
	if (rects_count < 1) return;
	
	SDL_SetRenderDrawColor(AppGlobals::main_render, _r, _g, _b, _a);
	SDL_Rect tmp = _rect;
	SDL_RenderDrawRect(AppGlobals::main_render, &tmp);

	for (int i = 1; i < rects_count; ++i) {
		GetNextRect(tmp);
		SDL_RenderDrawRect(AppGlobals::main_render, &tmp);

	}
	
}

void FatRect::GetNextRect(SDL_Rect& tmp_rect)
{
	tmp_rect.x += - 1;
	tmp_rect.y += - 1;
	tmp_rect.w += 2;
	tmp_rect.h += 2;
}

FatRect::~FatRect(){}
