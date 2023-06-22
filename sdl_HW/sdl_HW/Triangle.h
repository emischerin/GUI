#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include <SDL.h>
#include "Primitives.h"
#include "AppGlobals.h"

class Triangle : public Primitive
{

public:

	enum TriangleDirection
	{
		UP,
		DOWN,
		LEFT,
		RIGHT

	};

	

	Triangle(int x, int y, int w, int h,TriangleDirection dir);


	Triangle(SDL_Rect* bounding_rect, TriangleDirection dir);


	Triangle(SDL_Rect&& bounding_rect, TriangleDirection dir);
	
	
	

	void Draw() override;
	

protected:

	void InitVertices();

	SDL_Vertex _a;
	SDL_Vertex _b;
	SDL_Vertex _c;
	float _height = 0;
	std::vector<SDL_Vertex*> _points = {&_a,&_b,&_c};
	TriangleDirection _my_direction = UP;




};

#endif

