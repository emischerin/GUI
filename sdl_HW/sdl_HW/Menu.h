#pragma once
#ifndef MENU_H
#define MENU_H
#include "Control.h"
#include "Window.h"

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

	Menu(Window* parent_window, MenuPosType pos_type = LEFT);

	void ReactToEvents() override;

	void Draw() override;

	void AdjustToParent() override;

private:

	MenuPosType _pos_type;

	void (Menu::*_draw_impl)();

	void SelectDrawImpl();

	void DrawLeftMenu();
	void DrawRightMenu();
	void DrawTopMenu();
	void DrawBottomMenu();
};

#endif

