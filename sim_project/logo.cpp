#include "logo.h"

Logo::Logo()
{
	Logo::Inti();
}

void Logo::LoadGraphics()
{
	logo_D = LoadGraph("pack/Logo/logo_D.png");
	logo_d = LoadGraph("pack/Logo/logo_d.png");
	logo_i = LoadGraph("pack/Logo/logo_i.png");
	logo_l = LoadGraph("pack/Logo/logo_l.png");
	logo_o = LoadGraph("pack/Logo/logo_o.png");
	logo_p = LoadGraph("pack/Logo/logo_p.png");
}

void Logo::Inti()
{
	alph_graphics = 0;
	anime_x = 25.0f;
	anime_pos_x = -anime_x;
	timer = 0;
}

void Logo::DrawLogo(int x, int y)
{
	if (anime_pos_x < 0)
	{
		anime_pos_x += 0.5f;
		alph_graphics += 5.0f;
	}

	if (anime_pos_x == 0)
	{
		timer++;
		anime_pos_x = 0.0f; 
	}

	if (anime_pos_x >= 0 && timer >= 60)
	{
		anime_pos_x += 0.5f;
		alph_graphics -= 5.0f;
		if (anime_pos_x > anime_x)
		{
			anime_pos_x = anime_x;
			alph_graphics = 0;
		}
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alph_graphics);
	DrawGraph(x + anime_pos_x, y, logo_D, TRUE);
	DrawGraph(x + 40 + anime_pos_x, y - 5, logo_i, TRUE);
	DrawGraph(x + 60 + anime_pos_x, y + 25, logo_p, TRUE);
	DrawGraph(x + 85 + anime_pos_x, y - 5, logo_l, TRUE);
	DrawGraph(x + 120 + anime_pos_x, y - 5, logo_o, TRUE);
	DrawGraph(x + 145 + anime_pos_x, y - 5, logo_i, TRUE);
	DrawGraph(x + 180 + anime_pos_x, y, logo_d, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}