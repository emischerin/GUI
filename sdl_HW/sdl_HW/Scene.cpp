#include "Scene.h"
#include "Viewport.h"
#include "Window.h"

Scene::Scene(Window* w) : Control(w)
{
	_right_scroll_bar = new RightScrollBar();
	_right_scroll_bar->SetParentControl(this);

	_bottom_scroll_bar = new BottomScrollBar();
	_bottom_scroll_bar->SetParentControl(this);


}

Scene::Scene(Viewport* v) : Control((Control*)v)
{
	this->SetViewport(v);
	
	
	
}

void Scene::ReactToEvents()
{
	CollisionDetector cd;

	if (!cd.MouseInControl(this)) return;
	
	_right_scroll_bar->ReactToEvents();
	
	_bottom_scroll_bar->ReactToEvents();

	Control::ReactToEvents();

	ScrollDeduction();


}

void Scene::ScrollDeduction()
{
	
	
	SDL_Event* t = _my_parent_window->GetCurrentEventPtr();

	if (t->type == SDL_MOUSEWHEEL) {
		//int wheel_y = t->wheel.y;
		float wheel_y = t->wheel.preciseY;
		
		
		if (wheel_y > 0 ) {
			this->ScrollDown(5);
		}
		else if(wheel_y < 0) {
			this->ScrollUp(5);
		}
	}
}

void Scene::Update()
{
	

	this->UpdateMyBoundingRect();
	
	Control::Update();

	this->UpdateScrollBar();



}

void Scene::PreDraw()
{
	
	
}

void Scene::UpdateScrollBar()
{

	_need_right_scrollbar = NeedRightScrollbar();
	_need_bottom_scrollbar = NeedBottomScrollbar();
		
	_right_scroll_bar->Update();
	_bottom_scroll_bar->Update();
}

void Scene::Draw()
{
	SDL_Rect current_clip_rect;
	bool clip_set = SDL_RenderIsClipEnabled(_render);

	if (clip_set) 
		SDL_RenderGetClipRect(_render, &current_clip_rect);
	
		
	SDL_RenderSetClipRect(_render, &_bounding_rect);

	
	SDL_SetRenderDrawColor(_render, _background_color.r,_background_color.g,_background_color.b,_background_color.a);
	SDL_RenderFillRect(_render,&_bounding_rect );
	
	Control::Draw();

	

	this->DrawScrollBar();

	if (clip_set) {
		SDL_RenderSetClipRect(_render, &current_clip_rect);
	}
	else {
		SDL_RenderSetClipRect(_render, 0);
	}
	
	
	
	
	
	
}

void Scene::AddControl(Control* c)
{
	if (c) {

		c->SetRender(_render);
		c->SetParentWindow(_my_parent_window);
		c->SetParentControl(this);
		Control::AddChild(c);
				
	}
		

	
}



void Scene::AddObject(Control* c)
{
	this->AddControl(c);
}
void Scene::AddObject(Primitive* p)
{
	this->AddPrimitive(p);
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
	CollisionDetector cd;

	if (!cd.AllControlsYInControl(_child_controls, this)) {
		return true;
	}
		

	return false;
}


bool Scene::NeedBottomScrollbar()
{
	CollisionDetector cd;

	if (!cd.AllControlsXInControl(_child_controls, this)) {
		return true;
	}
		

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
	

	if (_need_right_scrollbar)
		_right_scroll_bar->Draw();

	if (_need_bottom_scrollbar)
		_bottom_scroll_bar->Draw();

	if (_need_right_scrollbar && _need_bottom_scrollbar) {

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
	
	if (this->MaxYControl() > _scene_texture_rect.y)
		return true;
	
	if (this->MaxYControl() > _scene_texture_rect.x)
		return true;

	return false;
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
	case Scene::ControlMsgRequest::_BOTTOM_SCROLLBAR_DEDUCTION:
		message->_result = _bottom_scroll_bar ? (void*)_bottom_scroll_bar->GetHeight() : 0;
		message->_result2 = (void*)_need_bottom_scrollbar;
		break;
	case Scene::ControlMsgRequest::_SCROLL_UP:
		this->ScrollUp(10);
		break;
	case Scene::ControlMsgRequest::_SCROLL_DOWN:
		this->ScrollDown(10);
	case Scene::ControlMsgRequest::_SCENE_HEIGHT:
		message->_result = (void*)this->GetSceneHeight();
		break;
	case Scene::ControlMsgRequest::_SCENE_WIDTH:
		message->_result = (void*)this->GetSceneWidth();
		break;
	default:
		break;
	}
}

