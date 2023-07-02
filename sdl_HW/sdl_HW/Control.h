#pragma once
#ifndef CONTROL_H
#define CONTROL_H

#include <SDL.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include "AppGlobals.h"
#include "Window.h"
#include "Primitives.h"



class Control
{

	friend class Primitive;
	friend class Window;
	
public:
	

	Control() {};

	Control(Control* parent)
	{
		if (!parent) return;

		_parent_control = parent;

		parent->AddChild(this);
	}

	Control(Window* parent_window)
	{
		if (!parent_window) return;

		_my_parent_window = parent_window;
		_parent_window = parent_window->GetWinPtr();

		_my_parent_window->AddControl(this);

	}

	virtual void SetColor(int r, int g, int b, int a)
	{
		_color.r = r;
		_color.g = g;
		_color.b = b;
		_color.a = a;
	}

	virtual void SetColor(SDL_Color* color)
	{
		_color.r = color->r;
		_color.g = color->g;
		_color.b = color->b;
		_color.a = color->a;
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

	virtual void SetPosition(int x, int y)
	{
		_bounding_rect.x = x;
		_bounding_rect.y = y;
	}

	virtual void SetWidthAndHeight(int w, int h)
	{		
		_bounding_rect.w = w;
		_bounding_rect.h = h;
	}

	virtual void SetBoundingRect(int x, int y, int w, int h)
	{
		_bounding_rect.x = x;
		_bounding_rect.y = y;
		_bounding_rect.w = w;
		_bounding_rect.h = h;
	}

	virtual SDL_Rect* GetBoundingRect()
	{
		return &_bounding_rect;
	}

	virtual void SetParentWindow(SDL_Window* w)
	{
		_parent_window = w;
		
		Window* my_win = AppGlobals::win_tracker->GetMyWindow(w);
		this->SetParentWindow(my_win);
		
	}

	virtual void SetParentWindow(Window* w)
	{
		_my_parent_window = w;
		_render = w->GetWinRender();
	}

	virtual void SetParentWindow(Window* my_w, SDL_Window* sdl_w)
	{
		this->SetParentWindow(my_w);
		this->SetParentWindow(sdl_w);
	}

	virtual SDL_Window* GetParentWindow() const
	{
		return _parent_window;
	}

	int GetX() const
	{
		return _bounding_rect.x;
	} 

	int GetY() const
	{
		return _bounding_rect.y;
	}

	virtual int GetWidth() const
	{
		return _bounding_rect.w;
	}

	virtual int GetHeight() const
	{
		return _bounding_rect.h;
	}

	virtual void SetParentControl(Control* parent)
	{
		_parent_control = parent;
		_render = parent->GetRender();
	}

	virtual Control* GetParentControl() const
	{
		return _parent_control;
	}

	virtual void AddChild(Control* child)
	{
		if (!child) return;
		child->SetRender(_render);
		_child_controls.push_back(child);
		_total_children_width += child->GetWidth();
		_total_children_height += child->GetHeight();
	}

	virtual void AddPrimitive(Primitive* p)
	{
		if (!p) return;
		p->SetRender(_render);
		_primitives.push_back(p);
	}

	virtual void ReactToEvents() {}
	virtual void Draw() = 0;
	virtual void AdjustToParent(){}
	virtual void AdjustChildren() {}


	virtual int MinXControl()
	{
		auto _control_by_x = [](Control* c1, Control* c2)
		{
			return (c1->GetX() < c2->GetX());
		};

		auto it = _child_controls.begin();

		std::nth_element(_child_controls.begin(), it, _child_controls.end(), _control_by_x);

		return (*it)->GetX();
	}

	virtual int MaxXControl()
	{
		
		auto _control_by_x = [](Control* c1, Control* c2)
		{
			return (c1->GetX() > c2->GetX());
		};

		auto it = _child_controls.begin();

		std::nth_element(_child_controls.begin(), it, _child_controls.end(), _control_by_x);

		return (*it)->GetX();
	}



	virtual int MinYControl()
	{
		auto _control_by_y = [](Control* c1, Control* c2)
		{
			return (c1->GetY() < c2->GetY());
		};

		auto it = _child_controls.begin();

		std::nth_element(_child_controls.begin(), it, _child_controls.end(), _control_by_y);

		return (*it)->GetY();
	}

	virtual int MaxYControl()
	{
		auto _control_by_y = [](Control* c1, Control* c2)
		{
			return (c1->GetY() > c2->GetY());
		};

		auto it = _child_controls.begin();

		std::nth_element(_child_controls.begin(), it, _child_controls.end(), _control_by_y);

		return (*it)->GetY();
	}

	virtual int MinXPrimitive()
	{
		auto _primitive_by_x = [](Primitive* p1, Primitive* p2)
		{
			return (p1->GetX() < p2->GetX());
		};

		auto it = _primitives.begin();

		std::nth_element(_primitives.begin(), it, _primitives.end(), _primitive_by_x);

		return (*it)->GetX();
	}

	virtual int MaxXPrimitive()
	{
		auto _primitive_by_x = [](Primitive* p1, Primitive* p2)
		{
			return (p1->GetX() > p2->GetX());
		};

		auto it = _primitives.begin();

		std::nth_element(_primitives.begin(), it, _primitives.end(), _primitive_by_x);

		return (*it)->GetX();
	}

	

	virtual int MinYPrimitive()
	{
		auto _primitive_by_y = [](Primitive* p1, Primitive* p2)
		{
			return (p1->GetY() < p2->GetY());
		};

		auto it = _primitives.begin();

		std::nth_element(_primitives.begin(), it, _primitives.end(), _primitive_by_y);

		return (*it)->GetY();
	}

	virtual int MaxYPrimitive()
	{
		auto _primitive_by_y = [](Primitive* p1, Primitive* p2)
		{
			return (p1->GetY() > p2->GetY());
		};

		auto it = _primitives.begin();

		std::nth_element(_primitives.begin(), it, _primitives.end(), _primitive_by_y);

		return (*it)->GetY();
	}

	void ResizeWidth(int dx)
	{
		_bounding_rect.x += dx;
	}

	void ResizeHeight(int dy)
	{
		_bounding_rect.h += dy;
	}


	virtual ~Control() 
	{
		for (Primitive* p : _primitives)
			if (p) delete p;

		for (Control* c : _child_controls)
			if (c) delete c;

	}


protected:
	
	SDL_Renderer* GetRender() { return _render; }

	void SetRender(SDL_Renderer* render) { _render = render; }

	int _total_children_width = 0;

	int _total_children_height = 0;

	SDL_Rect _bounding_rect = {};
	
	SDL_Color _color = { 0,0,0,1 };

	SDL_Color _mouse_over_color = { 0,0,0,1 };

	SDL_Window* _parent_window = nullptr;

	SDL_Renderer* _render = nullptr;

	Window* _my_parent_window = nullptr;

	Control* _parent_control = nullptr;

	std::vector<Control*> _child_controls;
	
	std::vector<Primitive*> _primitives;


};

#endif