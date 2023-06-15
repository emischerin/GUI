#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include "Control.h"

class Primitive
{
public:
	virtual void ReactToEvents() {};
	virtual void Draw() = 0;

	IControlAdapter* GetControlAdapter()
	{
		IControlAdapter* adapter = new IControlAdapter(this);
		return adapter;
	}
	

};

class IControlAdapter :public Control
{
public:
	IControlAdapter(Primitive* p)
	{
		if (!p) return;

		_data = p;
	}

	void ReactToEvents() override
	{
		_data->ReactToEvents();
	}

	void Draw() override
	{
		_data->Draw();
	}

	~IControlAdapter()
	{
		delete _data;
	}

private:
	Primitive* _data;


};

class Triangle : public Control
{


	
};

#endif
