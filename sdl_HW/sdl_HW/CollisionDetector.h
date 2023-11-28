#pragma once
#include <vector>
#include "Control.h"
#include <SDL.h>

class CollisionDetector
{
public:
	bool PointInControl(Control* control,int x,int y);
	bool MouseInWindow(SDL_Window* window);
	bool PointInRect(SDL_Rect* rect, int x, int y);
	bool MouseInControl(Control* control);

	bool PointXInRect(SDL_Rect* rect, int x);

	bool PointYInRect(SDL_Rect* rect,int y);




	bool AllControlsXInRect(std::vector<Control*> v, SDL_Rect* rect);

	bool AllControlsYInRect(std::vector<Control*> v, SDL_Rect* rect);


	bool AllControlsXInControl(std::vector<Control*> v, Control* c);

	bool AllControlsYInControl(std::vector<Control*> v, Control* c);
};

