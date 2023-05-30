#pragma once
#include <SDL.h>
class Control {
public:
	

	

	virtual void SetColor(int r, int g, int b, int a)
	{
		_r = r;
		_g = g;
		_b = b;
		_a = a;
	}

	virtual void SetPosition(int x, int y)
	{
		_x = x;
		_y = y;

		_bounding_rect.x = x;
		_bounding_rect.y = y;
	}

	virtual void SetWidthAndHeight(int w, int h)
	{
		_width = w;
		_height = h;
		_bounding_rect.w = w;
		_bounding_rect.h = h;
	}

	virtual void SetBoundingRect(int x, int y, int w, int h)
	{
		_bounding_rect.x = x;
		_bounding_rect.y = y;
		_bounding_rect.w = w;
		_bounding_rect.h = h;
	}

	virtual SDL_Rect* GetBoundingRect()
	{
		return &_bounding_rect;
	}

	virtual void SetParentWindow(SDL_Window* w)
	{
		_parent_window = w;
	}

	int GetX() const
	{
		return _x;
	}
	int GetY() const
	{
		return _y;
	}

	virtual int GetWidth() const
	{
		return _bounding_rect.w;
	}

	virtual int GetHeight() const
	{
		return _bounding_rect.h;
	}

	virtual void ReactToEvents() {}
	virtual void Draw() = 0;
	virtual ~Control() = default;
protected:
	
	SDL_Rect _bounding_rect = {};
	SDL_Window* _parent_window = nullptr;

	int _r = 0;
	int _g = 0;
	int _b = 0;
	int _a = 1;

	int _x = 0;
	int _y = 0;
	int _width = 0;
	int _height = 0;
};
