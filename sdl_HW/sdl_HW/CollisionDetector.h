#pragma once
#include "Control.h"
#include <SDL.h>
class CollisionDetector
{public:
	bool PointInControl(Control* control,int x,int y);
	bool MouseInWindow(SDL_Window* window);
	bool PointInRect(SDL_Rect* rect, int x, int y);
	bool MouseInControl(Control* control);

};

