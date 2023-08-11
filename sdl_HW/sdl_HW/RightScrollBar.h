#pragma once
#ifndef RIGHTSCROLLBAR_H
#define RIGHTSCROLLBAR_H

#include "Control.h"
#include "BaseScrollBar.h"
#include "RightScrollBar.h"
#include "Primitives.h"

/*
* 
* In fact, scrollbar and scene are very hard task, right now we deside to only 
* make a vertival scroll scene and vertical scrollbar 
* 
*/



class ScrollBarButton;
class ScrollBarCaret;


class RightScrollBar : public BaseScrollBar
{
public:
	

	RightScrollBar();
	RightScrollBar(Control* parent);

	

	

	void ReactToEvents() override;
	void Update() override;
	void Draw() override;

	/*!!!!USE WITH CAUSITION!!!!*/
	void TrimMyHeightIfBottomScrollbar();

	virtual void ControlMessagingFunction(ControlMsg* message);
private:
	ScrollBarButton* _up = nullptr;
	ScrollBarButton* _down = nullptr;
	ScrollBarCaret* _caret = nullptr;

	
	

	
	

};
#endif

