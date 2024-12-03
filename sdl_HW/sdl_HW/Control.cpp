#include "Control.h"
#include "Primitives.h"
#include "Window.h"

Control::Control(){}



Control::Control(Control* parent)
{
	if (!parent) return;

	_parent_control = parent;

	parent->AddChild(this);

	this->_my_parent_window = _parent_control->GetMyParentWindow();
}

Control::Control(Window* parent_window)
{
	if (!parent_window) return;

	_my_parent_window = parent_window;
	_parent_window = parent_window->GetWinPtr();

	_my_parent_window->AddControl(this);

}


void Control::SetColor(int r, int g, int b, int a)
{
	_color.r = r;
	_color.g = g;
	_color.b = b;
	_color.a = a;
}

void Control::SetColor(SDL_Color* color)
{
	_color.r = color->r;
	_color.g = color->g;
	_color.b = color->b;
	_color.a = color->a;
}


void Control::SetMouseOverColor(SDL_Color* color)
{
	_mouse_over_color.r = color->r;
	_mouse_over_color.g = color->g;
	_mouse_over_color.b = color->b;
	_mouse_over_color.a = color->a;
}

void Control::SetMouseOverColor(int r, int g, int b, int a)
{
	_mouse_over_color.r = r;
	_mouse_over_color.g = g;
	_mouse_over_color.b = b;
	_mouse_over_color.a = a;
}

SDL_Color* Control::GetColor()
{
	return &_color;
}

SDL_Color* Control::GetMouseOverColor()
{
	return &_mouse_over_color;
}


void Control::SetPosition(int x, int y)
{
	_bounding_rect.x = x;
	_bounding_rect.y = y;
}

void Control::SetWidthAndHeight(int w, int h)
{
	_bounding_rect.w = w;
	_bounding_rect.h = h;
}

void Control::SetWidth(int w)
{
	_bounding_rect.w = w;
}

void Control::SetHeight(int h)
{
	_bounding_rect.h = h;
}

void Control::SetBoundingRect(int x, int y, int w, int h)
{
	_bounding_rect.x = x;
	_bounding_rect.y = y;
	_bounding_rect.w = w;
	_bounding_rect.h = h;
}

void Control::SetBoundingRect(SDL_Rect* bounding_rect)
{
	_bounding_rect.x = bounding_rect->x;
	_bounding_rect.y = bounding_rect->y;
	_bounding_rect.w = bounding_rect->w;
	_bounding_rect.h = bounding_rect->h;
}

SDL_Rect* Control::GetBoundingRect()
{
	return &_bounding_rect;
}

void Control::SetParentWindow(SDL_Window* w)
{
	_parent_window = w;

	Window* my_win = AppGlobals::win_tracker->GetMyWindow(w);
	this->SetParentWindow(my_win);


}

void Control::SetParentWindow(Window* w)
{
	_my_parent_window = w;
	_render = w->GetWinRender();

}

void Control::SetParentWindow(Window* my_w, SDL_Window* sdl_w)
{
	this->SetParentWindow(my_w);
	this->SetParentWindow(sdl_w);
}

SDL_Window* Control::GetParentWindow() const
{
	return _parent_window;
}

Window* Control::GetMyParentWindow() const
{
	return _my_parent_window;
}

int Control::GetX() const
{
	return _bounding_rect.x;
}

