#include "LoadScene.h"

LoadScene::LoadScene()
{
	flag = false;
	LoadScene::Init();
}

void LoadScene::Load()
{
	fade_in.LoadGraphics();
	fade_out.LoadGraphics();

	return_button.LoadGraphics();
}

void LoadScene::Init()
{
	load_scene_flag = 0;

	fade_in.init();
	fade_out.init();

	return_button.init();
}

void LoadScene::DrawLoadScene(int window_x, int window_y, bool wire)
{
	while (load_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//フェードアウト
		{
			DrawString(0, 0, "LoadScene", GetColor(0, 0, 0));

			if (return_button.DrawReturnButton(window_x - (return_button.return_button.size_x + 10), window_y - (return_button.return_button.size_y + 10), wire) == 1)
			{
				flag = true;
			}

			if (flag == true)//フェードイン
			{
				if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)
				{
					LoadScene::Init();//初期化してから
					flag = false;
					load_scene_flag = 1;//ループを抜ける
				}
			}
		}
	}
}