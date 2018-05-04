#include "diploidGraphics\diploidCircle.h"

void DiploidCircle::Init(VECTOR position, float size)
{
	center_position = position;
	origin_size.z = size;
}

void DiploidCircle::Update()
{
	if (mouse_point_move_flag == false)
	{
		anime_position = VAdd(anime_position, move_speed);//アニメーションで移動した分を保存
		position = VAdd(center_position, anime_position);//オブジェクトを描写した位置と移動した分を保存

		anime_size = VAdd(anime_size, move_size);
		size = VAdd(anime_size, origin_size);
	}
	else
	{
		GetMousePoint(&mouse_position_x, &mouse_position_y);
		size = origin_size;
		position.x = mouse_position_x;
		position.y = mouse_position_y;
	}
}

void DiploidCircle::Draw(bool wire)
{
	if (wire == true)
	{
		DrawCircleAA(position.x, position.y, size.z, 64, color, fill, thickness);
	}
}