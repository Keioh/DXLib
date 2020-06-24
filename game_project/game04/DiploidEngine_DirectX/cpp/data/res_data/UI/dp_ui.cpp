#include "data/res_data/UI/dp_ui.h"

void DpUI::LoadGraphics()
{
	image[0].Load("texter/res/dp/0.png");
	image[1].Load("texter/res/dp/1.png");
	image[2].Load("texter/res/dp/2.png");
	image[3].Load("texter/res/dp/3.png");
	image[4].Load("texter/res/dp/4.png");
	image[5].Load("texter/res/dp/5.png");
	image[6].Load("texter/res/dp/6.png");
	image[7].Load("texter/res/dp/7.png");
	image[8].Load("texter/res/dp/8.png");

	image[9].Load("texter/res/dp/back.png");

}

void DpUI::LoadGraphicsHandle()
{
	for (int count = 0; count != 8; ++count)
	{
		defense_animations[0].LoadHandles(image[count].GetGraphicsHandl());
		defense_animations[1].LoadHandles(image[count].GetGraphicsHandl());
		defense_animations[2].LoadHandles(image[count].GetGraphicsHandl());
	}
}

void DpUI::Init(VECTOR pos, float scale)
{
	image[9].Init(VGet(pos.x, pos.y + (16 * scale),pos.z), false);
	image[9].SetScale(scale, scale);
	defense_animations[0].Init(VGet(pos.x + (11 * scale), pos.y + (16 * scale), pos.z), anime_speed, scale);
	defense_animations[1].Init(VGet(pos.x + (16 * scale) + (32 * scale), pos.y + (16 * scale), pos.z), anime_speed, scale);
	defense_animations[2].Init(VGet(pos.x + (22 * scale) + (64 * scale), pos.y + (16 * scale), pos.z), anime_speed, scale);
}

void DpUI::Updata(Player player)
{
	//player‚©‚çdefense_point‚Ìî•ñ‚ð“¾‚é
	defense = player.GetPlayerDefensePoint();
}

void DpUI::Draw(bool draw)
{
	image[9].Draw(draw);

	if (defense >= 1)//defense_point‚ª1‚ÌŽž
	{
		defense_animations[0].Draw(draw);

		if (defense >= 2)//defense_point‚ª2‚ÌŽž
		{
			defense_animations[1].Draw(draw);

			if (defense >= 3)//defense_point‚ª3‚ÌŽž
			{
				defense_animations[2].Draw(draw);
			}
		}
	}
}