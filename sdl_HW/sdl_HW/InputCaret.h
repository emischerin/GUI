#pragma once
#include <SDL.h>
#include "Control.h"
#include "AppGlobals.h"

class InputCaret :public Control
{
public:
	InputCaret(int x, int y);

	InputCaret(int x, int y, int w,int h);

	void SetWidth(int w);
	void SetHeight(int h);
    void SetColor(int r, int g, int b, int a) override;
	void SetInvisibilityColor(int r, int g, int b, int a);
	void SetTimeout(int timeout);
	void Draw() override;

	

private:

	enum CaretState{VISIBLE,INVISIBLE};

	int _x = 0;
	int _y = 0;
	int _w = 1;
	int _h = 1;
	SDL_Rect _rect;

	int _inv_r = 0;
	int _inv_g = 0;
	int _inv_b = 0;
	int _inv_a = 1;
	
	int _timeout = 1000;
	uint32_t _last_tick = 0;

	CaretState _this_state = VISIBLE;

	void SetDrawingColor();

	void SetRect();

	 void SetVisibleState();
	 void SetInvisibleState();

	 void(InputCaret::*_set_state)(void) = &InputCaret::SetVisibleState;
	
};

