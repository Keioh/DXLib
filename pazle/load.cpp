#include "load.h"

Load::Load()
{
	Load::init();
}

void Load::init()
{
	load.Init();
	hit_buffer = 0;
	anime_alph = 0;
}

void Load::LoadGraphics()
{
	load.Load("pack/UI/Title/load.png");
}

int Load::DrawLoadButton(int x, int y, float speed, bool wire)
{
	if (anime_alph > 255)
	{
		anime_alph = 255;
	}

	anime_alph += speed;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, anime_alph);
	hit_buffer = load.BoxUI_Button(x, y, 1.0f, 1.0f, 1, wire);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	return hit_buffer;
}