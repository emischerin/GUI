#include "Primitives.h"
#include "Control.h"

Primitive::Primitive(Control* parent)
{
	if (!parent) return;

	this->_parent_control = parent;

	this->_render = parent->GetRender();

	this->SetBoundingRect(parent->GetBoundingRect());
}

Primitive::Primitive(int x, int y, int w, int h)
{
	_bounding_rect.x = x;
	_bounding_rect.y = y;
	_bounding_rect.w = w;
	_bounding_rect.h = h;
}



Primitive::Primitive(SDL_Rect* bounding_rect)
{
	_bounding_rect.x = bounding_rect->x;
	_bounding_rect.y = bounding_rect->y;
	_bounding_rect.w = bounding_rect->w;
	_bounding_rect.h = bounding_rect->h;
}

Primitive::Primitive(SDL_Rect bounding_rect)
{
	_bounding_rect.x = bounding_rect.x;
	_bounding_rect.y = bounding_rect.y;
	_bounding_rect.w = bounding_rect.w;
	_bounding_rect.h = bounding_rect.h;
}



std::vector<SDL_Vertex*> Primitive::GetVertexArray() const
{
	return _vertices;
}

std::vector<SDL_Vertex*>* Primitive::GetVertexArrayPtr()
{
	return &_vertices;
}

int Primitive::GetX() const
{
	return _bounding_rect.x;
}

int Primitive::GetY() const
{
	return _bounding_rect.y;
}

void Primitive::SetBoundingRect(SDL_Rect* bounding_rect)
{
	_bounding_rect.x = bounding_rect->x;
	_bounding_rect.y = bounding_rect->y;
	_bounding_rect.w = bounding_rect->w;
	_bounding_rect.h = bounding_rect->h;
}



void Primitive::SetRender(SDL_Renderer* render)
{
		_render = render;
}

	
