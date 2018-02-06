#pragma once
#include <math.h>
#include "Object_Base.h"

class Camera3D : public ObjectBase
{
private:
	VECTOR moved_pos = { 0.f,0.f,0.f };
	VECTOR rotate = { 0.f,0.f,0.f };

	int wheel;

public:	
	
	void Init();
	void Set(VECTOR pos);
	void Move(float speed);
};