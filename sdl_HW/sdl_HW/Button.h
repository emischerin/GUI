#pragma once
#include "Control.h"

class Button : public Control
{
public:
	Button(SDL_Window* parent);
	

	void ImplBehaviour() override;
	

private:
	int _mouse_over_r = 58, _mouse_over_g = 6;
	int _mouse_over_b = 69, _mouse_over_a = 1;
	int _width = 150;
	int _height = 75;
	SDL_Window* _parent = nullptr;
	SDL_Rect _bounding_rect;
	

	bool MouseInButton(int x, int y);
	bool MouseYInButtonRange(int y);
	bool MouseXInButtonRange(int x);
};

