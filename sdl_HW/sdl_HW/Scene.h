#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include "Control.h"
#include "Primitives.h"
#include "BaseScrollbar.h"
#include "RightScrollBar.h"
#include "BottomScrollBar.h"


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

	enum ControlMsgRequest
	{
		_RIGHT_SCROLLBAR_WIDTH = 1,
		_BOTTOM_SCROLLBAR_HEIGHT,
		_SCROLL_UP,
		_SCROLL_DOWN,
		_SCENE_HEIGHT,
		_SCENE_WIDTH

	};

	Scene(Window* w);
	Scene(Viewport* v);
	

	void AddControl(Control* c);
	void AddPrimitive(Primitive* p) override;

	void ReactToEvents() override;
	void Update() override;
	void PreDraw() override;
	void Draw() override;
		
	int GetViewportPositionXInScene();

	int GetViewportPositionYInScene();

	int GetSceneHeight();
	int GetSceneWidth();

	void SetViewport(Viewport* viewport);

	bool NeedBottomScrollbar();
	bool NeedRightScrollbar();


	

	bool HasRightScrollBar() const;
	bool HasBottomScrollBar() const;

	void ScrollUp(int step);
	void ScrollDown(int step);
	void ScrollLeft(int step);
	void ScrollRight(int step);

	void ControlMessagingFunction(ControlMsg* message) override;

	~Scene();

protected:
	void RelocatePrimitiveVerticesX(Primitive* p);
	void RelocatePrimitiveVerticesY(Primitive* p);
	
	bool SceneTextureNeedsReallocation();

	void SetThisAsCurrentRenderingTarget();
	void RestoreSavedRenderingState();
	
	void ResizeTexture(int dw, int dh);
	void SetTextureSize(int w, int h);

	void CreateDefaultScene();

	bool ControlOutOfSceneTexture(Control* c);
	bool PrimitiveOutOfSceneTexture(Primitive* p);

	void ResizeTextureToControl(Control* c);
	void ResizeTextureToPrimitive(Primitive* p);

	void CreateRightScrollBar();
	void RemoveRightScrollBar();

	void CreateBottomScrollBar();
	void RemoveBottomScrollBar();
	void UpdateScrollBar();
	void DrawScrollBar();

	void ScrollBarDeduction();
	void ScrollDeduction();
	RightScrollBar* _right_scroll_bar = nullptr;
	BottomScrollBar* _bottom_scroll_bar = nullptr;

	bool _has_bottom_scrollbar = false;
	bool _has_right_scrollbar = false;

	int _scroll_up_lim = 30;
	int _scroll_down_lim = 30;
	int _scroll_left_lim = 30;
	int _scroll_right_lim = 30;
	

private:
	
	bool NeedXRelocation(Primitive* p);
	bool NeedYRelocation(Primitive* p);

	void CreateSceneTexture(int w,int h);

	void UpdateMyBoundingRect();

	/*offsets from window coordinates systems*/
	/*Offsets in fact are x & y of the beginning of scene*/
	int _offset_x = 0;
	int _offset_y = 0;

	
	
	SDL_Rect _viewport_rect = { 0,0,0,1 };

	SDL_Texture* _scene_texture = nullptr;

	SDL_Texture* _saved_texture = nullptr;

	SDL_Rect _scene_texture_rect = { 0,0,0,1 };
	
	SDL_Rect _viewport_in_scene = { 0,0,0,1 };
	
	Viewport* _viewport = nullptr;
	
	SDL_Color _background_color = { 255,255,255,1 };


};

#endif

