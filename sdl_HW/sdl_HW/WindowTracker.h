#ifndef WINDOWTRACKER_H
#define WINDOWTRACKER_H
#include <map>
#include <vector>
#include <SDL.h>


class Window;


class WindowTracker
{
public:
	void TrackWindow(SDL_Window* sdl_w, Window* my_w, SDL_Renderer* render);
	Window* GetMyWindow(SDL_Window* w);
	SDL_Window* GetSDLWindow(Window* w);

	SDL_Renderer* GetWindowRender(SDL_Window* w);
	SDL_Renderer* GetWindowRender(Window* w);

	std::vector<Window*>* GetAllWindows();

	bool WindowIsTracked(SDL_Window* w);
	bool WindowIsTracked(Window* w);

private:
	std::map<SDL_Window*, Window*> _sdl_to_my;
	std::map<Window*, SDL_Window*> _my_to_sdl;

	std::map<SDL_Window*, SDL_Renderer*> _sdl_win_rndr;
	std::map<Window*, SDL_Renderer*> _my_win_rndr;

	std::map<Window*, int> _my_win_indexes;

	std::vector<Window*> _all_windows;
	

};
#endif

