#include "Menu.h"

Menu::Menu(Control* parent,MenuPosType pos_type) : Control(parent)
{
	_pos_type = pos_type;
	this->SelectDrawImpl();
}

void Menu::ReactToEvents() 
{

}

void Menu::Draw()
{

}

void Menu::SelectDrawImpl()
{
	switch (_pos_type) 
	{
	case LEFT:
		_draw_impl = &Menu::DrawLeftMenu;
		break;
	case RIGHT:
		_draw_impl = &Menu::DrawRightMenu;
		break;
	case TOP:
		_draw_impl = &Menu::DrawTopMenu;
		break;
	case BOTTOM:
		_draw_impl = &Menu::DrawBottomMenu;
		break;
	default:
		_draw_impl = &Menu::DrawLeftMenu;
		break;
	}
}

void Menu::DrawLeftMenu()
{

}

void Menu::DrawRightMenu()
{

}

void Menu::DrawTopMenu()
{

}

void Menu::DrawBottomMenu()
{

}
