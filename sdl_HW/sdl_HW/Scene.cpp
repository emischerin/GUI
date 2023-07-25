#include "Scene.h"
#include "Viewport.h"
#include "Window.h"

Scene::Scene(Viewport* v) : Control((Control*)v)
{
	this->SetViewport(v);

	this->CreateDefaultScene();
	
}


void Scene::Update()
{
		

}

void Scene::PreDraw()
{
	this->CreateSceneTexture(300,300);
	this->SaveCurrentRenderingState();
	this->RestoreSavedRenderingState();
}

void Scene::Draw()
{
	

	
}

void Scene::AddControl(Control* c)
{
	if (c) {

	}
		

	
}

void Scene::AddPrimitive(Primitive* p)
{
	
}

bool Scene::ControlOutOfSceneTexture(Control* c)
{
	if (!c) return false;

	int ctrl_x = c->GetX();
	int ctrl_y = c->GetY();
	int ctrl_most_right = ctrl_x + c->GetWidth();
	int ctrl_most_down = ctrl_y + c->GetHeight();

	if (ctrl_x > _viewport_rect.w) return true;
	if (ctrl_y > _viewport_rect.h) return true;
	if (ctrl_most_right > _viewport_rect.w) return true;
	if (ctrl_most_down > _viewport_rect.h) return true;

	return false;
	
}

bool Scene::PrimitiveOutOfSceneTexture(Primitive* p)
{
	if (!p) return false;


}

bool Scene::NeedXRelocation(Primitive* p)
{
	std::vector<SDL_Vertex*> vert_arr = p->GetVertexArray();

	for (int i = 0; i < vert_arr.size(); ++i) {
		if (vert_arr[i]->position.x < _offset_x)
			return true;
	}

	return false;
}

bool Scene::NeedYRelocation(Primitive* p)
{
	std::vector<SDL_Vertex*> vert_arr = p->GetVertexArray();

	for (int i = 0; i < vert_arr.size(); ++i) {
		if (vert_arr[i]->position.y < _offset_y)
			return true;
	}

	return false;
}

void Scene::RelocatePrimitiveVerticesX(Primitive* p)
{
	std::vector<SDL_Vertex*>* v = p->GetVertexArrayPtr();

	for (SDL_Vertex* vert : *v)
		vert->position.x += _offset_x;
}

void Scene::RelocatePrimitiveVerticesY(Primitive* p)
{
	std::vector<SDL_Vertex*>* v = p->GetVertexArrayPtr();

	for (SDL_Vertex* vert : *v)
		vert->position.y += _offset_y;
}

int Scene::GetViewportPositionXInScene()
{
	if (_scene_texture)
	{
		return 666;
	}

	return -1;
	
}

int Scene::GetViewportPositionYInScene()
{
	if (_scene_texture)
	{
		
	}

	return -1;
}

void Scene::CreateSceneTexture(int w,int h)
{
	if (_scene_texture)
		SDL_DestroyTexture(_scene_texture);
	
	_scene_texture = SDL_CreateTexture(_render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);

	this->_scene_texture_rect.w = w;
	this->_scene_texture_rect.h = h;

}

bool Scene::SceneTextureNeedsReallocation()
{
	if (this->MaxYPrimitive() > _scene_texture_rect.y)
		return true;
	if (this->MaxYControl() > _scene_texture_rect.y)
		return true;
	if (this->MaxXPrimitive() > _scene_texture_rect.x)
		return true;
	if (this->MaxYControl() > _scene_texture_rect.x)
		return true;
}

void Scene::SetViewport(Viewport* viewport)
{
	if (viewport)
		_viewport = viewport;
}

void Scene::CreateDefaultScene()
{
	if (this->_viewport) {
		SDL_Rect* viewport_rect = _viewport->GetViewportRect();

		int v_w = viewport_rect->w;
		int v_h = viewport_rect->h;
		
		this->CreateSceneTexture(v_w, v_h);
	}
}

void Scene::SaveCurrentRenderingState()
{
	if (!_scene_texture) return;
	if (!_my_parent_window) return;
	
	this->_saved_texture = _my_parent_window->GetWindowTexture();
	
	SDL_Renderer* win_render = _my_parent_window->GetWinRender();

	if (!win_render) return;

	int set_rndr_target = SDL_SetRenderTarget(win_render,_scene_texture);

	if (set_rndr_target != 0)
		this->RestoreSavedRenderingState();

}

void Scene::RestoreSavedRenderingState()
{
	if (this->_saved_texture) {
		if (this->_scene_texture) {
			if (_my_parent_window) {
				SDL_Renderer* win_render = _my_parent_window->GetWinRender();

				int set_rndr_target = SDL_SetRenderTarget(win_render, _saved_texture);

				if (set_rndr_target != 0) {
					/*LOG IT LATER OR CRASH APP*/
				}
			}
						
		}
		
	}
	
}

void Scene::ResizeTexture(int dw, int dh)
{
	if (_scene_texture)
		SDL_DestroyTexture(_scene_texture);


	int w = _scene_texture_rect.w + dw;
	int h = _scene_texture_rect.h + dh;

	_scene_texture = SDL_CreateTexture(_render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);

	this->_scene_texture_rect.w = w;
	this->_scene_texture_rect.h = h;
}

Scene::~Scene()
{
	Control::~Control();

	if(_scene_texture)
		SDL_DestroyTexture(_scene_texture);
}