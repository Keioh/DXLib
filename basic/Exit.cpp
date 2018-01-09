#include "Exit.h"

Exit::Exit()
{
	Exit::init();
}

void Exit::init()
{
	exit.Init();
	hit_buffer = 0;
	anime_alph = 0;
}

void Exit::LoadGraphics()
{
	exit.Load("pack/UI/Title/exit.png");
}

int Exit::DrawExitButton(int x, int y, float speed, bool wire)
{
	if (anime_alph > 255)
	{
		anime_alph = 255;
	}

	anime_alph += speed;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, anime_alph);
	hit_buffer = exit.BoxUI_Button(x, y, 1.0f, 1.0f, 1, wire);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	return hit_buffer;
}