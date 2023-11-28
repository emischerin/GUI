#include "CollisionDetector.h"

bool CollisionDetector::PointInControl(Control* control, int x, int y)
{
	if (!control) return false;

	SDL_Rect* bounding_rect = control->GetBoundingRect();

	if (!bounding_rect) return false;

	return PointInRect(bounding_rect, x, y);

	
		
}

bool CollisionDetector::MouseInWindow(SDL_Window* window)
{
	if (!window) return false;

	int mouse_x, mouse_y;
	int win_x, win_y, win_w, win_h;

	SDL_GetGlobalMouseState(&mouse_x, &mouse_y);
	SDL_GetWindowSize(window, &win_w, &win_h);
	SDL_GetWindowPosition(window, &win_x, &win_y);

	SDL_Rect rect = { win_x,win_y,win_w,win_h };
	
	return PointInRect(&rect, mouse_x, mouse_y);


}

bool CollisionDetector::PointInRect(SDL_Rect* rect, int x, int y)
{
	if (!rect) return false;

	int upper_x = rect->x + rect->w;
	int upper_y = rect->y + rect->h;

	return ((x >= rect->x && x <= upper_x) && 
			(y >= rect->y && y <= upper_y));


}

bool CollisionDetector::MouseInControl(Control* control)
{
	if (!control) return false;

	int mouse_x, mouse_y;
	SDL_GetMouseState(&mouse_x, &mouse_y);

	return PointInControl(control, mouse_x, mouse_y);


}

bool CollisionDetector::PointXInRect(SDL_Rect* rect, int x)
{
	int rect_x1 = rect->x;
	int rect_x2 = rect->x + rect->w;

	if ((x >= rect_x1) && (x <= rect_x2))
		return true;

	return false;
}

bool CollisionDetector::PointYInRect(SDL_Rect* rect, int y)
{
	int rect_y1 = rect->y;
	int rect_y2 = rect->y + rect->h;

	if ((y >= rect_y1) && (y <= rect_y2))
		return true;

	return false;
}




bool CollisionDetector::AllControlsXInRect(std::vector<Control*> v, SDL_Rect* rect)
{

}

bool CollisionDetector::AllControlsYInRect(std::vector<Control*> v, SDL_Rect* rect)
{

}


bool CollisionDetector::AllControlsXInControl(std::vector<Control*> v, Control* c)
{

}

bool CollisionDetector::AllControlsYInControl(std::vector<Control*> v, Control* c)
{

}