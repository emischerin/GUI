#include "AppGlobals.h"

SDL_Renderer* AppGlobals::main_render = nullptr;
SDL_Window* AppGlobals::main_window = nullptr;


Control* selected_control = nullptr;
SDL_Event* AppGlobals::event = nullptr;

MainWindow* AppGlobals::my_main_window = nullptr;

WindowTracker* AppGlobals::win_tracker = new WindowTracker();

bool AppGlobals::app_is_inFullscreen = false;

bool AppGlobals::quit_requested = false;