
#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <SDL.h>

#include "AppGlobals.h"
#include "WindowTracker.h"

class Menu;
class Header;

class Window
{
public:
	
	enum WindowSizeState
	{
		MY_SIZE,
		MAXIMIZED,
		MINIMIZED
	};

	Window(int width, int height,const char* title);
	


	SDL_Renderer* GetWinRender();
	SDL_Window* GetWinPtr();
	void AddControl(Control* control);
	
	virtual void ReactToEvents();

	virtual void Resize(int width,int height);

	void Draw();

	WindowSizeState GetSizeState() const;
	void SetSizeState(WindowSizeState size_state);

	void Maximize();
	void Minimize();
	void SetMySize();

	
	void SetHeader(Header* head);

	void GetWindowSizeAsRect(SDL_Rect* rect) const;

	Header* GetHeader();

	void AddMenu(Menu* menu);

	bool HasHeader() const;

	bool HasMenu() const;

	

	

	~Window();

protected:

	virtual void InternalReactToEvents();


	virtual void CaptureWindowState();

	bool TextureReallocationNeeded();

	void TryReallocateTexture();

	static SDL_HitTestResult SDLCALL MoveWindowCallback(SDL_Window* win, const SDL_Point* area, void* data);

	SDL_Texture* _texture = nullptr;

	bool _texture_created = false;

	bool _render_to_texture = false;

	SDL_Renderer* _win_render = nullptr;

	SDL_Window* _win_ptr = nullptr;

	WindowSizeState _size_state = MY_SIZE;

	SDL_Color _background_color;

	std::vector<Control*> _controls;

	Header *_header = nullptr;

	std::vector<Menu*> _menues;

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

	/*
	* Used for drawing on texture
	*/
	SDL_Rect _bounding_rect;

	
};
#endif // !WINDOW_H