#pragma once
#include "DxLib.h"
#include "Input.h"
#include "Collision.h"
#include "Box3D.h"

class ButtonUI3D
{
private:

public:
	ButtonUI3D();

	Collision triangle3D_collision_1, triangle3D_collision_2;
	Box3D box;

	Input mouse;
	bool click;

	void Init();
	void Load(char* path);
	void Transform(VECTOR scale = { 0.0f,0.0f,0.0f }, float rotate_x = 0.0f, float rotate_y = 0.0f, float rotate_z = 0.0f, VECTOR trans = { 0.0f,0.0f,0.0f });
	void ColliderOff();
	void ColliderOn();

	bool DrawButtonBox3D(bool wire);
};