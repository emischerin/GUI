#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H



#include "Primitives.h"


/* TODO: move vertices logic to primitive (base class) as, in fact, every primitive has vertices */

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
	
	void Update() override;
	
	void SetDirection(Triangle::TriangleDirection dir);

	

	void InitVertices();

	Triangle::TriangleDirection GetDirection() const;

	void SetBoundingRect(int x, int y, int w, int h) override;

	void SetBoundingRect(SDL_Rect* bounding_rect) override;

protected:
	
	

	void SetVertexPosition(SDL_Vertex* v, float x, float y);


	SDL_Vertex _a;
	SDL_Vertex _b;
	SDL_Vertex _c;
	float _height = 0;
	
	TriangleDirection _my_direction;

private:

	void InitVertexArray();




};

#endif

