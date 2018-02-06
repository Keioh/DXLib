#pragma once
#include "Object_Base.h"

class Camera3D : public ObjectBase
{
private:
	VECTOR moved_pos = { 0.f,0.f,0.f };
	int wheel;

public:
	void Set(VECTOR pos);
	void Move(float speed);
};