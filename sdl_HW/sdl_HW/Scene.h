#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Control.h"
#include "Primitives.h"
#include "Window.h"

/*
* cs = coordinate system
* 
* TODO: Add Vertices relocation modes:
* 
* RAW_SCENE: Actually relocate all vertices from Window coordinate system to scene cs
* 
* NO_RELLOCATION: You supposed to know what you are doing. 
*                 Scene vertices can overlap window elements.
* 
* RELLOCATION_ON_MISTAKE - vertices are in window coordinate system,
*  but mistaken vertices,that overlap window elements will be relocated to scene cs
* 
*/


/*The scene is actually endless, so scroling it requires*/
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
	/*Offsets in fact are x & y of the beginning of scene*/
	int _offset_x = 0;
	int _offset_y = 0;



};

#endif

