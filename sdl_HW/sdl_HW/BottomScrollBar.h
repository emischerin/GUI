#pragma once
#ifndef BOTTOMSCROLLBAR_H
#define BOTTOMSCROLLBAR_H

#include "Control.h"
#include "BaseScrollBar.h"
#include "Primitives.h"

/*
*
* In fact, scrollbar and scene are very hard task, right now we deside to only
* make a vertival scroll scene and vertical scrollbar
*
*/



class ScrollBarButton;
class ScrollBarCaret;
class Viewport;

class BottomScrollBar : public BaseScrollBar
{
public:


	BottomScrollBar(Viewport* viewport);





	void ReactToEvents() override;
	void Update() override;
	void Draw() override;

private:
	ScrollBarButton* _up = nullptr;
	ScrollBarButton* _down = nullptr;
	ScrollBarCaret* _caret = nullptr;


	Viewport* _viewport = nullptr;




};
#endif

