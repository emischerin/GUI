#pragma once
#ifndef CONTROL_H
#define CONTROL_H

#include <SDL.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include "AppGlobals.h"
#include "Window.h"




class Control
{

	
	friend class Window;
	friend class Scene;

public:
	
	struct ControlMsg
	{
		int _command;
		void* _result;
		void* _result2; //just in case you need additional result args

	};


	Control();

	Control(Control* parent);
	

	Control(Window* parent_window);
	

	virtual void SetColor(int r, int g, int b, int a);
	

	virtual void SetColor(SDL_Color* color);
	

	virtual void SetMouseOverColor(SDL_Color* color);
	

	virtual void SetMouseOverColor(int r, int g, int b, int a);
	

	virtual SDL_Color* GetColor();
	

	virtual SDL_Color* GetMouseOverColor();


	virtual void SetPosition(int x, int y);
	

	virtual void SetWidthAndHeight(int w, int h);
	

	virtual void SetWidth(int w);
	

	virtual void SetHeight(int h);


	virtual void SetBoundingRect(int x, int y, int w, int h);
	

	virtual void SetBoundingRect(SDL_Rect* bounding_rect);


	virtual SDL_Rect* GetBoundingRect();
	

	virtual void SetParentWindow(SDL_Window* w);
	

	virtual void SetParentWindow(Window* w);


	virtual void SetParentWindow(Window* my_w, SDL_Window* sdl_w);
	

	virtual SDL_Window* GetParentWindow() const;


	virtual Window* GetMyParentWindow() const;
	

	int GetX() const;
	

	int GetY() const;
	

	virtual int GetWidth() const;
	

	virtual int GetHeight() const;
	

	virtual void SetParentControl(Control* parent);
	
		

	virtual Control* GetParentControl() const;
	

	virtual void AddChild(Control* child);
	

	
	

	virtual void ReactToEvents();
	

	virtual void Update();
	


	/*
	* Now this needs for Scene, but probably will be needed in future somwhere else
	*/
	virtual void PreDraw();
	
	

	virtual void Draw();
	

	virtual void AdjustToParent();
	virtual void AdjustChildren();


	virtual int MinXControl();
	

	virtual int MaxXControl();
	



	virtual int MinYControl();
	

	virtual int MaxYControl();
	
	
	

	/*RETURNS MIN Y CONTROL OR PRIMITIVE*/
	virtual int MinYObject();
	/*RETURNS MAX Y CONTROL OR PRIMITIVE*/
	virtual int MaxYObject();

	virtual int MaxXObject();

	virtual int MinXObject();

	void ResizeWidth(int dx);
	

	void ResizeHeight(int dy);
	

	virtual int GetLayer();
	
	
	virtual void MoveUp(int step);
	

	virtual void MoveDown(int step);
	

	virtual void MoveLeft(int step);
	

	virtual void MoveRight(int step);
	

	virtual ~Control();
	

	virtual void ControlMessagingFunction(ControlMsg* message);

	virtual void RemoveChild(Control* c);
		
	std::vector<SDL_Point> GetAllBoundingRectPoints();
	



	
	SDL_Renderer* GetRender();

	void SetRender(SDL_Renderer* render);
	
	void SetRenderToChildren(SDL_Renderer* render);

	void SetParentWindowToChildren(Window* w);

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
	
	


};

#endif