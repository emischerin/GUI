#include "Primitives.h"


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


 int Primitive::MaxXVertex()
{
	if (_vertices.size() == 0) return -1;

	auto _vertex_by_x = [](SDL_Vertex* v1, SDL_Vertex* v2)
	{
		return (v1->position.x > v2->position.x);
	};

	auto it = _vertices.begin();

	std::nth_element(_vertices.begin(), it, _vertices.end(), _vertex_by_x);

	return (*it)->position.x;
}

 int Primitive::MaxYVertex()
 {
	 if (_vertices.size() == 0) return -1;

	 auto _vertex_by_y = [](SDL_Vertex* v1, SDL_Vertex* v2)
	 {
		 return (v1->position.y > v2->position.y);
	 };

	 auto it = _vertices.begin();

	 std::nth_element(_vertices.begin(), it, _vertices.end(), _vertex_by_y);

	 return (*it)->position.y;
 }


 //TODO: Add BoundingRectUpdate for Primitives
 void Primitive::MoveUp(int step)
 {
	 if (_vertices.size() <= 0) return;

	 this->_bounding_rect.y -= step;

	 for (int i = 0; i < _vertices.size(); ++i) {
		 SDL_Vertex* v = _vertices[i];
		 if (v) v->position.y -= step;
	 }
 }

 void Primitive::MoveDown(int step)
 {
	 if (_vertices.size() <= 0) return;

	 this->_bounding_rect.y += step;

	 for (int i = 0; i < _vertices.size(); ++i) {
		 SDL_Vertex* v = _vertices[i];
		 if (v) v->position.y += step;
	 }
 }

 void Primitive::MoveLeft(int step)
 {
	 if (_vertices.size() <= 0) return;

	 this->_bounding_rect.x -= step;

	 for (int i = 0; i < _vertices.size(); ++i) {
		 SDL_Vertex* v = _vertices[i];
		 if (v) v->position.x -= step;
	 }
 }

 int Primitive::GetLayer()
 {
	 const int layer = -5;
	 return layer;
 }

 void Primitive::MoveRight(int step)
 {
	 if (_vertices.size() <= 0) return;

	 this->_bounding_rect.x += step;

	 for (int i = 0; i < _vertices.size(); ++i) {
		 SDL_Vertex* v = _vertices[i];
		 if (v) v->position.x += step;
	 }
 }

 void Primitive::AppllyColorToEachVertex()
 {
	 if (_vertices.size() == 0) return;

	 for (SDL_Vertex* v : _vertices)
		 if (v) v->color = _color;
 }

 void Primitive::SetRender(SDL_Renderer* render)
 {
	 _render = render;
 }



 std::vector<SDL_Point> Primitive::GetAllBoundingRectPoints()
 {
	 std::vector<SDL_Point> result;

	 SDL_Point p1;
	 p1.x = _bounding_rect.x;
	 p1.y = _bounding_rect.y;

	 SDL_Point p2;
	 p2.x = _bounding_rect.x + _bounding_rect.w;
	 p2.y = _bounding_rect.y;

	 SDL_Point p3;
	 p3.x = _bounding_rect.x;
	 p3.y = _bounding_rect.y + _bounding_rect.h;

	 SDL_Point p4;
	 p4.x = _bounding_rect.x + _bounding_rect.w;
	 p4.y = _bounding_rect.y + _bounding_rect.h;

	 result.push_back(p1);
	 result.push_back(p2);
	 result.push_back(p3);
	 result.push_back(p4);

	 return result;
 }

	
