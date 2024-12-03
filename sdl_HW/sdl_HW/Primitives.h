#pragma once
#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include <algorithm>
#include <vector>
#include <SDL.h>
#include "Control.h"
/* TODO: 1) implement vertice color setter
*	     2) Move vertices from Triangle here		
*/




class Primitive : public Control
{
		

public:
	
	Primitive(Control* parent);

	Primitive(int x, int y, int w, int h);
	



	Primitive(SDL_Rect* bounding_rect);
	

	Primitive(SDL_Rect bounding_rect);
	

	

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

	
	void AppllyColorToEachVertex();


	
	

	void SetParentWindow(Window* w);

	std::vector<SDL_Vertex*> _vertices;
	
	

	Window* _my_parent_window = nullptr;


	

};





#endif
