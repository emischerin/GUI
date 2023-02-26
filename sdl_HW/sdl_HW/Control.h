#pragma once
#include <SDL.h>
class Control {
public:
	
	virtual void SetRenderer(SDL_Renderer* r)
	{
		_renderer = r;
	}

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
	}

	virtual void ImplBehaviour() = 0;
	virtual ~Control() = default;
protected:
	SDL_Renderer* _renderer = nullptr;

	int _r = 0;
	int _g = 0;
	int _b = 0;
	int _a = 1;

	int _x = 0;
	int _y = 0;
};
