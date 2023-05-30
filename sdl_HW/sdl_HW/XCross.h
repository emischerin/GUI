#pragma once
#include <SDL.h>
#include "Primitives.h"
#include "Control.h"
#include "AppGlobals.h"


class XCross: public Control
{


public:
	enum XCrossMode{LINES_ANTIALIASED = 1,RECT_VISIBLE = 2};
	XCross(int& x, int& y,int& w,int& h,XCrossMode mode);
	XCross(SDL_Rect& r, int mode);
	
	void Draw() override;
	
	

	~XCross();

private:
	/*int _x1 = 10;
	int _y1 = 224;
	int _x2 = 84;
	int _y2 = 150;*/

	int _mode;

	int _x1 = 0;
	int _y1 = 0;
	int _x2 = 0;
	int _y2 = 0;


	/*White is default color*/
	

	

	SDL_Rect _bounding_rect;
	MLine line1;
	MLine line2;

	void SetLines();

	
		
	void DrawLinesAliased();
	void DrawLinesAntiAliased();
	
	void FitRectToCross();
	

	
	

	
	



};

