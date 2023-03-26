#pragma once
#include <SDL.h>
#include "Control.h"

class FatRect : public Control
{
public:
	FatRect(int x, int y, int w, int h);

	
	void SetColor(int r, int g, int b, int a) override;
	void Draw() override;

	~FatRect();

private:
	int _x, _y, _w, _h;

	SDL_Rect _rect;
	void DrawRects(int rects_count);
	void GetNextRect(SDL_Rect& tmp_rect);
	
};

