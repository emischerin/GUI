#include "Scene.h"

Scene::Scene(Window* parent_w) : Control(parent_w)
{
	this->DefineOffsets();


}

void Scene::Draw()
{
	
	Control::Draw();
	
		
}

void Scene::DrawScrollBar()
{
	if (NeedRightScrollbar()) {
		int w_height = _my_parent_window->GetWinHeight();
		int w_width = _my_parent_window->GetWinWidth();

		_scroll_bar.SetWidthAndHeight(20,w_height - _offset_y);
		_scroll_bar.SetPosition(this->GetX() + this->GetWidth() - _scroll_bar.GetWidth(),_scroll_bar.GetHeight() );

		_scroll_bar.Draw();

	}
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

