#pragma once
#include <map>

#include <SDL.h>


class Window;


class WindowTracker
{
public:
	void TrackWindow(SDL_Window* sdl_w, Window* my_w);
	Window* GetMyWindow(SDL_Window* w);
	SDL_Window* GetSDLWindow(Window* w);

	bool WindowIsTracked(SDL_Window* w);
	bool WindowIsTracked(Window* w);

private:
	std::map<SDL_Window*, Window*> _sdl_to_my;
	std::map<Window*, SDL_Window*> _my_to_sdl;
};

