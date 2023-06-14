#include "Menu.h"
#include "Header.h"

Menu::Menu(Control* parent,MenuPosType pos_type) : Control(parent)
{
	_pos_type = pos_type;
	this->SelectDrawImpl();
}

Menu::Menu(Window* parent_window, MenuPosType pos_type) : Control(parent_window)
{
	_pos_type = pos_type;
	this->SelectDrawImpl();
	this->AdjustToParent();


}

void Menu::ReactToEvents() 
{
	
	for (int i = 0; i < _child_controls.size(); ++i) {
		Control* child = _child_controls[i];
		if (child) child->ReactToEvents();
	}

}

void Menu::Draw()
{

}

void Menu::AdjustToParent()
{
	bool parent_has_header = _my_parent_window->HasHeader();

	if (parent_has_header) {
		int header_height = _my_parent_window->GetHeader()->GetHeight();
		this->_bounding_rect.y += header_height;
	}
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
