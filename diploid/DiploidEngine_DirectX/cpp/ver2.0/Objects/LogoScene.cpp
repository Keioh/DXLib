#include "ver2.0/Objects/LogoScene.h"

void LogoScene::Load()
{
	logo.Load("texter/diploid_logo/diploid.png");
	logo_lib.Load("texter/diploid_logo/diploid_lib.png");
}

void LogoScene::Init()
{	
	logo.Init(VGet(0, 0, 0), false);
	logo_lib.Init(VGet(0, 0, 0), false);
}

void LogoScene::Updata(DiploidEngineScreen& screen)
{
	input.Update();

	logo.SetAlpha(alpha);
	logo_lib.SetAlpha(alpha);



	if (alpha > 255)
	{
		main_log_time++;
	}

	if (main_log_time > main_logo_draw_time)
	{
		alpha -= alpha_speed;
		mosaic -= 0.005f;
	}
	else
	{
		alpha += alpha_speed;
		mosaic += 0.005f;
	}	

	if (alpha == 0)
	{
		scene_number++;
		main_log_time = 0;
	}

	//モザイクの数値のオーバーフロー対策
	if (mosaic > 1.0f)
	{
		mosaic = 1.0f;
	}

	if (mosaic < 0.0f)
	{
		mosaic = 0.0f;
	}

	if (scene_number > 1)
	{
		r -= back_ground_speed;
		g -= back_ground_speed;
		b -= back_ground_speed;

		if (r < 0)
		{
			r = 0;
		}

		if (g < 0)
		{
			g = 0;
		}	
		
		if (b < 0)
		{
			b = 0;
		}
	}
}

void LogoScene::Draw()
{
	if (scene_number == 0)
	{
		logo.Draw();
	}

	if (scene_number == 1)
	{
		logo_lib.Draw();
	}

	scr_gra.Draw(mosaic);

	if (scene_number > 1)
	{
		SetBackgroundColor(r, g, b);
	}

}


bool LogoScene::GetFinalScene()
{
	if (scene_number > 1)
	{
		if ((r == 0) && (g == 0) && (b == 0))
		{
			r = 0;
			g = 0;
			b = 0;

			return true;
		}
	}
	return false;
}