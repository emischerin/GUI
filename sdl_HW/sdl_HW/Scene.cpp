#include "Scene.h"

Scene::Scene(Window* parent_w) : Control(parent_w)
{
	this->DefineOffsets();
}

void Scene::Draw()
{
	for (int i = 0; i < _primitives.size(); ++i)
		_primitives.at(i)->Draw();
}

void Scene::AddChildren(Primitive* p)
{
	this->DefineOffsets();



	_primitives.push_back(p);
}

void Scene::DefineOffsets()
{
	if (_my_parent_window->HasHeader()) {
		_offset_y = _my_parent_window->GetHeaderHeight();
	}
	else { _offset_y = 0; }

	if (_my_parent_window->HasMenu()) {
		_offset_x = _my_parent_window->GetMenuWidth();
	}
	else { _offset_x = 0; }
}

bool Scene::NeedXOffsetApplication(Primitive* p)
{
	return false;
}

bool Scene::NeedYOffsetApplication(Primitive* p)
{
	return false;
}

Scene::~Scene()
{
	if (_primitives.size() > 0)
		for (auto p : _primitives)
			if (p) delete p;
}