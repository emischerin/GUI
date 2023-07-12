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

	

	

	void ReactToEvents() override;
	void Update() override;
	void Draw() override;


	
protected:
	virtual void* ControllMessagingFunction(void* arg1) override;

private:
	ScrollBarButton* _up = nullptr;
	ScrollBarButton* _down = nullptr;
	ScrollBarCaret* _caret = nullptr;

	
	Scene* _scene = nullptr;

	
	

};
#endif

