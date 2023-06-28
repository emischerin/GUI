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
	MainWindow mw(0,0,800, 600, "HELLO NORMAL WINDOW!");

	Header* h = new Header(35, 35);
	h->SetColor(62, 19, 66, 1);

	mw.SetHeader(h);

	Menu* m = new Menu(&mw);

	m->SetColor(62, 19, 66,20);

	Scene* s = new Scene(&mw);

	
	//Triangle* t = new Triangle(&p, 40, 50);

	Triangle* t = new Triangle(40,50,50,50,Triangle::TriangleDirection::UP);
	Triangle* t1 = new Triangle(100, 100, 50, 50, Triangle::TriangleDirection::DOWN);
	Triangle* t2 = new Triangle(200, 200, 50, 50, Triangle::TriangleDirection::LEFT);
	Triangle* t3 = new Triangle(300, 300, 50, 50, Triangle::TriangleDirection::RIGHT);
	
	s->AddChildren(t);
	s->AddChildren(t1);
	s->AddChildren(t2);
	s->AddChildren(t3);
		
	return mw.StartLoop(MainWindow::LoopType::SIMPLE_APP);



}