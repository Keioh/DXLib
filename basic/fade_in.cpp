#include "fade_in.h"

void FadeIn::init()
{
	flag = false;
	graphics_alph = 0;
}

void FadeIn::LoadGraphics()
{
	black_screen_graphics = LoadGraph("pack/Effect/black_screen.png");
}

bool FadeIn::DrawFadeIn(int x, int y, float speed)
{
	graphics_alph += speed;

	if (graphics_alph >= 255) 
	{
		graphics_alph = 255; flag = true;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, graphics_alph);
	DrawGraph(x, y, black_screen_graphics, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	return flag;
}
