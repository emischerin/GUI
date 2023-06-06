#pragma once
#include <vector>
#include <SDL.h>
#include "AppGlobals.h"
#include "Control.h"


class Window
{
public:
	enum WindowSizeState
	{
		MY_SIZE,
		MAXIMIZED,
		MINIMIZED
	};
	SDL_Renderer* GetWinRender();
	SDL_Window* GetWinPtr();
	void AddControl(Control* control);
	
	virtual void ReactToEvents();

	virtual void Resize(int width,int height);

	void Draw();

	WindowSizeState GetSizeState() const;
	void SetSizeState(WindowSizeState size_state);

	void Maximize();
	void Minimize();
	void SetMySize();

protected:

	virtual void InternalReactToEvents();

	SDL_Renderer* _win_render = nullptr;
	SDL_Window* _win_ptr = nullptr;
	WindowSizeState _size_state = MY_SIZE;
	SDL_Color _background_color;
	std::vector<Control*> _controls;
	int _width = 0;
	int _height = 0;
	int _x = 0;
	int _y = 0;
	uint32_t _flags = 0;
	const char* _title = nullptr;
};