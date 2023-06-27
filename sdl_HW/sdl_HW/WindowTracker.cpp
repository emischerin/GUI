#include "WindowTracker.h"

void WindowTracker::TrackWindow(SDL_Window* sdl_w, Window* my_w,SDL_Renderer* render)
{
	if (!my_w) return;
	if (!sdl_w) return;
	if (!render) return;

	_sdl_to_my[sdl_w] = my_w;
	_my_to_sdl[my_w] = sdl_w;

	_sdl_win_rndr[sdl_w] = render;
	_my_win_rndr[my_w] = render;

	_all_windows.push_back(my_w);

	int _new_win_index = _all_windows.size() - 1;

	_my_win_indexes[my_w] = _new_win_index;

	
}

Window* WindowTracker::GetMyWindow(SDL_Window* w)
{
	return _sdl_to_my[w];
}

SDL_Window* WindowTracker::GetSDLWindow(Window* w)
{
	return _my_to_sdl[w];
}

SDL_Renderer* WindowTracker::GetWindowRender(SDL_Window* w)
{
	return _sdl_win_rndr[w];
}

SDL_Renderer* WindowTracker::GetWindowRender(Window* w)
{
	return _my_win_rndr[w];
}

std::vector<Window*>* WindowTracker::GetAllWindows() const
{
	return &_all_windows;
}

bool WindowTracker::WindowIsTracked(SDL_Window* w)
{
	return _sdl_to_my.find(w) != _sdl_to_my.end();
}

bool WindowTracker::WindowIsTracked(Window* w)
{
	return _my_to_sdl.find(w) != _my_to_sdl.end();
}