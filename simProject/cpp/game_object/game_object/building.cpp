#include "building.h"


void Building::Init()
{
	bulidng_object.Init();
}

void Building::Load()
{
	bulidng_object.Load("pack/GameObject/models/buliding.png");
}

void Building::Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos)
{
	bulidng_object.Transform(scale, rote_x, rote_y, rote_z, pos);
}

void Building::Draw(bool wire)
{
	bulidng_object.DrawButtonBox3D(wire);

	//どちらかのコライダーにマウスがヒットしていたら
	if ((bulidng_object.hit1 == true) || (bulidng_object.hit2 == true))
	{
		GetMousePoint(&mouse_x, &mouse_y);

		DrawBox(mouse_x + 15, mouse_y + 10, mouse_x + 115, mouse_y + 60, GetColor(150, 150, 150), TRUE);
	}


}