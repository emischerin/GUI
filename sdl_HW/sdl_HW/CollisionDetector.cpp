#include "CollisionDetector.h"

bool CollisionDetector::PointInControl(Control* control, int x, int y)
{
	if (!control) return false;

	SDL_Rect* bounding_rect = control->GetBoundingRect();

	if (!bounding_rect) return false;

	return PointInRect(bounding_rect, x, y);

	
		
}

bool CollisionDetector::AllControlsGroupInControl(std::vector<Control*>& inner, Control* outer)
{
	if (!outer) return false;

	for (auto ctrl : inner) {
		if (!AllControlPointsInControl(outer,ctrl))
			return false;
	}

	return true;
}

bool CollisionDetector::AllPrimitiveGroupInControl(std::vector<Primitive*>& inner, Control* outer)
{
	if (!outer) return false;

	for (auto primitive : inner) {
		if (!AllPrimitivePointsInControl(outer,primitive))
			return false;
	}

	return true;
}

bool CollisionDetector::NotAllControlsGroupInControl(std::vector<Control*>& inner, Control* outer)
{
	if (!outer) return false;

	for (auto ctrl : inner) {

		if (!AllControlPointsInControl(outer, ctrl))
			return true;
	}

	return false;
}

bool CollisionDetector::NotAllPrimitiveGroupInControl(std::vector<Primitive*>& inner, Control* outer)
{
	if (!outer) return false;

	for (auto primitive : inner) {
		if (!AllPrimitivePointsInControl(outer, primitive))
			return true;
	}

	return false;
}

bool CollisionDetector::PointInControl(Control* control, SDL_Point* p)
{
	if (!control) return false;
	if (!p) return false;


	SDL_Rect* bounding_rect = control->GetBoundingRect();

	if (!bounding_rect) return false;

	return PointInRect(bounding_rect, p->x, p->y);

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
	if (!rect) return false;

	int rect_x1 = rect->x;
	int rect_x2 = rect->x + rect->w;

	if ((x >= rect_x1) && (x <= rect_x2))
		return true;

	return false;
}

bool CollisionDetector::PointYInRect(SDL_Rect* rect, int y)
{
	if (!rect) return false;

	int rect_y1 = rect->y;
	int rect_y2 = rect->y + rect->h;

	if ((y >= rect_y1) && (y <= rect_y2))
		return true;

	return false;
}




bool CollisionDetector::AllControlsXInRect(std::vector<Control*>& v, SDL_Rect* rect)
{
	if (!rect) return false;
	if (v.size() == 0) return false;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i]) {
			SDL_Rect* ctrl_rect = v[i]->GetBoundingRect();

			if (!PointXInRect(rect, ctrl_rect->x))
				return false;
		}
	}

	return true;
}

bool CollisionDetector::AllControlsYInRect(std::vector<Control*>& v, SDL_Rect* rect)
{
	if (!rect) return false;
	if (v.size() == 0) return false;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i]) {
			SDL_Rect* ctrl_rect = v[i]->GetBoundingRect();

			if (!PointYInRect(rect, ctrl_rect->y))
				return false;
		}
	}

	return true;
}


bool CollisionDetector::AllControlsXInControl(std::vector<Control*>& v, Control* c)
{
	if (!c) return false;
	if (v.size() == 0) return false;

	SDL_Rect* ctrl_rect = c->GetBoundingRect();

	return AllControlsXInRect(v, ctrl_rect);


}


bool CollisionDetector::AllControlsYInControl(std::vector<Control*>& v, Control* c)
{
	if (!c) return false;
	if (v.size() == 0) return false;

	SDL_Rect* ctrl_rect = c->GetBoundingRect();

	return AllControlsYInRect(v, ctrl_rect);
}

bool CollisionDetector::RectInRect(SDL_Rect* outer, SDL_Rect* inner)
{
	return false;
}

bool CollisionDetector::ControlInControl(Control* outer, Control* inner)
{
	return AllControlPointsInControl(outer, inner);
}

bool CollisionDetector::AllControlPointsInControl(Control* outer, Control* inner)
{
	if (!outer) return false;
	if (!inner) return false;

	std::vector<SDL_Point> inner_points = inner->GetAllBoundingRectPoints();

	for (int i = 0; i < inner_points.size(); ++i) {
		if (!PointInControl(outer, &inner_points[i])) {
			return false;
		}
	}

	return true;

	
}

bool CollisionDetector::AllPrimitivePointsInControl(Control* outer, Primitive* inner)
{
	if (!outer) return false;
	if (!inner) return false;

	std::vector<SDL_Point> inner_points = inner->GetAllBoundingRectPoints();

	for (int i = 0; i < inner_points.size(); ++i) {
		if (!PointInControl(outer, &inner_points[i])) {
			return false;
		}
	}

	return true;
}