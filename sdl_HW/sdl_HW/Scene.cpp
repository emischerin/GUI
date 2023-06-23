#include "Scene.h"

void Scene::Draw()
{
	for (int i = 0; i < _primitives.size(); ++i)
		_primitives.at(i)->Draw();
}

void Scene::AddChildren(Primitive* p)
{
	_primitives.push_back(p);
}

Scene::~Scene()
{
	if (_primitives.size() > 0)
		for (auto p : _primitives)
			if (p) delete p;
}