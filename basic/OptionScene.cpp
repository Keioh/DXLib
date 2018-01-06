#include "OptionScene.h"

OptionScene::OptionScene()
{
	flag = false;
	OptionScene::Init();
}

void OptionScene::Load()
{
	back_wall_graphics = LoadGraph("pack/UI/option/option_back_wall.png");

	bgm.LoadSound("pack/GameObject/bgm/01.wav");

	bgm_volume.LoadGraphics();
	se_volume.LoadGraphics();

	bgm_mute.LoadGraphics();
	se_mute.LoadGraphics();

	fade_in.LoadGraphics();
	fade_out.LoadGraphics();

	apply_button.LoadGraphics();
	save_and_return.LoadGraphics();
}

void OptionScene::Init()
{
	option_scene_flag = 0;

	bgm_volume.init();
	se_volume.init();

	bgm_mute.init();
	se_mute.init();

	fade_in.init();
	fade_out.init();

	apply_button.init();
	save_and_return.init();
}

void OptionScene::DrawOptionScene(int window_x, int window_y, Filer config, bool wire)
{		

	while (option_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)
		DrawGraph(0, 0, back_wall_graphics, TRUE);

		if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//フェードアウト
		{		

			bgm_volume.DrawBGMVolumeSlider(200, 200, GetColor(0, 0, 255), wire);//BGM音量調節
			bgm_mute.DrawBGMMuteButton(200 + 255 + 20, 200 + 5, wire);//BGMミュート

			se_volume.DrawSEVolumeSlider(200, 250, GetColor(0, 0, 255), wire);//SE音量調節
			se_mute.DrawSEMuteButton(200 + 255 + 20, 250 + 5, wire);//SEミュート

			apply_button.DrawApplyButton(window_x - (100 + apply_button.apply.size_x * 2), window_y - (50 + apply_button.apply.size_y), wire);

			//設定をセーブしてからオプション画面から抜けるボタン
			if (save_and_return.DrawSaveAndReturnButton(window_x - (50 + save_and_return.save_and_return.size_x), window_y - (50 + save_and_return.save_and_return.size_y), wire) == 1)
			{
				flag = true;
			}

			if (flag == true)//フェードイン
			{
				if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)
				{
					OptionScene::Init();//初期化してから
					flag = false;
					option_scene_flag = 1;//ループを抜ける
				}
			}
		}
	}
}