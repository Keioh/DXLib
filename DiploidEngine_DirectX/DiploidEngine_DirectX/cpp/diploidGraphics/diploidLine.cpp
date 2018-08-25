#include "diploidGraphics\diploidLine.h"

void DiploidLine::Init(VECTOR position_one, VECTOR position_two)
{
	POSITION_ONE = position_one;
	POSITION_TWO = position_two;

}

void DiploidLine::Update()
{
	anime_position_one = VAdd(anime_position_one, move_speed);//アニメーションで移動した分を保存
	Position_one = VAdd(POSITION_ONE, anime_position_one);//オブジェクトを描写した位置と移動した分を保存

	anime_position_two = VAdd(anime_position_two, move_speed);//アニメーションで移動した分を保存
	Position_two = VAdd(POSITION_TWO, anime_position_two);//オブジェクトを描写した位置と移動した分を保存

	//anime_size = VAdd(anime_size, move_size);
	//size = VAdd(anime_size, origin_size);
}

void DiploidLine::Draw(bool wire)
{
	if (wire == true)
	{
		DrawLine(Position_one.x, Position_one.y, Position_two.x, Position_two.y, color, thickness);
	}
}

double DiploidLine::GetAngle()
{
	double angle;

	angle = atan2(Position_two.y - Position_one.y, Position_two.x - Position_one.x);

	return angle;
}