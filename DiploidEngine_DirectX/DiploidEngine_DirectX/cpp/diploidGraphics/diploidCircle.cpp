#include "diploidGraphics\diploidCircle.h"

void DiploidCircle::Init(VECTOR position, float size)
{
	center_position = position;
	origin_size = size;
}

void DiploidCircle::Update(VECTOR move_speed, float move_size)
{
	anime_position = VAdd(anime_position, move_speed);//アニメーションで移動した分を保存
	position = VAdd(center_position, anime_position);//オブジェクトを描写した位置と移動した分を保存

	anime_size += move_size;
	size.z = anime_size + origin_size;
}

void DiploidCircle::Draw(bool wire)
{
	if (wire == true)
	{
		DrawCircleAA(position.x, position.y, size.z, 64, color, fill, thickness);
	}
}