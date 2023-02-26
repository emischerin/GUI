#include "BorderLine.h"




BorderLine::BorderLine(SDL_Window* w,int rel_x,int rel_y)
{
	this->_window = w;
	_rel_x = rel_x;
	_rel_y = rel_y;
	
}

void BorderLine::SetRelativeCoordinates(int rel_x, int rel_y)
{
	_rel_x = rel_x;
	_rel_y = rel_y;
}


void BorderLine::ImplBehaviour()
{
	int w_pos_x, w_pos_y;

	int w_size_w, w_size_h;

	SDL_GetWindowSize(_window, &w_size_w, &w_size_h);
	SDL_GetWindowPosition(_window, &w_pos_x, &w_pos_y);

	if (w_size_h > w_pos_y) {
		int p1_x = 0;
		int p1_y = _rel_y;
		int p2_x = w_size_w;
		int p2_y = _rel_y;
		int result_set_color = SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);

		if(result_set_color == 0)
			SDL_RenderDrawLine(_renderer, p1_x, p1_y, p2_x, p2_y);
			/*Drawing second line, so the resulting line is fat*/
			//SDL_RenderDrawLine(_renderer, p1_x, p1_y + 1, p2_x, p2_y + 1);
	}


}

