#include "diploidGraphics\diploidPoint.h"

void DiploidPoint::Init(VECTOR position)
{

}

void DiploidPoint::Update(VECTOR move_speed, bool mouse_point)
{
	//アニメーション有効時
	if (mouse_point == false)
	{
		
	}
	else
	{
		GetMousePoint(&mouse_position_x, &mouse_position_y);
	}
}

void DiploidPoint::Draw(bool wire)
{
	DrawPixel(position.x + mouse_position_x, position.y + mouse_position_y, color);
}