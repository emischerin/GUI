#include "Header.h"

Header::Header(int rel_y,int buttons_width)
{
	_rel_y = rel_y;
	_buttons_width = buttons_width;
	_border_line.SetRelativeHeight(rel_y);
	_close_button.SetWidthAndHeight(rel_y - 1, buttons_width);

}

void Header::ImplBehaviour()
{

}
