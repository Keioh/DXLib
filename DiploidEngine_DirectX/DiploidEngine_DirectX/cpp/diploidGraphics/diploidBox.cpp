#include "diploidGraphics\diploidBox.h"

void DiploidBox::Init(VECTOR position, VECTOR size)
{
	DiploidBox::position = origin_position = position;
	DiploidBox::size = origin_size = size;

	center_position = VAdd(VScale(DiploidBox::size, 0.5f), DiploidBox::position);
}

void DiploidBox::Update()
{
	if (mouse_point_move_flag == false)
	{
		anime_position = VAdd(anime_position, move_speed);
		position = VAdd(anime_position, origin_position);
		center_position = VAdd(center_position, move_speed);

		anime_size = VAdd(anime_size, move_size);
		size = VAdd(anime_size, origin_size);
	}
	else
	{
		GetMousePoint(&mouse_x, &mouse_y);

		position.x = mouse_x - (size.x / 2);
		position.y = mouse_y - (size.y / 2);

		anime_size = VAdd(anime_size, move_size);
		size = VAdd(anime_size, origin_size);
	}
}

void DiploidBox::Draw(bool wire)
{
	if (wire == true)
	{
		DrawBox(position.x, position.y, position.x + size.x, position.y + size.y, color, fill);
	}
}