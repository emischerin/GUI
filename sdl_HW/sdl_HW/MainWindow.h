#pragma once
#include <sdl.h>
#include <SDL_events.h>

#include <vector>
#include "AppGlobals.h"

#include "Header.h"
#include "Window.h"

class MainWindow : public Window
{
public:

	enum LoopType
	{
		HARD_REAL_TIME,
		SIMPLE_APP
	};

	enum WindowSizeState
	{
		MY_SIZE,
		MAXIMIZED,
		MINIMIZED
	};

	MainWindow(int width, int height,const char* w_title);
	
	int StartLoop(MainWindow::LoopType loop_type);
	

	WindowSizeState GetSizeState() const;
	WindowSizeState SetSizeState(MainWindow::WindowSizeState size_state);
	 
	 

	 

private:
	

	WindowSizeState _size_state;
	
	int InitGraphics();
	int HardRealTimeMainLoop();
	int SimpleAppMainLoop();

	void SetBackgroundColor();

	void Maximize();
	void Minimize();
	void SetMySize();
	

};

