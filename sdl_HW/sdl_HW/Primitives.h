#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include "Control.h"

class Primitive
{
public:
	virtual void ReactToEvents() {};
	virtual void Draw() = 0;

};

class IControlAdapter :public Control
{
public:
	IControlAdapter(Primitive* p) : _data(p){}

private:
	Primitive* _data;


};








#endif
