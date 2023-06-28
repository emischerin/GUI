#pragma once
#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include <SDL.h>
/* TODO: 1) implement vertice color setter
*	     2) Move vertices from Triangle here		
*/
class Primitive
{
public:
	
	Primitive(int x, int y, int w, int h)
	{
		_bounding_rect.x = x;
		_bounding_rect.y = y;
		_bounding_rect.w = w;
		_bounding_rect.h = h;
	}

	Primitive(SDL_Rect* bounding_rect)
	{
		_bounding_rect.x = bounding_rect->x;
		_bounding_rect.y = bounding_rect->y;
		_bounding_rect.w = bounding_rect->w;
		_bounding_rect.h = bounding_rect->h;
	}

	Primitive(SDL_Rect bounding_rect)
	{
		_bounding_rect.x = bounding_rect.x;
		_bounding_rect.y = bounding_rect.y;
		_bounding_rect.w = bounding_rect.w;
		_bounding_rect.h = bounding_rect.h;
	}

	virtual void ReactToEvents() {};
	virtual void Draw() = 0;

	virtual std::vector<SDL_Vertex*> GetVertexArray() const
	{
		return _vertices;
	}

	std::vector<SDL_Vertex*>* GetVertexArrayPtr()
	{
		return &_vertices;
	}


protected:
	
	SDL_Rect _bounding_rect;
	/*
	* This is for solid one color figures
	*/
	SDL_Color _color = { 0,0,0,1 };

	std::vector<SDL_Vertex*> _vertices;
	


	

};





#endif
