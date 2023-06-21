#include "Triangle.h"

Triangle::Triangle(SDL_FPoint* basic_vertice, int height, int base_width)
{
	_a.position.x = basic_vertice->x;
	_a.position.y = basic_vertice->y;

	_a.color = _color;

	_b.position.x = _a.position.x - (base_width / 2);
	_b.position.y = _a.position.y + height;
	_b.color = _color;

	_c.position.x = _b.position.x + base_width;
	_c.position.y = _b.position.y;
	_c.color = _color;

	
	



}

void Triangle::Draw() 
{
	
	SDL_RenderGeometry(AppGlobals::main_render, 0, *_points.data(), _points.size(), 0, 0);
	
}