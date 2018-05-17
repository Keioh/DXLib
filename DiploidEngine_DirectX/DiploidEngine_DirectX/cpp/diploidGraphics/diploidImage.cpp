#include "diploidGraphics\diploidImage.h"

void DiploidEngineImage::Load(const char* path)
{
	handl = LoadGraph(path);
}

void DiploidEngineImage::Draw(bool draw = true)
{
	if (draw == true)
	{
		DrawGraph(position.x, position.y, handl, TRUE);
	}
}