void Scene::ScrollUp(int step)
{
	int max_y_obj = MaxYObject();
	
	int obj_max_y = (this->GetY() + this->GetHeight()) - 150;


	if (max_y_obj == INT_MIN) return;

	if (max_y_obj < obj_max_y) return;


	for (int i = 0; i < _child_controls.size(); ++i) {
		Control* c = _child_controls[i];
		if (c) c->MoveUp(step);
	}

	
	
}

void Scene::ScrollDown(int step)
{
	int min_y_obj = MinYObject();
	int max_obj_y = this->GetY() + 50;

	if (min_y_obj == INT_MIN) return;

	if (min_y_obj > max_obj_y) return;


	for (int i = 0; i < _child_controls.size(); ++i) {
		Control* c = _child_controls[i];
		if (c) c->MoveDown(step);
	}

	
	
}


void Scene::ScrollRight(int step)
{
	int min_x_obj = this->MinXObject();
	int min_obj_x = this->GetX() + 50;

	if (min_x_obj == INT_MIN) return;

	if (min_x_obj > min_obj_x) return;
	
	for (int i = 0; i < _child_controls.size(); ++i) {
		Control* c = _child_controls[i];
		if (c) c->MoveRight(step);
	}

	
	
}


void Scene::ScrollLeft(int step)
{
	int max_x_obj = this->MaxXObject();
	int max_obj_x = (this->GetX() + this->GetWidth()) - 50;

	if (max_x_obj == INT_MIN) return;

	if (max_x_obj > max_obj_x) return;

	for (int i = 0; i < _child_controls.size(); ++i) {
		Control* c = _child_controls[i];
		if (c) c->MoveLeft(step);
	}

	
}

int Scene::GetSceneHeight()
{
	int min_y = this->MinYObject();
	int max_y = this->MaxYObject();

	if ((min_y != INT_MIN) && (max_y != INT_MIN)) {
		if (min_y == max_y) 
			return max_y;
		else return max_y - min_y;
	}
	else if ((min_y == INT_MIN) && (max_y == INT_MIN)) {
		return 0;
	}
	else if ((min_y == INT_MIN) && (max_y != INT_MIN)) {
		return max_y;
	}
	else if ((min_y != INT_MIN) && (max_y == INT_MIN)) {
		return min_y;
	}
	
	return 0;
	
	

}

int Scene::GetSceneWidth()
{
	
	int min_x = this->MinXObject();
	int max_x = this->MaxXObject();

	if ((min_x != INT_MIN) && (max_x != INT_MIN)) {
		if (min_x == max_x)
			return max_x;
		else return max_x - min_x;
	}
	else if ((min_x == INT_MIN) && (max_x == INT_MIN)) {
		return 0;
	}
	else if ((min_x == INT_MIN) && (max_x != INT_MIN)) {
		return max_x;
	}
	else if ((min_x != INT_MIN) && (max_x == INT_MIN)) {
		return min_x;
	}

	return 0;
}

void Scene::ScrollBarDeduction()
{
	

}

bool Scene::AllObjectsYVisible()
{
	CollisionDetector cd;

	if (cd.AllControlsYInControl(_child_controls, this)) {
			return false;
		}
	else {
		return true;
	}
		
		
	
		
}

bool Scene::AllObjectXVisible()
{
	return true;
}

Scene::~Scene()
{
	Control::~Control();
	delete _right_scroll_bar;
	delete _bottom_scroll_bar;
	
}