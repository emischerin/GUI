#pragma once
#include "Control.h"
class BorderLine : public Control
{
public:

	/*
	* 
	* rel_x and rel_y are relative from window height and width
	* 
	*/
	BorderLine(SDL_Window* w,int rel_x,int rel_y);

	void ImplBehaviour() override;

	
	

protected:
	SDL_Window* _window = nullptr;
	int _rel_x, _rel_y;

};

