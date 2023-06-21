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

	Triangle(SDL_FPoint* basic_vertice, int height, int base_width);
	

	void Draw() override;
	

protected:
	SDL_Vertex _a;
	SDL_Vertex _b;
	SDL_Vertex _c;
	float _height = 0;
	std::vector<SDL_Vertex*> _points = {&_a,&_b,&_c};




};

#endif

