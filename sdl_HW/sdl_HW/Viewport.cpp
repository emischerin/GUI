#include "Viewport.h"

Viewport::Viewport(Window* parent_w) : Control(parent_w)
{
	
	this->Update();

}

void Viewport::Update()
{
	//this->DefineOffsets();
	//this->SetPosition(_offset_x, _offset_y);
	//this->SetWidthAndHeight(_my_parent_window->GetWinWidth() - _offset_x, _my_parent_window->GetWinHeight() - _offset_y);

	//

	//if (NeedRightScrollbar()) {

	//	if (!_right_scroll_bar)
	//		this->CreateRightScrollBar();

	//	_right_scroll_bar->Update();
	//}
	//else {
	//	RemoveRightScrollBar();
	//}

	//if (NeedBottomScrollbar()) {

	//	if (!_bottom_scroll_bar)
	//		this->CreateBottomScrollBar();

	//	_bottom_scroll_bar->Update();



	//}
	//else {
	//	RemoveBottomScrollBar();
	//}
	//
	//if (_right_scroll_bar && _bottom_scroll_bar) {
	//	_right_scroll_bar->Update();

	//}

	//this->SetViewportRect();

}

void Viewport::Draw()
{
	
	

			//DrawScrollBar();
	/*Filling the hole between two scrollbars*/
	/*if (_right_scroll_bar && _bottom_scroll_bar) {
		
		SDL_Color* c = _right_scroll_bar->GetColor();

		SDL_Rect r;
		r.x = _right_scroll_bar->GetX();
		r.y = _right_scroll_bar->GetY() + _right_scroll_bar->GetHeight();
		r.w = _right_scroll_bar->GetWidth();
		r.h = this->GetHeight() - _right_scroll_bar->GetHeight();

		SDL_SetRenderDrawColor(_render, c->r, c->g, c->b, c->a);

		SDL_RenderFillRect(_render, &r);

	}*/

}


void Viewport::DrawScrollBar()
{

	if (_right_scroll_bar)
		_right_scroll_bar->Draw();

	if (_bottom_scroll_bar)
		_bottom_scroll_bar->Draw();


}


void Viewport::DefineOffsets()
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




void Viewport::ControlMessagingFunction(ControlMsg* message)
{
	if (!message) return;

	Viewport::ControlMsgRequest request = (Viewport::ControlMsgRequest)message->_command;

	switch (request)
	{
	case Viewport::ControlMsgRequest::_RIGHT_SCROLLBAR_WIDTH:
		message->_result = _right_scroll_bar ? (void*)_right_scroll_bar->GetWidth() : 0;
		break;
	case Viewport::ControlMsgRequest::_BOTTOM_SCROLLBAR_HEIGHT:
		message->_result = _bottom_scroll_bar ? (void*)_bottom_scroll_bar->GetHeight() : 0;
		break;
	default:
		break;
	}
}

SDL_Rect* Viewport::GetViewportRect() 
{
	return &_viewport_rect;
}


SDL_Rect* Viewport::GetViewportRectInScene()
{
	_viewport_rect_in_scene.x = 0;
	_viewport_rect_in_scene.y = 0;
	_viewport_rect_in_scene.x += _viewport_offset_x;
	_viewport_rect_in_scene.y += _viewport_offset_y;

	_viewport_rect_in_scene.w = _viewport_rect.w;
	_viewport_rect_in_scene.h = _viewport_rect.h;

	return &_viewport_rect_in_scene;
}


Viewport::~Viewport()
{
	Control::~Control();

	//if (this->_scene)
	//	delete _scene;
}



//void Scene::CreateSceneTexture()
//{
//	if (_scene_texture)
//		SDL_DestroyTexture(_scene_texture);
//
//	if (this->NeedRightScrollbar()) {
//		int max_ctrl_y = this->MaxYControl();
//		int max_primitive_y = this->MaxYPrimitive();
//		int max_ctrl_x = this->MaxXControl();
//		int max_primitive_x = this->MaxXPrimitive();
//
//		int max_y = std::max(max_ctrl_y, max_primitive_y);
//		int max_x = std::max(max_ctrl_x, max_primitive_x);
//
//		_scene_texture = SDL_CreateTexture(_render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, max_x + 20, max_y + 20);
//	}
//	else
//	{
//		_scene_texture = SDL_CreateTexture(_render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, _viewport_rect.w, _viewport_rect.h);
//	}
//
//
//}

//bool Scene::SceneTextureNeedsReallocation()
//{
//	if (this->MaxYPrimitive() > _scene_texture_rect.y)
//		return true;
//	if (this->MaxYControl() > _scene_texture_rect.y)
//		return true;
//	if (this->MaxXPrimitive() > _scene_texture_rect.x)
//		return true;
//	if (this->MaxYControl() > _scene_texture_rect.x)
//		return true;
//}
