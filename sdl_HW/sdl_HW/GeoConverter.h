#pragma once
#ifndef GEOCONVERTER_H
#define GEOCONVERTER_H


#include <vector>
#include <SDL.h>

class Control;
class Primitive;

class GeoConverter
{
public:

	std::vector<SDL_Point> GetAllRectPoints(SDL_Rect* rect);
	std::vector<SDL_Point> GetAllBoundingRectPoints(Control* control);
	std::vector<SDL_Point> GetAllBoundingRectPoints(Primitive* p);
};
#endif // !GEOCONVERTER_H
