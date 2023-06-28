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


protected:
	void RelocatePrimitiveVerticesX(Primitive* p);
	void RelocatePrimitiveVerticesY(Primitive* p);

private:
	std::vector<Primitive*> _primitives;



	void DefineOffsets();

	bool NeedXRelocation(Primitive* p);
	bool NeedYRelocation(Primitive* p);

	/*offsets from window coordinates systems*/
	int _offset_x = 0;
	int _offset_y = 0;

};

#endif

