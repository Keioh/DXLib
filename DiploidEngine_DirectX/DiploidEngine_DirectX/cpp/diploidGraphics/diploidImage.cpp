#include "diploidGraphics\diploidImage.h"

void DiploidImage::Load(const char* path)
{
	handl = LoadGraph(path);
}

void DiploidImage::Updata()
{

}

void DiploidImage::Draw(bool draw)
{
	if (draw == true)
	{
		DrawGraph(position.x, position.y, handl, TRUE);
	}
}