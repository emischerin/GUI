
#ifndef RESIZEBUTTON_H
#define RESIZEBUTTON_H

#pragma once
#include "Control.h"

#include "CollisionDetector.h"




class ResizeButton : public Control
{
public:
	ResizeButton();
	ResizeButton(Control* parent);
	void ReactToEvents() override;
	void Draw() override;
	void SetParentControl(Control* parent) override;
private:

	bool _fullscreen = false;


	int _mouse_over_r = 139, _mouse_over_g = 56;
	int _mouse_over_b = 148, _mouse_over_a = 1;
	
	void DrawMaximizeButton();
	void DrawSetMySizeButton();



};

#endif