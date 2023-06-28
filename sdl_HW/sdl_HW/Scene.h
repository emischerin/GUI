#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Control.h"
#include "Primitives.h"

class Window;

class Scene : public Control
{
public:
	Scene(Window* parent_w);
	void AddChildren(Primitive* p);
	void Draw() override;

	~Scene();

private:
	std::vector<Primitive*> _primitives;


};

#endif

