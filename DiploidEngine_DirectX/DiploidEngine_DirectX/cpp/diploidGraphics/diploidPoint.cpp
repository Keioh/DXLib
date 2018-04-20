#include "diploidGraphics\diploidPoint.h"

void DiploidPoint::Init(VECTOR position)
{

}

void DiploidPoint::Update()
{
	//アニメーション有効時
	if (mouse_point_move_flag == false)
	{

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