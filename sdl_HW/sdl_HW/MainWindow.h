#pragma once
#include <sdl.h>
#include <vector>
#include "AppGlobals.h"

#include "Header.h"
#include "Window.h"

class MainWindow : public Window
{
public:

	MainWindow(int width, int height,const char* w_title);
	
	int StartLoop();
	
	 
	 

	 

private:
	
	
	

	
	

	
	
	int InitGraphics();
	int MainLoop();

	void SetBackgroundColor();

	void Update();

};

