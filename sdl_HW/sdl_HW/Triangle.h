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

	Triangle(SDL_FPoint* basic_vertice, float height, float base_width);
	

	void Draw() override;
	

protected:
	SDL_FPoint _a;
	SDL_FPoint _b;
	SDL_FPoint _c;
	float _height = 0;
	std::vector<SDL_FPoint*> _points;



};

#endif

