#include <SDL.h>

#include <iostream>
#include <thread>

#include "FatRect.h"
#include "InputCaret.h"
#include "MainWindow.h"
#include "Header.h"
#include "Menu.h"
#include "Scene.h"
#include "Triangle.h"
#include "Viewport.h"

static int TestMultithreadedWindows()
{
	MainWindow mw(1, 1, 800, 600, "HELLO NORMAL WINDOW!");

	Header* h = new Header(35, 35);
	h->SetColor(62, 19, 66, 1);

	mw.SetHeader(h);

	Menu* m = new Menu(&mw);

	m->SetColor(62, 19, 66, 20);

	//Scene* s = new Scene();


	////Triangle* t = new Triangle(&p, 40, 50);

	//Triangle* t = new Triangle(40, 50, 50, 50, Triangle::TriangleDirection::UP);
	//Triangle* t1 = new Triangle(100, 100, 50, 50, Triangle::TriangleDirection::DOWN);
	//Triangle* t2 = new Triangle(200, 200, 50, 50, Triangle::TriangleDirection::LEFT);
	//Triangle* t3 = new Triangle(300, 300, 50, 50, Triangle::TriangleDirection::RIGHT);

	//s->AddPrimitive(t);
	//s->AddPrimitive(t1);
	//s->AddPrimitive(t2);
	//s->AddPrimitive(t3);

	
	

	return mw.StartLoop(MainWindow::LoopType::SIMPLE_APP);

	
}

int main(int argc, char** argv)
{
	MainWindow mw(0,0,800, 600, "HELLO NORMAL WINDOW!");

	Header* h = new Header(35, 35,&mw);
	h->SetColor(62, 19, 66, 1);
	

	Menu* m = new Menu(&mw);

	m->SetColor(62, 19, 66,20);
	

	Scene* s = new Scene(&mw);

	Triangle* t = new Triangle(150, 300, 55, 55, Triangle::TriangleDirection::UP);
	s->AddControl(t);

	Triangle* t1 = new Triangle(400, 500, 55, 55, Triangle::TriangleDirection::LEFT);
	s->AddControl(t1);


	Triangle* t2 = new Triangle(500, 900, 55, 55, Triangle::TriangleDirection::LEFT);
	s->AddControl(t2);

	Triangle* t3 = new Triangle(1000, 300, 55, 55, Triangle::TriangleDirection::DOWN);
	s->AddControl(t3);
	
	
		
	return mw.StartLoop(MainWindow::LoopType::HARD_REAL_TIME);



}
