#pragma once
#include "Control.h"
#include "XCross.h"

class CloseButton : public Control
{
public:
	CloseButton();
	CloseButton(SDL_Window* parent);
	

	void ImplBehaviour() override;
	

private:
	int _mouse_over_r = 233, _mouse_over_g = 211;
	int _mouse_over_b = 245, _mouse_over_a = 1;
	int _width = 75;
	int _height = 75;
	SDL_Window* _parent = nullptr;
	SDL_Rect _bounding_rect;
	

	bool MouseInButton(int x, int y);
	bool MouseYInButtonRange(int y);
	bool MouseXInButtonRange(int x);
};

