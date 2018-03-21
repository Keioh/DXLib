#include "building.h"


void Building::Init()
{
	bulidng_object.Init();
}

void Building::Load(char* path)
{
	bulidng_object.Load(path);
}

void Building::Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos)
{
	bulidng_object.Transform(scale, rote_x, rote_y, rote_z, pos);
}

void Building::Mode(MODE mode_flag)
{
	//接続モードがオンの時
	if (mode_flag.connection_mode == 1)
	{

	}
	else
	{

	}
}

void Building::Draw(bool wire)
{		
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, graphics_alph);
	object_click = bulidng_object.DrawButtonBox3D(wire);	
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Building::DrawUI(int pos_x, int pos_y, bool wire)
{
	//どちらかのコライダーにマウスがヒットしていたら
	if ((bulidng_object.hit1 == true) || (bulidng_object.hit2 == true))
	{
		GetMousePoint(&mouse_x, &mouse_y);

		//DrawBox(mouse_x + 15, mouse_y + 10, mouse_x + 115, mouse_y + 60, GetColor(150, 150, 150), TRUE);
	}
}