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



void Primitive::SetBoundingRect(int x, int y, int w, int h)
{
	_bounding_rect.x = x;
	_bounding_rect.y = y;
	_bounding_rect.w = w;
	_bounding_rect.h = h;
}

void Primitive::SetBoundingRect(SDL_Rect* bounding_rect)
{
	_bounding_rect.x = bounding_rect->x;
	_bounding_rect.y = bounding_rect->y;
	_bounding_rect.w = bounding_rect->w;
	_bounding_rect.h = bounding_rect->h;
}

void Primitive::SetColor(int r, int g, int b, int a)
{
	_color.r = r;
	_color.g = g;
	_color.b = b;
	_color.a = a;

	this->AppllyColorToEachVertex();
}


void Primitive::SetColor(SDL_Color* color)
{
	_color.r = color->r;
	_color.g = color->g;
	_color.b = color->b;
	_color.a = color->a;

	this->AppllyColorToEachVertex();
}


void Primitive::SetMouseOverColor(SDL_Color* color)
{
	_mouse_over_color.r = color->r;
	_mouse_over_color.g = color->g;
	_mouse_over_color.b = color->b;
	_mouse_over_color.a = color->a;


}

SDL_Color* Primitive::GetColor()
{
	return &_color;
}

 SDL_Color* Primitive::GetMouseOverColor()
{
	return &_mouse_over_color;
}

 void Primitive::ReactToEvents()
 {

 }
 void Primitive::Update()
 {

 }
 void Primitive::PreDraw()
 {

 }
 void Primitive::Draw()
 {

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



 void Primitive::SetParentWindow(Window* w)
 {
	 _my_parent_window = w;
 }

 void Primitive::SetParentControl(Control* c)
 {
	 _parent_control = c;
	 _render = c->GetRender();
 }



	
