#include "Scene.h"

Scene::Scene(Viewport* v)
{
	this->SetViewport(v);
}


void Scene::Update()
{
		

}

void Scene::Draw()
{
	

	
}

void Scene::AddControl(Control* c)
{
	if (c)
		this->AddChild(c);

	
}

void Scene::AddPrimitive(Primitive* p)
{
	
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

void Scene::CreateSceneTexture()
{
	/*if (_scene_texture)
		SDL_DestroyTexture(_scene_texture);

	if (this->NeedRightScrollbar()) {
		int max_ctrl_y = this->MaxYControl();
		int max_primitive_y = this->MaxYPrimitive();
		int max_ctrl_x = this->MaxXControl();
		int max_primitive_x = this->MaxXPrimitive();

		int max_y = std::max(max_ctrl_y, max_primitive_y);
		int max_x = std::max(max_ctrl_x, max_primitive_x);

		_scene_texture = SDL_CreateTexture(_render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, max_x + 20, max_y + 20);
	}
	else
	{
		_scene_texture = SDL_CreateTexture(_render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, _viewport_rect.w, _viewport_rect.h);
	}*/


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

void Scene::SaveCurrentRenderingState()
{

}

void Scene::RestoreSavedRenderingState()
{

}