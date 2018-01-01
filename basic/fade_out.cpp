#include "fade_out.h"

void FadeOut::init()
{
	flag = false;
	graphics_alph = 255;
}

void FadeOut::LoadGraphics()
{
	black_screen_graphics = LoadGraph("pack/Effect/black_screen.png");
}

bool FadeOut::DrawFadeOut(int x, int y, float speed)
{
	graphics_alph -= speed;

	if (graphics_alph <= 0)
	{
		graphics_alph = 0;
		flag = true;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, graphics_alph);
	DrawGraph(x, y, black_screen_graphics, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	return flag;
}