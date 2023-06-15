#pragma once
#ifndef PRIMITIVES_H
#define PRIMITIVES_H

class Primitive
{
public:
	virtual void ReactToEvents() {};
	virtual void Draw() = 0;

protected:
	SDL_Color _color = { 0,0,0,1 };


	

};





#endif
