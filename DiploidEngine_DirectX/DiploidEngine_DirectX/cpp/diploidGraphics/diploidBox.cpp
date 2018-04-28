#include "diploidGraphics\diploidBox.h"

void DiploidBox::Init(VECTOR position)
{

}

void DiploidBox::Update()
{

}

void DiploidBox::Draw(bool wire)
{
	if (wire == true)
	{
		DrawBoxAA(position.x, position.y, position.x + size.x, position.y + size.y, color, fill, thickness);
	}
}