#pragma once
#include <vector>
#include <SDL.h>
#include "Control.h"
#include "Primitives.h"
#include "GeoConverter.h"

class CollisionDetector
{
public:
	bool PointInControl(Control* control,int x,int y);
	bool PointInControl(Control* control, SDL_Point* p);

	bool MouseInWindow(SDL_Window* window);
	bool PointInRect(SDL_Rect* rect, int x, int y);
	bool MouseInControl(Control* control);

	bool PointXInRect(SDL_Rect* rect, int x);

	bool PointYInRect(SDL_Rect* rect,int y);




	bool AllControlsXInRect(std::vector<Control*>& v, SDL_Rect* rect);

	bool AllControlsYInRect(std::vector<Control*>& v, SDL_Rect* rect);


	bool AllControlsXInControl(std::vector<Control*>& v, Control* c);

	bool AllControlsYInControl(std::vector<Control*>& v, Control* c);

	bool RectInRect(SDL_Rect* outer, SDL_Rect* inner);

	bool ControlInControl(Control* outer, Control* inner);

	bool AllPointsInControl(Control* outer, Control* inner);

	bool AllPrimitivePointsInControl(Control* outer, Primitive* inner);
	
	
};

