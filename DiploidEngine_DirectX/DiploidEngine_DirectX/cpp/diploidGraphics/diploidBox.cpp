#include "diploidGraphics\diploidBox.h"

void DiploidBox::Init(VECTOR position, VECTOR size)
{
	DiploidBox::position = position;
	DiploidBox::size = size;

	center_position = VAdd(VScale(DiploidBox::size, 0.5f), DiploidBox::position);
}

void DiploidBox::Update()
{
	//center_position = VAdd(VScale(size, 0.5f), position);

	if (mouse_point_move_flag == false)
	{

	}
	else
	{

	}
}

void DiploidBox::Draw(bool wire)
{
	if (wire == true)
	{
		DrawBoxAA(position.x, position.y, position.x + size.x, position.y + size.y, color, fill, thickness);
	}
}