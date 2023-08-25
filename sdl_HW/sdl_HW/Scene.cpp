#include "Scene.h"
#include "Viewport.h"
#include "Window.h"

Scene::Scene(Window* w) : Control(w)
{

}

Scene::Scene(Viewport* v) : Control((Control*)v)
{
	this->SetViewport(v);
	
	
	
}

void Scene::ReactToEvents()
{
	if (_right_scroll_bar)
		_right_scroll_bar->ReactToEvents();
	if (_bottom_scroll_bar)
		_bottom_scroll_bar->ReactToEvents();

	Control::ReactToEvents();

}

void Scene::Update()
{
	

	this->UpdateMyBoundingRect();
	
	this->_scroll_up_lim = (this->GetY() + this->GetHeight()) - 10;
	this->_scroll_down_lim = this->GetY() + 10;
	this->_scroll_left_lim = _my_parent_window->GetWinWidth() - 40;
	this->_scroll_right_lim = _my_parent_window->GetMenuWidth() + 40;

	Control::Update();

	this->UpdateScrollBar();



}

void Scene::PreDraw()
{
	
	
}

void Scene::UpdateScrollBar()
{
	if (_right_scroll_bar)
		_right_scroll_bar->Update();

	if (_bottom_scroll_bar)
		_bottom_scroll_bar->Update();
}

void Scene::Draw()
{
	
	
	
	SDL_SetRenderDrawColor(_render, _background_color.r,_background_color.g,_background_color.b,_background_color.a);
	SDL_RenderFillRect(_render,&_bounding_rect );
	
	Control::Draw();

	this->DrawScrollBar();
	
	
	
}

void Scene::AddControl(Control* c)
{
	if (c) {

		c->SetRender(_render);
		c->SetParentWindow(_my_parent_window);
		c->SetParentControl(this);

		if (ControlOutOfSceneTexture(c)) {
			//this->ResizeTextureToControl(c);
			Control::AddChild(c);
		}
		else {
			Control::AddChild(c);
		}

		this->ScrollBarDeduction();
	}
		

	
}

void Scene::AddPrimitive(Primitive* p)
{
	if (p) {

		p->SetRender(_render);
		p->SetParentControl(this);
		p->SetParentWindow(_my_parent_window);

		if (PrimitiveOutOfSceneTexture(p)) {
			//this->ResizeTextureToPrimitive(p);
			Control::AddPrimitive(p);
		}
		else {
			Control::AddPrimitive(p);
		}

		this->ScrollBarDeduction();
	}
}

void Scene::ResizeTextureToControl(Control* c)
{
	if (!c) return;
	
	const int offset_x = 25;
	const int offset_y = 25;

	int result_width, result_height;

	int most_right = c->GetX() + c->GetWidth();
	int most_down = c->GetY() + c->GetHeight();

	if (most_right >= _scene_texture_rect.w) {
		result_width = most_right + offset_x;
	}
	else {
		result_width = _scene_texture_rect.w;
	}

	if (most_down >= _scene_texture_rect.h) {
		result_height = most_down + offset_y;
	} 
	else{
		result_height = _scene_texture_rect.h;
	}

	//this->SetTextureSize(result_width,result_height);
	
	
	
		
}

