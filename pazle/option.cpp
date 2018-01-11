#include "option.h"

Option::Option()
{
	Option::init();
}

void Option::init()
{
	option.Init();
	hit_buffer = 0;
	anime_alph = 0;
}

void Option::LoadGraphics()
{
	option.Load("pack/UI/Title/option.png");
}

int Option::DrawOptionButton(int x, int y, float speed, bool wire)
{
	if (anime_alph > 255)
	{
		anime_alph = 255;
	}

	anime_alph += speed;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, anime_alph);
	hit_buffer = option.BoxUI_Button(x, y, 1.0f, 1.0f, 1, wire);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
 
	return hit_buffer;
}