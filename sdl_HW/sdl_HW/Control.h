#pragma once
#include <SDL.h>
class Control {
public:
	
	virtual void SetRenderer(SDL_Renderer* r)
	{
		_renderer = r;
	}

	virtual void SetColor(int r, int g, int b, int a) = 0;

	virtual void ImplBehaviour() = 0;
	virtual ~Control() = default;
protected:
	SDL_Renderer* _renderer;

	int _r = 255;
	int _g = 255;
	int _b = 255;
	int _a = 1;
};
