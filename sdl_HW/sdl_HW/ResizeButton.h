#pragma once
#include "Control.h"
#include "XCross.h"
#include "CollisionDetector.h"
#include "AppGlobals.h"

class ResizeButton : public Control
{
public:
	ResizeButton();
	void ReactToEvents() override;
	void Draw() override;
private:
	int _mouse_over_r = 139, _mouse_over_g = 56;
	int _mouse_over_b = 148, _mouse_over_a = 1;
	int _width = 20;
	int _height = 20;



};

