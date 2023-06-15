#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Control.h"
#include "Primitives.h"


class Scene : public Control
{
public:
	void AddChildren(Primitive* p);
	void Draw() override;
private:
	std::vector<Primitive*> _primitives;


};

#endif

