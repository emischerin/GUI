#pragma once
#ifndef GEOCONVERTER_H
#define GEOCONVERTER_H


#include <vector>
#include <SDL.h>

class GeoConverter
{
public:

	std::vector<SDL_Point> GetAllRectPoints(SDL_Rect* rect);
};
#endif // !GEOCONVERTER_H
