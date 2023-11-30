#pragma once
#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include <algorithm>
#include <vector>
#include <SDL.h>

/* TODO: 1) implement vertice color setter
*	     2) Move vertices from Triangle here		
*/




class Primitive
{
	friend class Window;
	friend class Scene;
	friend class Control;

public:
	
	Primitive(Control* parent);

	Primitive(int x, int y, int w, int h);
	



	Primitive(SDL_Rect* bounding_rect);
	

	Primitive(SDL_Rect bounding_rect);
	

	virtual void SetBoundingRect(int x, int y, int w, int h);
	

	virtual void SetBoundingRect(SDL_Rect* bounding_rect);
	
	virtual SDL_Rect* GetBoundingRect();


	virtual void SetColor(int r, int g, int b, int a);


	virtual void SetColor(SDL_Color* color);
	

	virtual void SetMouseOverColor(SDL_Color* color);


	virtual SDL_Color* GetColor();


	virtual SDL_Color* GetMouseOverColor();
	

	virtual void ReactToEvents();
	virtual void Update();
	virtual void PreDraw();
	virtual void Draw();

	virtual std::vector<SDL_Vertex*> GetVertexArray() const;
	

	std::vector<SDL_Vertex*>* GetVertexArrayPtr();
	
	int GetX() const;


	int GetY() const;
	

	virtual int MaxXVertex();
	

	virtual int MaxYVertex();
	

	virtual int GetLayer();
	

	virtual void MoveUp(int step);
	

	virtual void MoveDown(int step);


	virtual void MoveLeft(int step);
	

	virtual void MoveRight(int step);

	void SetRender(SDL_Renderer* render);

	void SetParentControl(Control* c);

	std::vector<SDL_Point> GetAllBoundingRectPoints();

protected:
	
	void AppllyColorToEachVertex();


	
	

	void SetParentWindow(Window* w);


	
	


	SDL_Renderer* _render = nullptr;

	SDL_Rect _bounding_rect;
	/*
	* This is for solid one color figures
	*/
	SDL_Color _color = { 0,0,0,1 };

	SDL_Color _mouse_over_color = { 255,255,255,1 };

	std::vector<SDL_Vertex*> _vertices;
	
	Control* _parent_control = nullptr;

	Window* _my_parent_window = nullptr;


	

};





#endif
