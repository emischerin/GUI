#include "Scene.h"

Scene::Scene(Window* parent_w) : Control(parent_w)
{
	this->DefineOffsets();
	
	this->SetPosition(_offset_x, _offset_y);
	this->SetWidthAndHeight(parent_w->GetWinWidth() - _offset_x, parent_w->GetWinHeight() - _offset_y);
	
}

void Scene::Update()
{
	this->DefineOffsets();
	this->SetPosition(_offset_x, _offset_y);
	this->SetWidthAndHeight(_my_parent_window->GetWinWidth() - _offset_x, _my_parent_window->GetWinHeight() - _offset_y);

	if (NeedRightScrollbar()) {
		
		if (!_scroll_bar)
			this->CreateScrollBar();

		_scroll_bar->Update();



	}
	else {
		RemoveScrollBar();
	}

	if (_scroll_bar) {
		this->_viewport_rect.x = this->GetX();
		this->_viewport_rect.y = this->GetY();

		this->_viewport_rect.w = this->GetWidth() - _scroll_bar->GetWidth();
		this->_viewport_rect.h = this->GetHeight();
	}

	

}

void Scene::Draw()
{
	if (!_scene_texture) return;


	SDL_SetRenderTarget(_render, _scene_texture);

	Control::Draw();
	
	DrawScrollBar();

	SDL_SetRenderTarget(_render,0);
}



void Scene::SetScrollBarGeometry()
{
	
}

void Scene::DrawScrollBar()
{
	
	if (_scroll_bar) 
		_scroll_bar->Draw();	
	
	
}

bool Scene::NeedBottomScrollbar()
{
	int max_control_x = MaxXControl();
	int max_primitive_x = MaxXPrimitive();
	int my_width = this->GetWidth();

	if ((max_control_x > my_width) || (max_primitive_x > my_width))
		return true;



	return false;
}

bool Scene::NeedRightScrollbar()
{
	int max_control_y = MaxYControl();
	int max_primitive_y = MaxYPrimitive();
	int my_width = this->GetHeight();

	if ((max_control_y > my_width) || (max_primitive_y > my_width))
		return true;

	return false;
}

void Scene::RemoveScrollBar()
{
	if (_scroll_bar) {
		delete _scroll_bar;
		_scroll_bar = nullptr;
	}
}

void Scene::CreateScrollBar()
{
	if (!_scroll_bar) {
		_scroll_bar = new ScrollBar(this);
		_scroll_bar->SetWidthAndHeight(20, this->GetHeight());
	}
}



void Scene::AddControl(Control* parent)
{

}

void Scene::AddPrimitive(Primitive* p)
{
	this->DefineOffsets();

	if (NeedXRelocation(p))
		RelocatePrimitiveVerticesX(p);

	if (NeedYRelocation(p))
		RelocatePrimitiveVerticesY(p);

	_primitives.push_back(p);
}

void Scene::DefineOffsets()
{
	if (_my_parent_window->HasHeader()) {
		_offset_y = _my_parent_window->GetHeaderHeight();
	}
	else { _offset_y = 0; }

	if (_my_parent_window->HasMenu()) {
		_offset_x = _my_parent_window->GetMenuWidth();
	}
	else { _offset_x = 0; }

	
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
	if (_scene_texture)
		SDL_DestroyTexture(_scene_texture);

	if (this->NeedRightScrollbar()) {
		int max_ctrl_y = this->MaxYControl();
		int max_primitive_y = this->MaxYPrimitive();
		int max = std::max(max_ctrl_y, max_primitive_y);

		_scene_texture = SDL_CreateTexture(_render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, _viewport_rect.w, max + 10);
	}
	else
	{
		_scene_texture = SDL_CreateTexture(_render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, _viewport_rect.w, _viewport_rect.h);
	}


}

bool Scene::SceneTextureNeedsReallocation()
{
	if(this->MaxYPrimitive() > )
}