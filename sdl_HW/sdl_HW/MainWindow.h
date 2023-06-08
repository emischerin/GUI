#pragma once
#include <sdl.h>
#include <SDL_events.h>

#include <vector>
#include "AppGlobals.h"


#include "Window.h"

class MainWindow : public Window
{
public:

	enum LoopType
	{
		HARD_REAL_TIME,
		SIMPLE_APP
	};

	

	MainWindow(int width, int height,const char* w_title);
	
	

	int StartLoop(MainWindow::LoopType loop_type);
	

	
	 
	 

	 

private:
	

	int _init = 0; /*Result of initalizing video subsystem*/
	
	int InitGraphics();
	int HardRealTimeMainLoop();
	int SimpleAppMainLoop();

	void SetBackgroundColor();

	
	

};

