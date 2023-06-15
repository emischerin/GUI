#include "Triangle.h"

Triangle::Triangle(SDL_FPoint* basic_vertice, float height, float base_width)
{
	_a.x = basic_vertice->x;
	_a.y = basic_vertice->y;

	_b.x = _a.x - (base_width / 2);
	_b.y = _a.y + height;

	_c.x = _b.x + base_width;
	_c.y = _b.y;


}

void Triangle::Draw() 
{
	SDL_SetRenderDrawColor(AppGlobals::main_render, 0, 0, 0, 0);
}