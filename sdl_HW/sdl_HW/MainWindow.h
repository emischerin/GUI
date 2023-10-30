#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Window.h"
#include <SDL_events.h>
#include "AppGlobals.h"
#include "WindowTracker.h"



class MainWindow : public Window
{
public:

	enum LoopType
	{
		HARD_REAL_TIME,
		SIMPLE_APP
	};

	

	MainWindow(int width, int height,const char* w_title);
	MainWindow(int x, int y, int width, int height, const char* w_title);
	

	int StartLoop(MainWindow::LoopType loop_type);
	

	void RequestQuit();

	

	



	 


	 

private:
	
	int _init = 0; /*Result of initalizing video subsystem*/
	
	int InitGraphics();

	/*TODO: it's not tested currently and have different bugs. */
	int HardRealTimeMainLoop();
	int SimpleAppMainLoop();

	void SetBackgroundColor();

	bool _quit = false;
	
	

};

#endif
