#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Control.h"
#include "Primitives.h"
#include "Window.h"


class Scene : public Control
{
public:
	Scene(Window* parent_w);
	void AddChildren(Primitive* p);
	void Draw() override;

	~Scene();

private:
	std::vector<Primitive*> _primitives;



	void DefineOffsets();

	bool NeedXOffsetApplication(Primitive* p);
	bool NeedYOffsetApplication(Primitive* p);

	/*offsets from window coordinates systems*/
	int _offset_x = 0;
	int _offset_y = 0;

};

#endif

