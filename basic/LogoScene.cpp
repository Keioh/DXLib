#include "LogoScene.h"

LogoScene::LogoScene()
{
	LogoScene::init();
}

void LogoScene::init()
{
	logo.Inti();

	fade_in.init();
	fade_out.init();

	logo_scene_flag = 0;
}

void LogoScene::LoadGraphics()
{
	logo.LoadGraphics();

	fade_in.LoadGraphics();
	fade_out.LoadGraphics();

	logo_sound_handl = LoadSoundMem("pack/Logo/sound/logo_sound.wav");//音読み込み
}

void LogoScene::DrawLogoScene(int x, int y)
{
	while (logo_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//フェードアウト
		{
			if (CheckSoundMem(logo_sound_handl) == 0)PlaySoundMem(logo_sound_handl, DX_PLAYTYPE_BACK);//音再生

			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)//マウスを左クリックしたら
			{
				LogoScene::init();//初期化
				StopSoundMem(logo_sound_handl);
				logo_scene_flag = 1;//ロゴシーンを抜ける
			}

			logo.DrawLogo(x, y);//フェードアウトが完了したらロゴを表示

			if (logo.anime_pos_x >= logo.anime_x)
			{
				if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)//フェードイン
				{
					SetBackgroundColor(0, 0, 0);//背景色を黒に設定
					LogoScene::init();//初期化
					StopSoundMem(logo_sound_handl);
					logo_scene_flag = 1;//フェードインが完了したらロゴシーンを抜ける
				}
			}
		}
	}
	DeleteSoundMem(logo_sound_handl);
}