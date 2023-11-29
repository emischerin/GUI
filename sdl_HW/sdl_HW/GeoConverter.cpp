#include "GeoConverter.h"

std::vector<SDL_Point> GeoConverter::GetAllRectPoints(SDL_Rect* rect)
{
	
	std::vector<SDL_Point> result;

	if (!rect) return result;

	SDL_Point p1;
	p1.x = rect->x;
	p1.y = rect->y;

	SDL_Point p2;
	p2.x = rect->x + rect->w;
	p2.y = rect->y;

	SDL_Point p3;
	p3.x = rect->x;
	p3.y = rect->y + rect->h;

	SDL_Point p4;
	p4.x = rect->x + rect->w;
	p4.y = rect->y + rect->h;

	result.push_back(p1);
	result.push_back(p2);
	result.push_back(p3);
	result.push_back(p4);


}

std::vector<SDL_Point> GeoConverter::GetAllBoundingRectPoints(Control* control)
{

}
