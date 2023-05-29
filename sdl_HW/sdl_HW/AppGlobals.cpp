#include "AppGlobals.h"

SDL_Renderer* AppGlobals::main_render = nullptr;
SDL_Window* AppGlobals::main_window = nullptr;


SDL_WindowEvent* AppGlobals::window_event = nullptr;
SDL_MouseMotionEvent* AppGlobals::mouse_motion = nullptr;
SDL_MouseButtonEvent* AppGlobals::mouse_button = nullptr;
SDL_ControllerTouchpadEvent* AppGlobals::touchpad_event = nullptr;
SDL_KeyboardEvent* AppGlobals::keyboard_event = nullptr;
Uint8 AppGlobals::mouse_button_code = 0;
Control* selected_control = nullptr;

