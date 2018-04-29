#include "diploidGraphics\diploidBox.h"

void DiploidBox::Init(VECTOR position, VECTOR size)
{
	DiploidBox::position = position;
	DiploidBox::size = size;

	position_center = VScale(VAdd(position, size), 0.5f);
}

void DiploidBox::Update()
{
	position_center = VScale(VAdd(position, size), 0.5f);
}

void DiploidBox::Draw(bool wire)
{
	if (wire == true)
	{
		DrawBoxAA(position.x, position.y, position.x + size.x, position.y + size.y, color, fill, thickness);
	}
}