#include <SDL.h>

#include <iostream>

#include "FatRect.h"
#include "InputCaret.h"
#include "MainWindow.h"
#include "Header.h"
#include "Menu.h"
#include "Scene.h"
#include "Triangle.h"

int main(int argc, char** argv)
{
	MainWindow mw(800, 600, "HELLO NORMAL WINDOW!");

	Header* h = new Header(35, 35);
	h->SetColor(62, 19, 66, 1);

	mw.SetHeader(h);

	Menu* m = new Menu(&mw);

	m->SetColor(62, 19, 66,20);

	Scene* s = new Scene();

	SDL_FPoint p = { 100,100 };
	Triangle* t = new Triangle(&p, 40, 50);

	s->AddChildren(t);


	mw.AddControl(s);


	

	
	return mw.StartLoop(MainWindow::LoopType::SIMPLE_APP);



}