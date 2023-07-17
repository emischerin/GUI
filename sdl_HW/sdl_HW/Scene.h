#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <queue>
#include <algorithm>
#include "Control.h"
#include "Primitives.h"
#include "BaseScrollbar.h"
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

class Viewport;


class Scene : public Control
{
public:

	

	Scene();
	Scene(Viewport* v);
	

	void AddControl(Control* c);
	void AddPrimitive(Primitive* p) override;

	void Update() override;

	void Draw() override;
		
	int GetViewportPositionXInScene();

	int GetViewportPositionYInScene();

	void SetViewport(Viewport* viewport);
	

protected:
	void RelocatePrimitiveVerticesX(Primitive* p);
	void RelocatePrimitiveVerticesY(Primitive* p);
	
	bool SceneTextureNeedsReallocation();

	

private:
	
	bool NeedXRelocation(Primitive* p);
	bool NeedYRelocation(Primitive* p);

	void CreateSceneTexture();

	/*offsets from window coordinates systems*/
	/*Offsets in fact are x & y of the beginning of scene*/
	int _offset_x = 0;
	int _offset_y = 0;

	BaseScrollBar* _scroll_bar = nullptr;
	
	SDL_Rect _viewport_rect = { 0,0,0,1 };

	SDL_Texture* _scene_texture = nullptr;

	SDL_Rect _scene_texture_rect = { 0,0,0,1 };
	
	SDL_Rect _viewport_in_scene = { 0,0,0,1 };
	
	Viewport* _viewport = nullptr;
	


};

#endif