int Control::GetY() const
{
	return _bounding_rect.y;
}

 int Control::GetWidth() const
{
	return _bounding_rect.w;
}

 int Control::GetHeight() const
{
	return _bounding_rect.h;
}

 void Control::SetParentControl(Control* parent)
 {
	 _parent_control = parent;
	 _my_parent_window = parent->GetMyParentWindow();
	 _render = parent->GetRender();
	 this->SetRenderToChildren(_render);
	 this->SetParentWindowToChildren(_my_parent_window);
	 

 }


 Control* Control::GetParentControl() const
 {
	 return _parent_control;
 }

 void Control::AddChild(Control* child)
 {
	 if (!child) return;
	 child->SetRender(_render);
	 _child_controls.push_back(child);
	 _total_children_width += child->GetWidth();
	 _total_children_height += child->GetHeight();
 }


 void Control::ReactToEvents()
 {
	 for (int i = 0; i < _child_controls.size(); ++i) {
		 Control* c = _child_controls[i];
		 if (c) c->ReactToEvents();
	 }

	 
 }

 void Control::Update()
 {
	 for (Control* c : _child_controls)
		 if (c) c->Update();
	 

 }

 void Control::PreDraw()
 {
	 for (int i = 0; i < _child_controls.size(); ++i) {
		 Control* ctrl = _child_controls[i];
		 if (ctrl) ctrl->PreDraw();
	 }

	 
 }

 void Control::Draw()
 {

	 for (Control* c : _child_controls)
		 if (c) c->Draw();

	
 }

 void Control::AdjustToParent() {}
 void Control::AdjustChildren() {}

 int Control::MinXControl()
 {
	 if (_child_controls.size() == 0) return -1;

	 auto _control_by_x = [](Control* c1, Control* c2)
	 {
		 return (c1->GetX() < c2->GetX());
	 };

	 auto it = _child_controls.begin();

	 std::nth_element(_child_controls.begin(), it, _child_controls.end(), _control_by_x);

	 return (*it)->GetX();
 }

 int Control::MaxXControl()
 {
	 if (_child_controls.size() == 0) return -1;

	 auto _control_by_x = [](Control* c1, Control* c2)
	 {
		 return (c1->GetX() > c2->GetX());
	 };

	 auto it = _child_controls.begin();

	 std::nth_element(_child_controls.begin(), it, _child_controls.end(), _control_by_x);

	 return (*it)->GetX();
 }



 int Control::MinYControl()
 {
	 if (_child_controls.size() == 0) return INT_MIN;

	 auto _control_by_y = [](Control* c1, Control* c2)
	 {
		 return (c1->GetY() < c2->GetY());
	 };

	 auto it = _child_controls.begin();

	 std::nth_element(_child_controls.begin(), it, _child_controls.end(), _control_by_y);

	 return (*it)->GetY();
 }

 int Control::MaxYControl()
 {
	 if (_child_controls.size() == 0) return INT_MIN;

	 auto _control_by_y = [](Control* c1, Control* c2)
	 {
		 return (c1->GetY() > c2->GetY());
	 };

	 auto it = _child_controls.begin();

	 std::nth_element(_child_controls.begin(), it, _child_controls.end(), _control_by_y);

	 return (*it)->GetY();
 }
 
  int Control::MinYObject()
  {
	 return MinYControl();
	  
  }

  int Control::MaxYObject()
  {
	  return MaxYControl();
	  
  }

  int Control::MaxXObject()
  {
	  return MaxXControl();
	    
  }

  int Control::MinXObject()
  {
	  return MaxXControl();
	  
  }

  void Control::ResizeWidth(int dx)
  {
	  _bounding_rect.w += dx;
  }

  void Control::ResizeHeight(int dy)
  {
	  _bounding_rect.h += dy;
  }

  int Control::GetLayer()
  {
	  const int layer = -5;
	  return layer;
  }

  void Control::MoveUp(int step)
  {
	  this->_bounding_rect.y -= step;

	  
  }

  void Control::MoveDown(int step)
  {
	  this->_bounding_rect.y += step;
  }
 
  void Control::MoveLeft(int step)
  {
	  this->_bounding_rect.x -= step;
  }

  void Control::MoveRight(int step)
  {
	  this->_bounding_rect.x += step;
  }

  

  Control::~Control()
  {
	  
	  for (Control* c : _child_controls)
		  if (c) delete c;

  }

  void Control::ControlMessagingFunction(ControlMsg* message) {}

  void Control::RemoveChild(Control* c)
  {
	  if (_child_controls.size() < 1) return;

	  for (auto it = _child_controls.begin(); it != _child_controls.end(); ++it) {
		  if (c == *it) {
			  _child_controls.erase(it);
			  delete c;
			  c = 0;
			  break;
		  }

	  }
  }

  

  SDL_Renderer* Control::GetRender() { return _render; }

  void Control::SetRender(SDL_Renderer* render)
  {
	  _render = render;
	  this->SetRenderToChildren(render);
  }

  void Control::SetRenderToChildren(SDL_Renderer* render)
  {
	  for (int i = 0; i < _child_controls.size(); ++i) {
		  Control* c = _child_controls[i];
		  if (c) c->SetRender(render);
	  }

	  
  }

  void Control::SetParentWindowToChildren(Window* w)
  {
	  for (int i = 0; i < _child_controls.size(); ++i) {
		  Control* c = _child_controls[i];
		  if (c) c->_my_parent_window = _my_parent_window;
	  }
	  	
  }

  std::vector<SDL_Point> Control::GetAllBoundingRectPoints()
  {
	  std::vector<SDL_Point> result;
	  
	  SDL_Point p1;
	  p1.x = _bounding_rect.x;
	  p1.y = _bounding_rect.y;

	  SDL_Point p2;
	  p2.x = _bounding_rect.x + _bounding_rect.w;
	  p2.y = _bounding_rect.y;

	  SDL_Point p3;
	  p3.x = _bounding_rect.x;
	  p3.y = _bounding_rect.y + _bounding_rect.h;

	  SDL_Point p4;
	  p4.x = _bounding_rect.x + _bounding_rect.w;
	  p4.y = _bounding_rect.y + _bounding_rect.h;

	  result.push_back(p1);
	  result.push_back(p2);
	  result.push_back(p3);
	  result.push_back(p4);

	  return result;
  }