#pragma once
#include "Object_Base.h"

class Collision : public ObjectBase
{

private:
	int red;
	int blue;
	int green;

public:
	~Collision(){};

	bool hit;
	bool active = true;//コライダーをon、offする変数

	VECTOR mouse_pos_world_near, mouse_pos_world_far;

	HITRESULT_LINE hit3D;

	int size_x;
	int size_y;
	int size_r;

	bool BoxColliderMouse(int position_x, int size_x, int position_y, int size_y, bool wire = false);		//boxあたり判定(点と四角)
	bool CircleColliderMouse(int position_x, int position_y, int size_r , bool wire = false);		//circleあたり判定(点と円)

	bool TriangleColliderMouse3D(VERTEX3D triangle_vertex, VERTEX3D triangle_vertex_2, VERTEX3D triangle_vertex_3, bool wire = false);//3D空間をクリックで判定
};