#pragma once
#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H
#include "Control.h"

#include "CollisionDetector.h"

class Window;

class CloseButton : public Control
{
public:
	CloseButton();
	CloseButton(SDL_Window* parent);
	CloseButton(Window* parent_window);
	CloseButton(Control* parent);

	void Draw() override;
	
	void SetParentControl(Control* parent) override;
	
	

	
	void ReactToEvents() override;
private:
	int _mouse_over_r = 139, _mouse_over_g = 56;
	int _mouse_over_b = 148, _mouse_over_a = 1;
	
	
	
	

	
};

#endif