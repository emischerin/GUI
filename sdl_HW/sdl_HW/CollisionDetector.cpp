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