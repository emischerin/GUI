#include "WindowTracker.h"

void WindowTracker::TrackWindow(SDL_Window* sdl_w, Window* my_w)
{
	_sdl_to_my[sdl_w] = my_w;
	_my_to_sdl[my_w] = sdl_w;
}

Window* WindowTracker::GetMyWindow(SDL_Window* w)
{
	return _sdl_to_my[w];
}

SDL_Window* WindowTracker::GetSDLWindow(Window* w)
{
	return _my_to_sdl[w];
}

bool WindowTracker::WindowIsTracked(SDL_Window* w)
{
	return _sdl_to_my.find(w) != _sdl_to_my.end();
}

bool WindowTracker::WindowIsTracked(Window* w)
{
	return _my_to_sdl.find(w) != _my_to_sdl.end();
}