#include "Menu.h"
#include "Header.h"
#include "AppGlobals.h"

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

	parent_window->AddMenu(this);


}

void Menu::ReactToEvents() 
{
	
	Control::ReactToEvents();

}

void Menu::Draw()
{
	if (_draw_impl) (*this.*_draw_impl)();
}

void Menu::AdjustToParent()
{
	bool parent_has_header = _my_parent_window->HasHeader();

	if (parent_has_header) {
		SDL_Rect parent_rect;
		int header_height = _my_parent_window->GetHeader()->GetHeight();
		_my_parent_window->GetWindowSizeAsRect(&parent_rect);
		
		_bounding_rect.x = 0;
		_bounding_rect.y = header_height;
		_bounding_rect.w = 50; /*TODO WRITE IMPL instead of this test*/
		_bounding_rect.h = parent_rect.h;
		
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
	this->AdjustToParent();

	SDL_SetRenderDrawColor(AppGlobals::main_render, _color.r, _color.g, _color.b, _color.a);

	SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
}

int Menu::GetLayer()
{
	const int layer = 1;
	return layer;
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
