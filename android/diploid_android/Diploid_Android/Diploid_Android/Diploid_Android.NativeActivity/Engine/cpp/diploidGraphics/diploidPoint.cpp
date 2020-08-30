#include "diploidGraphics\diploidPoint.h"

void DiploidPoint::Init(VECTOR position)
{
	center_position = position;
}

void DiploidPoint::Update()
{
	//アニメーション有効時
	if (mouse_point_move_flag == false)
	{
		anime_position = VAdd(anime_position, move_speed);//アニメーションで移動した分を保存
		position = VAdd(center_position, anime_position);//オブジェクトを描写した位置と移動した分を保存

		move_speed = VGet(0, 0, 0);
	}
	else
	{
		GetMousePoint(&mouse_position_x, &mouse_position_y);
		position.x = mouse_position_x;
		position.y = mouse_position_y;
	}
}

void DiploidPoint::Draw(bool wire)
{
	DrawPixel(position.x, position.y, color);
}

std::string DiploidPoint::GetNameTag()
{
	return name_tag;
}