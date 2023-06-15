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