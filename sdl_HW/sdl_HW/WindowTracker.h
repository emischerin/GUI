#pragma once
#include <map>

#include <SDL.h>


class Window;


class WindowTracker
{
public:
	void TrackWindow(SDL_Window* sdl_w, Window* my_w);
	Window* GetMyWindow(SDL_Window* w);
private:
	std::map<SDL_Window*, Window*> _sdl_to_my;
};

