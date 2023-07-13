#include "Viewport.h"

Viewport::Viewport(Window* parent_w) : Control(parent_w)
{
	



}

void Viewport::Update()
{
	this->DefineOffsets();
	this->SetPosition(_offset_x, _offset_y);
	this->SetWidthAndHeight(_my_parent_window->GetWinWidth() - _offset_x, _my_parent_window->GetWinHeight() - _offset_y);

	if (NeedRightScrollbar()) {

		if (!_right_scroll_bar)
			this->CreateRightScrollBar();

		_right_scroll_bar->Update();



	}
	else {
		RemoveRightScrollBar();
	}

	if (NeedBottomScrollbar()) {

		if (!_bottom_scroll_bar)
			this->CreateBottomScrollBar();

		_bottom_scroll_bar->Update();



	}
	else {
		RemoveBottomScrollBar();
	}
	



}

void Viewport::Draw()
{
	
	Control::Draw();
	
	DrawScrollBar();


}





void Viewport::DrawScrollBar()
{

	if (_right_scroll_bar)
		_right_scroll_bar->Draw();


}

void Viewport::SetViewportRect()
{
	this->_viewport_rect = _bounding_rect;

	if (_has_right_scrollbar) {
		_viewport_rect.w -= _right_scroll_bar->GetWidth();
	}

	if (_has_bottom_scrollbar) {
		_viewport_rect.h -= _right_scroll_bar->GetHeight();
	}
	
	
}

bool Viewport::NeedBottomScrollbar()
{
	int max_control_x = MaxXControl();
	int max_primitive_x = MaxXPrimitive();
	int my_width = this->GetWidth();

	if ((max_control_x > my_width) || (max_primitive_x > my_width))
		return true;



	return false;
}

bool Viewport::HasRightScrollBar() const
{
	return _right_scroll_bar != nullptr;
}

bool Viewport::HasBottomScrollBar() const
{
	return _bottom_scroll_bar != nullptr;
}

bool Viewport::NeedRightScrollbar()
{
	int max_control_y = MaxYControl();
	int max_primitive_y = MaxYPrimitive();
	int my_width = this->GetHeight();

	if ((max_control_y > my_width) || (max_primitive_y > my_width))
		return true;

	return false;
}
void Viewport::CreateRightScrollBar()
{
	if (!_right_scroll_bar) {
		_right_scroll_bar = new ScrollBar(this);
		_right_scroll_bar->SetWidthAndHeight(20, this->GetHeight());
		this->_has_right_scrollbar = true;
	}
}

void Viewport::RemoveRightScrollBar()
{
	if (_right_scroll_bar) {
		delete _right_scroll_bar;
		_right_scroll_bar = nullptr;
		this->_has_right_scrollbar = false;
	}
}

void Viewport::CreateBottomScrollBar()
{
	if (!_bottom_scroll_bar) {
		_bottom_scroll_bar = new ScrollBar(this);
		_bottom_scroll_bar->SetWidthAndHeight(20, this->GetWidth());
		this->_has_right_scrollbar = true;
	}
}

void Viewport::RemoveBottomScrollBar()
{
	if (_bottom_scroll_bar) {
		delete _bottom_scroll_bar;
		_bottom_scroll_bar = nullptr;
		this->_has_bottom_scrollbar = false;
	}
}





void Viewport::AddControl(Control* parent)
{
	
}

void Viewport::AddPrimitive(Primitive* p)
{
	
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
