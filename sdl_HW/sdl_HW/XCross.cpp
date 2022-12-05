#include "XCross.h"

XCross::XCross(int& x, int& y,int& w,int& h, XCrossMode mode)
{
	this->_bounding_rect.x = x;
	this->_bounding_rect.y = y;
	this->_bounding_rect.h = h;
	this->_bounding_rect.w = w;

	this->_x1 = _bounding_rect.x;
	this->_y1 = _bounding_rect.y;

	this->_mode = mode;
	
}

XCross::XCross(SDL_Rect& r, int mode)
{
	this->_bounding_rect = r;
	this->_x1 = _bounding_rect.x;
	this->_y1 = _bounding_rect.y;
	this->_mode = mode;
	
}
/*Needed to avoid ugly corners in Rectangles*/
void XCross::SetLines()
{
	line1._x1 = _bounding_rect.x;
	line1._y1 = _bounding_rect.y;
	line1._x2 = (_x1 + _bounding_rect.w);
	line1._y2 = (_y1 + _bounding_rect.h);

	line2._x1 = (_bounding_rect.x);
	line2._y1 = (_bounding_rect.y + _bounding_rect.h);
	line2._x2 = (_bounding_rect.x + _bounding_rect.w);
	line2._y2 = _bounding_rect.y;
}



void XCross::DrawLinesAliased()
{
	SetLines();
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderDrawLine(_renderer, line1._x1, line1._y1, line1._x2, line1._y2);
	SDL_RenderDrawLine(_renderer, line2._x1, line2._y1, line2._x2, line2._y2);

}



void XCross::SetColor(int r, int g, int b, int a)
{
	this->_r = r;
	this->_g = g;
	this->_b = b;
	this->_a = a;
}

void XCross::DrawLinesAntiAliased()
{
	
	SetLines();
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderDrawLine(_renderer, line1._x1, line1._y1, line1._x2, line1._y2);
	SDL_RenderDrawLine(_renderer, line2._x1, line2._y1, line2._x2, line2._y2);
	
	
	SDL_RenderDrawLine(_renderer, line1._x1 + 1 , line1._y1, line1._x2 + 1, line1._y2);
	SDL_RenderDrawLine(_renderer, line2._x1 + 1, line2._y1, line2._x2 + 1, line2._y2);

	SDL_RenderDrawLine(_renderer, line1._x1 + 2, line1._y1, line1._x2 + 2, line1._y2);
	SDL_RenderDrawLine(_renderer, line2._x1 + 2, line2._y1, line2._x2 + 2, line2._y2);

}

void XCross::ImplBehaviour() 
{
	

	if ((_mode & LINES_ANTIALIASED) == LINES_ANTIALIASED) {
		DrawLinesAntiAliased();
	}
	else  {
		DrawLinesAliased();
	}
	
	if ((_mode & RECT_VISIBLE) == RECT_VISIBLE) {
		FitRectToCross();
		SDL_RenderDrawRect(_renderer, &this->_bounding_rect);
	}

	
}

void XCross::FitRectToCross()
{

	if ((_mode & LINES_ANTIALIASED) == LINES_ANTIALIASED) {
		_bounding_rect.x -= 1;
		_bounding_rect.y -= 1;
		_bounding_rect.w += 4;
		_bounding_rect.h += 3;
	}
	else {
			
		_bounding_rect.w += 1;
		_bounding_rect.h += 1;
	}
}

XCross::~XCross() {}