#pragma once
#include "Control.h"
class BorderLine : public Control
{
public:

	BorderLine() {};

	/*
	* 
	* rel_x and rel_y are relative from window height and width
	* 
	*/
	BorderLine(SDL_Window* w,int rel_x,int rel_y);

	void ImplBehaviour() override;

	void SetRelativeCoordinates(int rel_x,int rel_y);
	

protected:
	SDL_Window* _window = nullptr;
	int _rel_x = 0, _rel_y = 0;

};

