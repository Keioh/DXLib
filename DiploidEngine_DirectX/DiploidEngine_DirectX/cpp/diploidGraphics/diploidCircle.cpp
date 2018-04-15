#include "diploidGraphics\diploidCircle.h"

void DiploidCircle::Init()
{

}

void DiploidCircle::Update()
{

}

void DiploidCircle::Draw()
{
	DrawCircleAA(position.x, position.y, size.z, 64, color, fill, thickness);
}