#pragma once
#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include "Control.h"
#include "Primitives.h"


/*
* 
* In fact, scrollbar and scene are very hard task, right now we deside to only 
* make a vertival scroll scene and vertical scrollbar 
* 
*/



class ScrollBarButton;
class ScrollBarCaret;
class Scene;

class ScrollBar : public Control
{
public:


	enum ScrollBarPosition
	{
		DOWN,
		RIGHT
	};

	ScrollBar(Scene* scene,ScrollBarPosition position = RIGHT);

	void SetWidthAndHeight(int width, int height) override;

	void SetPosition(int x, int y) override;

	void ReactToEvents() override;
	void Update() override;
	void Draw() override;


	


	
	

};
#endif

