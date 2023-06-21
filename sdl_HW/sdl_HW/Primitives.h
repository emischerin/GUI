#pragma once
#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include <SDL.h>
class Primitive
{
public:
		 
	virtual void ReactToEvents() {};
	virtual void Draw() = 0;

protected:
	
	SDL_Rect _bounding_rect;
	/*
	* This is for solid one color figures
	*/
	SDL_Color _color = { 0,0,0,1 };


	

};





#endif