void Scene::ResizeTextureToPrimitive(Primitive* p)
{
	if (!p) return;

	const int offset_x = 25;
	const int offset_y = 25;

	int result_width, result_height;

	int most_right = p->MaxXVertex();
	int most_down = p->MaxYVertex();

	if (most_right >= _scene_texture_rect.w) {
		result_width = most_right + offset_x;
	}
	else {
		result_width = _scene_texture_rect.w;
	}

	if (most_down >= _scene_texture_rect.h) {
		result_height = most_down + offset_y;
	}
	else {
		result_height = _scene_texture_rect.h;
	}

	//this->SetTextureSize(result_width, result_height);
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
	if (!_viewport) return false;

	int primitive_max_x = p->MaxXVertex();
	int primitive_max_y = p->MaxYVertex();
	SDL_Rect* viewport_rect = _viewport->GetViewportRect();

	if (primitive_max_x > viewport_rect->w) return true;
	if (primitive_max_y > viewport_rect->h) return true;

	return false;
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

bool Scene::NeedRightScrollbar()
{

	
	

	int max_control_y = this->MaxYControl();
	int max_primitive_y = this->MaxYPrimitive();
	int my_height = this->GetHeight();

	if ((max_control_y > my_height) || (max_primitive_y > my_height))
		return true;

	return false;
}


bool Scene::NeedBottomScrollbar()
{



	int max_control_x = this->MaxXControl();
	int max_primitive_x = this->MaxXPrimitive();
	int my_width = this->GetWidth();

	if ((max_control_x > my_width) || (max_primitive_x > my_width))
		return true;


	return false;
}

bool Scene::HasRightScrollBar() const
{
	return _right_scroll_bar != nullptr;
}

bool Scene::HasBottomScrollBar() const
{
	return _bottom_scroll_bar != nullptr;
}

void Scene::CreateRightScrollBar()
{
	if (!_right_scroll_bar) {
		_right_scroll_bar = new RightScrollBar();
		_right_scroll_bar->SetParentControl(this);
		this->_has_right_scrollbar = true;


	}
}

void Scene::RemoveRightScrollBar()
{
	if (_right_scroll_bar) {
		
		delete _right_scroll_bar;
		_right_scroll_bar = nullptr;
		this->_has_right_scrollbar = false;

	}
}

void Scene::CreateBottomScrollBar()
{
	if (!_bottom_scroll_bar) {
		_bottom_scroll_bar = new BottomScrollBar();
		_bottom_scroll_bar->SetParentControl(this);
		this->_has_right_scrollbar = true;

	}
}

void Scene::RemoveBottomScrollBar()
{
	if (_bottom_scroll_bar) {
		
		delete _bottom_scroll_bar;
		_bottom_scroll_bar = nullptr;
		this->_has_bottom_scrollbar = false;
	}
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

void Scene::DrawScrollBar()
{
	if (_right_scroll_bar)
		_right_scroll_bar->Draw();

	if (_bottom_scroll_bar)
		_bottom_scroll_bar->Draw();

	if (_right_scroll_bar && _bottom_scroll_bar) {

		SDL_Color* c = _right_scroll_bar->GetColor();

		SDL_Rect r;
		r.x = _right_scroll_bar->GetX();
		r.y = _right_scroll_bar->GetY() + _right_scroll_bar->GetHeight();
		r.w = _right_scroll_bar->GetWidth();
		r.h = this->GetHeight() - _right_scroll_bar->GetHeight();

		SDL_SetRenderDrawColor(_render, c->r, c->g, c->b, c->a);

		SDL_RenderFillRect(_render, &r);

	}
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
		
		//this->CreateSceneTexture(v_w, v_h);
	}
}

/*This function sets scene texture as current render target and saves window rendering params*/
void Scene::SetThisAsCurrentRenderingTarget()
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

void Scene::SetTextureSize(int w, int h)
{
	if (_scene_texture)
		SDL_DestroyTexture(_scene_texture);

	_scene_texture = SDL_CreateTexture(_render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
	
	this->_scene_texture_rect.w = w;
	this->_scene_texture_rect.h = h;

}

void Scene::UpdateMyBoundingRect()
{
	if (_my_parent_window->HasHeader()) {
		_offset_y = _my_parent_window->GetHeaderHeight();
	}
	else { _offset_y = 0; }

	if (_my_parent_window->HasMenu()) {
		_offset_x = _my_parent_window->GetMenuWidth();
	}
	else { _offset_x = 0; }


	SDL_Rect w_rect;

	_my_parent_window->GetWindowSizeAsRect(&w_rect);

	_bounding_rect.x = _offset_x;
	_bounding_rect.y = _offset_y;
	_bounding_rect.w = w_rect.w - _offset_x;
	_bounding_rect.h = w_rect.h - _offset_y;

	
}

void Scene::ControlMessagingFunction(ControlMsg* message)
{
	if (!message) return;

	Scene::ControlMsgRequest request = (Scene::ControlMsgRequest)message->_command;

	switch (request)
	{
	case Scene::ControlMsgRequest::_RIGHT_SCROLLBAR_WIDTH:
		message->_result = _right_scroll_bar ? (void*)_right_scroll_bar->GetWidth() : 0;
		break;
	case Scene::ControlMsgRequest::_BOTTOM_SCROLLBAR_HEIGHT:
		message->_result = _bottom_scroll_bar ? (void*)_bottom_scroll_bar->GetHeight() : 0;
		break;
	case Scene::ControlMsgRequest::_SCROLL_UP:
		this->ScrollDown(5);
		break;
	case Scene::ControlMsgRequest::_SCROLL_DOWN:
		this->ScrollUp(5);
	default:
		break;
	}
}

void Scene::ScrollUp(int step)
{
	int max_y_obj = MaxYObject();
		
	for (int i = 0; i < _child_controls.size(); ++i) {
		Control* c = _child_controls[i];
		if (c) c->MoveUp(step);
	}

	for (int i = 0; i < _primitives.size(); ++i) {
		Primitive* p = _primitives[i];
		if (p) p->MoveUp(step);
	}
	
}

void Scene::ScrollDown(int step)
{
	int min_y_obj = MinYObject();
		
	for (int i = 0; i < _child_controls.size(); ++i) {
		Control* c = _child_controls[i];
		if (c) c->MoveDown(step);
	}

	for (int i = 0; i < _primitives.size(); ++i) {
		Primitive* p = _primitives[i];
		if (p) p->MoveDown(step);
	}
	
}

void Scene::ScrollRight(int step)
{
	int min_x_ctrl = this->MinXControl();
	int min_x_primitive = this->MinXPrimitive();


	if (min_x_ctrl <= _scroll_right_lim && min_x_primitive <= _scroll_right_lim) {
		for (int i = 0; i < _child_controls.size(); ++i) {
			Control* c = _child_controls[i];
			if (c) c->MoveRight(step);
		}

		for (int i = 0; i < _primitives.size(); ++i) {
			Primitive* p = _primitives[i];
			if (p) p->MoveRight(step);
		}
	}
}

void Scene::ScrollLeft(int step)
{
	int max_x_ctrl = this->MaxXControl();
	int max_x_primitive = this->MaxXPrimitive();


	if (max_x_ctrl >= _scroll_left_lim && max_x_primitive >= _scroll_left_lim) {
		for (int i = 0; i < _child_controls.size(); ++i) {
			Control* c = _child_controls[i];
			if (c) c->MoveLeft(step);
		}

		for (int i = 0; i < _primitives.size(); ++i) {
			Primitive* p = _primitives[i];
			if (p) p->MoveLeft(step);
		}
	}
}

void Scene::ScrollBarDeduction()
{
	if (NeedRightScrollbar()) {
		this->CreateRightScrollBar();
	}
	else
	{
		RemoveRightScrollBar();
	}

	if (NeedBottomScrollbar()) {
		this->CreateBottomScrollBar();
	}
	else
	{
		RemoveBottomScrollBar();
	}

}

Scene::~Scene()
{
	Control::~Control();
	ScrollBarDeduction();
	
}