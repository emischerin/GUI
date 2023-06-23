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

	

	Triangle(int x, int y, int w, int h,TriangleDirection dir = UP);


	Triangle(SDL_Rect* bounding_rect, TriangleDirection dir = UP);


	Triangle(SDL_Rect bounding_rect, TriangleDirection dir = UP);
	
	
	
	

	void Draw() override;
	

protected:
	
	void InitVertices();

	void SetVertexPosition(SDL_Vertex* v, float x, float y);


	SDL_Vertex _a;
	SDL_Vertex _b;
	SDL_Vertex _c;
	float _height = 0;
	std::vector<SDL_Vertex*> _points = {&_a,&_b,&_c};
	TriangleDirection _my_direction;




};

#endif

