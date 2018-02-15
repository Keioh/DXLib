#pragma once
#include <math.h>
//#include "Object_Base.h"
#include "Input.h"
#include "Collision.h"

class Camera3D
{
private:
	Input key;

	Collision cursol_move_up;
	Collision cursol_move_down;
	Collision cursol_move_left;
	Collision cursol_move_right;

	VECTOR rotate = { 0.f,0.f,0.f };

	bool mouse_click = false;
	int mouse_x, mouse_y;

	int wheel;

public:	
	VECTOR moved_pos = { 0.f,0.f,0.f };

	void Init();
	void Set(int window_x, int window_y, VECTOR pos, bool wire = false);
	void Move(int window_x, int window_y, float speed, bool wire = false);
};