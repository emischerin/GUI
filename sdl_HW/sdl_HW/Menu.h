#pragma once
#ifndef MENU_H
#define MENU_H
#include "Control.h"

class Menu : public Control
{
public:


	enum MenuPosType
	{
		LEFT,
		RIGHT,
		TOP,
		BOTTOM
	};

	Menu(Control* parent);
};

#endif

