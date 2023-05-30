#pragma once
#include "Control.h"
#include "XCross.h"
#include "CollisionDetector.h"
#include "AppGlobals.h"

class CloseButton : public Control
{
public:
	CloseButton();
	CloseButton(SDL_Window* parent);
	CloseButton(Control* parent);

	void Draw() override;
	
	
	

	
	void ReactToEvents() override;
private:
	int _mouse_over_r = 139, _mouse_over_g = 56;
	int _mouse_over_b = 148, _mouse_over_a = 1;
	
	
	
	

	
};

