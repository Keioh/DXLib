#include "start.h"

Start::Start()
{
	Start::init();
}

void Start::init()
{
	start.Init();
	hit_buffer = 0;
	anime_alph = 0;
}

void Start::LoadGraphics()
{
	start.Load("pack/UI/Title/new_game.png");
}

int Start::DrawStartButton(int x, int y, float speed, bool wire)
{
	if (anime_alph > 255)
	{
		anime_alph = 255;
	}

	anime_alph += speed;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, anime_alph);
	hit_buffer = start.BoxUI_Button(x, y, 1.0f, 1.0f, 1, wire);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	return hit_buffer;
}