#include "Triangle.h"

Triangle::Triangle(int x, int y, int w, int h, TriangleDirection dir) : Primitive(x,y,w,h)
{
	this->_my_direction = dir;
	this->InitVertexArray();
	this->InitVertices();
}


Triangle::Triangle(SDL_Rect* bounding_rect, TriangleDirection dir) :Primitive(bounding_rect)
{
	this->_my_direction = dir;
	this->InitVertexArray();
	this->InitVertices();
}


Triangle::Triangle(SDL_Rect bounding_rect, TriangleDirection dir) : Primitive(bounding_rect)
{
	this->_my_direction = dir;
	this->InitVertexArray();
	this->InitVertices();
}

void Triangle::InitVertices()
{
	if (_my_direction == UP) {
		_a.position.x = _bounding_rect.x + ( _bounding_rect.w / 2);
		_a.position.y = (_bounding_rect.y);

		_b.position.x = _bounding_rect.x;
		_b.position.y = _bounding_rect.y + _bounding_rect.h;

		_c.position.x = _bounding_rect.x + _bounding_rect.w;
		_c.position.y = _bounding_rect.y + _bounding_rect.h;

		/*Initializing Vertex Color*/
		_a.color = _color;
		_b.color = _color;
		_c.color = _color;

		return;

	}

	if (_my_direction == DOWN) {
		_a.position.x = _bounding_rect.x + (_bounding_rect.w / 2);
		_a.position.y = (_bounding_rect.y + _bounding_rect.h);

		_b.position.x = _bounding_rect.x;
		_b.position.y = _bounding_rect.y;

		_c.position.x = _bounding_rect.x + _bounding_rect.w;
		_c.position.y = _bounding_rect.y;

		/*Initializing Vertex Color*/
		_a.color = _color;
		_b.color = _color;
		_c.color = _color;

		return;
	}

	if (_my_direction == LEFT) {
		_a.position.x = (_bounding_rect.x);
		_a.position.y = _bounding_rect.y + (_bounding_rect.h /2);

		_b.position.x = _bounding_rect.x + _bounding_rect.w;
		_b.position.y = _bounding_rect.y;

		_c.position.x = _bounding_rect.x + _bounding_rect.w;
		_c.position.y = _bounding_rect.y + _bounding_rect.h;

		/*Initializing Vertex Color*/
		_a.color = _color;
		_b.color = _color;
		_c.color = _color;

		return;
	}

	if (_my_direction == RIGHT) {
		_a.position.x = (_bounding_rect.x + _bounding_rect.w);
		_a.position.y = _bounding_rect.y + (_bounding_rect.h / 2);

		_b.position.x = _bounding_rect.x;
		_b.position.y = _bounding_rect.y;

		_c.position.x = _bounding_rect.x;
		_c.position.y = _bounding_rect.y + _bounding_rect.h;

		/*Initializing Vertex Color*/
		_a.color = _color;
		_b.color = _color;
		_c.color = _color;

		return;
	}
	else /*If somebody manage to pass some value that out of enum scope*/
	{
		_a.position.x = _bounding_rect.x + (_bounding_rect.w / 2);
		_a.position.y = (_bounding_rect.y);

		_b.position.x = _bounding_rect.x;
		_b.position.y = _bounding_rect.y + _bounding_rect.h;

		_c.position.x = _bounding_rect.x + _bounding_rect.w;
		_c.position.y = _bounding_rect.y + _bounding_rect.h;

		/*Initializing Vertex Color*/
		_a.color = _color;
		_b.color = _color;
		_c.color = _color;

		return;
	}

	


}

void Triangle::SetBoundingRect(int x, int y, int w, int h) 
{
	Control::SetBoundingRect(x,y,w,h);

	this->InitVertices();

}

void Triangle::SetBoundingRect(SDL_Rect* bounding_rect)
{
	Control::SetBoundingRect(bounding_rect);

	this->InitVertices();
}

void Triangle::Update()
{
	this->InitVertices();
}

void Triangle::Draw()
{
	this->InitVertices();

	int result = SDL_RenderGeometry(_render, 0, *(_vertices.data()), _vertices.size(), 0, 0);
	
	if (result)
	{
		const char* err = SDL_GetError();

		SDL_Log(err);
	}
	

	
}

void Triangle::SetVertexPosition(SDL_Vertex* v, float x, float y)
{
	v->position.x = x;
	v->position.y = y;
}

void Triangle::InitVertexArray()
{
	_vertices = { &_a,&_b,&_c };
}

void Triangle::SetDirection(Triangle::TriangleDirection dir)
{
	this->_my_direction = dir;
	this->InitVertices();
}

Triangle::TriangleDirection Triangle::GetDirection() const
{
	return _my_direction;
}