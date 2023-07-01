#pragma once
#ifndef ISCENECONTROLLER_H
#define ISCENECONTROLLER_H
#include "Scene.h"


class ISceneController
{
public:
	ISceneController(Scene* scene) : _my_parent_scene(scene) {}


	

private:
	Scene* _my_parent_scene = nullptr;
};
#endif

