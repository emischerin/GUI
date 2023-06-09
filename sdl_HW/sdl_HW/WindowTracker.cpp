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