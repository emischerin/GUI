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

	Menu(Control* parent,MenuPosType pos_type = LEFT);

	void ReactToEvents() override;

	void Draw() override;

private:

	MenuPosType _pos_type;

	void (*_draw_impl)(void);


};

#endif

