#include <SDL.h>

#include <iostream>
#include "XCross.h"
#include "FatRect.h"
#include "InputCaret.h"
#include "MainWindow.h"
#include "Header.h"
#include "Menu.h"



int main(int argc, char** argv)
{
	MainWindow mw(800, 600, "HELLO NORMAL WINDOW!");

	Header* h = new Header(35, 35);
	h->SetColor(62, 19, 66, 1);

	mw.SetHeader(h);

	Menu* m = new Menu(&mw);

	m->SetColor(17, 135, 127,1);

	

	
	return mw.StartLoop(MainWindow::LoopType::SIMPLE_APP);



}