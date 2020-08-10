#include "data/res_data/UI/hp_ui.h"

void HpUI::LoadGraphics()
{
	image[0].Load("res/hp/0.png");
	image[1].Load("res/hp/1.png");
	image[2].Load("res/hp/2.png");
	image[3].Load("res/hp/3.png");
	image[4].Load("res/hp/4.png");
	image[5].Load("res/hp/5.png");
	image[6].Load("res/hp/6.png");
	image[7].Load("res/hp/7.png");
	image[8].Load("res/hp/8.png");

	image[9].Load("res/hp/back.png");
}

void HpUI::LoadGraphicsHandle()
{
	for (int count = 0; count != 8; ++count)
	{
		hp_animations[0].LoadHandles(image[count].GetGraphicsHandl());
		hp_animations[1].LoadHandles(image[count].GetGraphicsHandl());
		hp_animations[2].LoadHandles(image[count].GetGraphicsHandl());
	}
}

void HpUI::Init(VECTOR pos, float scale)
{
	image[9].Init(pos, false);
	image[9].SetScale(scale, scale);
	hp_animations[0].Init(VGet(pos.x + (11 * scale), pos.y + (16 * scale), pos.z), anime_speed, scale);
	hp_animations[1].Init(VGet(pos.x + (16 * scale) + (32 * scale), pos.y + (16 * scale), pos.z), anime_speed, scale);
	hp_animations[2].Init(VGet(pos.x + (22 * scale) + (64 * scale), pos.y + (16 * scale), pos.z), anime_speed, scale);
}

void HpUI::Updata(Player player)
{
	//player‚©‚çhp‚Ìî•ñ‚ð“¾‚é
	hp = player.PlayerCirclePtr()->GetLife();
}

void HpUI::Draw(bool draw)
{
	image[9].Draw(draw);

	if (hp >= 1)//hp‚ª1‚ÌŽž
	{
		hp_animations[0].Draw(draw);

		if (hp >= 2)//hp‚ª2‚ÌŽž
		{
			hp_animations[1].Draw(draw);

			if (hp >= 3)//hp‚ª3‚ÌŽž
			{
				hp_animations[2].Draw(draw);
			}
		}
	}
}