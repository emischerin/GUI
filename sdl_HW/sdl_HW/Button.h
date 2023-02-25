#pragma once
#include "Control.h"

class Button : public Control
{
public:
	Button();
	

	void ImplBehaviour() override;
	

private:
	int _mouse_over_r = 58, _mouse_over_g = 6;
	int _mouse_over_b = 69, _mouse_over_a = 1;
	int _width = 45;
	int _height = 20;
};

