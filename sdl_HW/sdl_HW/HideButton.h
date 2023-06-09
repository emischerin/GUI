#pragma once
#ifndef HIDEBUTTON_H
#define HIDEBUTTON_H

#include "Control.h"
#include "CollisionDetector.h"

class HideButton : public Control
{
public:
	HideButton();
	HideButton(SDL_Window* parent);
	HideButton(Control* parent);

	void Draw() override;

	void SetParentControl(Control* parent) override;




	void ReactToEvents() override;
private:
	int _mouse_over_r = 139, _mouse_over_g = 56;
	int _mouse_over_b = 148, _mouse_over_a = 1;
};

#endif

