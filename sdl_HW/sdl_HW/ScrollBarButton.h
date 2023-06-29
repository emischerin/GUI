#pragma once
#ifndef SCROLLBARBUTTON_H
#define SCROLLBARBUTTON_H
#include "Button.h"

class ScrollBarButton: public Button
{
public:

	void ReactToEvents() override;
	void Draw() override;

private:

};
#endif

