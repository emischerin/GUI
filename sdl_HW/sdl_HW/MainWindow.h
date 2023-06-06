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
	
	static MainWindow* GetMainWindowPtr();

	int StartLoop(MainWindow::LoopType loop_type);
	

	MainWindow::WindowSizeState GetSizeState() const;
	void SetSizeState(MainWindow::WindowSizeState size_state);
	 
	 

	 

private:
	

	MainWindow::WindowSizeState _size_state = MY_SIZE;
	static MainWindow* _this_ptr;
	int InitGraphics();
	int HardRealTimeMainLoop();
	int SimpleAppMainLoop();

	void SetBackgroundColor();

	void Maximize();
	void Minimize();
	void SetMySize();
	

};

