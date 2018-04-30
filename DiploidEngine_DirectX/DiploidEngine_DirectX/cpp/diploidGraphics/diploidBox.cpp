#include "diploidGraphics\diploidBox.h"

void DiploidBox::Init(VECTOR position, VECTOR size)
{
	DiploidBox::position = position;
	DiploidBox::size = size;

	position_center = VAdd(VScale(DiploidBox::size, 0.5f), DiploidBox::position);
}

void DiploidBox::Update()
{
	position_center = VAdd(VScale(size, 0.5f), position);
}

void DiploidBox::Draw(bool wire)
{
	if (wire == true)
	{
		DrawBoxAA(position.x, position.y, position.x + size.x, position.y + size.y, color, fill, thickness);
	}
}