
#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <map>
#include <SDL.h>

#include "AppGlobals.h"
#include "WindowTracker.h"

/*TODO: For each window in program we have corresponding renderer. 
* to be able to have multiple windows we need to change AppGlobals and Window 
* classes a little bit 
* 
*/

class Menu;
class Header;

class Window
{
	friend class Control;
	friend class Window;
	friend class Scene;
	friend class Primitive;

public:
	
	enum WindowSizeState
	{
		MY_SIZE,
		MAXIMIZED,
		MINIMIZED
	};

	Window(int width, int height,const char* title);
	Window(int x, int y, int width, int height, const char* title);


	SDL_Renderer* GetWinRender();
	SDL_Window* GetWinPtr();
	void AddControl(Control* control);
	
	void AddPrimitive(Primitive* primitive);

	virtual void ReactToEvents();

	virtual void Resize(int width,int height);

	virtual void Update();

	virtual void PreDraw();

	void Draw();

	WindowSizeState GetSizeState() const;
	void SetSizeState(WindowSizeState size_state);

	void Maximize();
	void Minimize();
	void SetMySize();

	
	void SetHeader(Header* head);

	void GetWindowSizeAsRect(SDL_Rect* rect) const;

	Header* GetHeader();

	SDL_Texture* GetWindowTexture() const;

	/*
	*DO NOT add menu twice, as you will have nullptr in controls
	* most likely, app will not fail, but it defenetely can
	**/
	void AddMenu(Menu* menu);

	bool HasHeader() const;

	bool HasMenu() const;
	
<<<<<<< HEAD
	/*
	*
	* Experimental mechanism of creating window. TODO: Integrate this into architecture
	*/
	Window* CreateWindow(int x, int y, int width, int height, const char* title);
=======
	int GetWinWidth() const;
	int GetWinHeight() const;

	int GetHeaderHeight();
	int GetMenuWidth();
	
	virtual uint32_t GetCurrentEventType() const;
	virtual SDL_Event* GetCurrentEventPtr();
>>>>>>> right_scrllbar

	~Window();

protected:

<<<<<<< HEAD
	
=======
	virtual void DrawControlsByLayer(std::vector<Control*>* v);
>>>>>>> right_scrllbar

	virtual void InternalReactToEvents();

	virtual void InternalUpdate();

	virtual void CaptureWindowState();

	bool TextureReallocationNeeded();

	void TryReallocateTexture();

	int GetMyPitch();

	static SDL_HitTestResult SDLCALL MoveWindowCallback(SDL_Window* win, const SDL_Point* area, void* data);

	SDL_Texture* _texture = nullptr;

	bool _texture_created = false;

	bool _render_to_texture = false;

	SDL_Renderer* _win_render = nullptr;

	SDL_Window* _win_ptr = nullptr;

	WindowSizeState _size_state = MY_SIZE;

	SDL_Color _background_color;

	std::vector<Control*> _controls;

	std::map<int,std::vector<Control*>> _controls_by_layer;

	std::vector<Primitive*> _primitives;

	std::map<int,std::vector<Primitive*>> _primitives_by_layer;

	Header *_header = nullptr;

	Menu* _menu = nullptr;

	int _width = 0;
	int _height = 0;
	int _x = 0;
	int _y = 0;

	int _saved_x = 0;
	int _saved_y = 0;

	int _saved_width = 0;
	int _saved_height = 0;

	uint32_t _flags = 0;

	const char* _title = nullptr;

	int _header_index = 0;
	int _menu_index = 0;
	
	uint32_t _event_type = 0;
	SDL_Event _current_event;
};
#endif // !WINDOW_H
