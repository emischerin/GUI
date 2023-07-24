#pragma once
#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include <SDL.h>
/* TODO: 1) implement vertice color setter
*	     2) Move vertices from Triangle here		
*/
class Primitive
{
	friend class Window;
	friend class Control;
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

	virtual void SetBoundingRect(int x, int y, int w, int h)
	{
		_bounding_rect.x = x;
		_bounding_rect.y = y;
		_bounding_rect.w = w;
		_bounding_rect.h = h;
	}

	virtual void SetBoundingRect(SDL_Rect* bounding_rect)
	{
		_bounding_rect.x = bounding_rect->x;
		_bounding_rect.y = bounding_rect->y;
		_bounding_rect.w = bounding_rect->w;
		_bounding_rect.h = bounding_rect->h;
	}

	virtual void SetColor(int r, int g, int b, int a)
	{
		_color.r = r;
		_color.g = g;
		_color.b = b;
		_color.a = a;

		this->AppllyColorToEachVertex();
	}

	virtual void SetColor(SDL_Color* color)
	{
		_color.r = color->r;
		_color.g = color->g;
		_color.b = color->b;
		_color.a = color->a;

		this->AppllyColorToEachVertex();
	}

	virtual void SetMouseOverColor(SDL_Color* color)
	{
		_mouse_over_color.r = color->r;
		_mouse_over_color.g = color->g;
		_mouse_over_color.b = color->b;
		_mouse_over_color.a = color->a;


	}

	virtual SDL_Color* GetColor()
	{
		return &_color;
	}

	virtual SDL_Color* GetMouseOverColor()
	{
		return &_mouse_over_color;
	}

	virtual void ReactToEvents() {};
	virtual void PreDraw() {};
	virtual void Draw() = 0;

	virtual std::vector<SDL_Vertex*> GetVertexArray() const
	{
		return _vertices;
	}

	std::vector<SDL_Vertex*>* GetVertexArrayPtr()
	{
		return &_vertices;
	}

	int GetX() const
	{
		return _bounding_rect.x;
	}
	
	int GetY() const
	{ 
		return _bounding_rect.y;
	}

protected:
	
	void AppllyColorToEachVertex()
	{
		if (_vertices.size() == 0) return;

		for (SDL_Vertex* v : _vertices)
			if (v) v->color = _color;
	}

	void SetRender(SDL_Renderer* render)
	{
		_render = render;
	}

	SDL_Renderer* _render = nullptr;

	SDL_Rect _bounding_rect;
	/*
	* This is for solid one color figures
	*/
	SDL_Color _color = { 0,0,0,1 };

	SDL_Color _mouse_over_color = { 255,255,255,1 };

	std::vector<SDL_Vertex*> _vertices;
	
	Control* _parent_control = nullptr;


	

};





#endif
