#include "OptionScene.h"

OptionScene::OptionScene()
{
	flag = false;
	//OptionScene::Init();
}

void OptionScene::Load()
{
	back_wall_graphics = LoadGraph("pack/UI/option/option_back_wall.png");

	se_apply.LoadSound("pack/GameObject/se/cursor_hit.wav");
	se_apply_click.LoadSound("pack/GameObject/se/click.wav");
	se_option_return.LoadSound("pack/GameObject/se/cursor_hit.wav");
	se_option_return_click.LoadSound("pack/GameObject/se/click.wav");
	se_bgm_volume.LoadSound("pack/GameObject/se/cursor_hit.wav");
	se_se_volume.LoadSound("pack/GameObject/se/cursor_hit.wav");

	bgm_volume.LoadGraphics();
	se_volume.LoadGraphics();

	bgm_mute.LoadGraphics();
	se_mute.LoadGraphics();

	fade_in.LoadGraphics();
	fade_out.LoadGraphics();

	japanese.LoadGraphics();
	english.LoadGraphics();
	apply_button.LoadGraphics();
	option_return.LoadGraphics();
}

void OptionScene::Init(Filer config)
{
	back_flag = false;
	language_change_flag = false;

	option_scene_flag = 0;
	anime_alph = 0;
	anime_speed = 35.0f;

	se_apply.OneShotReset();
	se_apply_click.OneShotReset();
	se_option_return.OneShotReset();
	se_option_return_click.OneShotReset();
	se_bgm_volume.OneShotReset();
	se_se_volume.OneShotReset();

	//各種設定値をconfigから取得
	bgm_volume.bgm_volume_slider.wheel_volume_buffer = config.sound_data.bgm_volume;
	bgm_mute.bgm_mute.switch_flag = config.sound_data.bgm_mute;
	se_volume.se_volume_slider.wheel_volume_buffer = config.sound_data.se_volume;
	se_mute.se_mute.switch_flag = config.sound_data.se_mute;

	japanese.japanese.switch_flag = config.language_data.japanese_flag;
	english.english.switch_flag = config.language_data.english_flag;


	fade_in.init();
	fade_out.init();

	apply_button.init();
	option_return.init();
}

bool OptionScene::DrawOptionScene(int window_x, int window_y, Filer& config, bool wire)
{
	SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)

	DrawGraph(0, 0, back_wall_graphics, TRUE);

	if (fade_out.DrawFadeOut(0, 0, 15.0f) == true)//フェードアウト
	{
		//オブジェクトの透過処理
		if(anime_alph > 255)
		{
			anime_alph = 255;
		}
		anime_alph += anime_speed;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, anime_alph);

		//現在の値を設定ファイルの各変数に代入
		config.sound_data.bgm_volume = bgm_volume.bgm_volume_slider.wheel_volume_buffer;
		config.sound_data.bgm_mute = bgm_mute.bgm_mute.switch_flag;
		config.sound_data.se_volume = se_volume.se_volume_slider.wheel_volume_buffer;
		config.sound_data.se_mute = se_mute.se_mute.switch_flag;

		config.language_data.japanese_flag = japanese.japanese.switch_flag;
		config.language_data.english_flag = english.english.switch_flag;

		//言語設定関連
		if (english.DrawEnglishButton(window_x - 200, window_y - 600, wire) == true)//英語を選択していたら
		{
			language_change_flag = true;
			japanese.japanese.switch_flag = -1;//日本語をオフにする。
		}
		if (japanese.DrawJapaneseButton(window_x - 200, window_y - 500, wire) == true)//日本語を選択していたら
		{
			language_change_flag = true;
			english.english.switch_flag = -1;//英語をオフにする。
		}

		//音設定関連
		bgm_volume.DrawBGMVolumeSlider(200, 200, GetColor(0, 0, 255), config, wire);//BGM音量調節
		bgm_mute.DrawBGMMuteButton(200 + 255 + 20, 200 + 5, wire);//BGMミュート

		se_volume.DrawSEVolumeSlider(200, 250, GetColor(0, 0, 255), config, wire);//SE音量調節
		se_mute.DrawSEMuteButton(200 + 255 + 20, 250 + 5, wire);//SEミュート

		if (bgm_volume.bgm_volume_slider.box_collision.hit == true)
		{
			se_bgm_volume.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
		}
		else
		{
			se_bgm_volume.OneShotReset();
		}

		if (se_volume.se_volume_slider.box_collision.hit == true)
		{
			se_se_volume.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
		}
		else
		{
			se_se_volume.OneShotReset();
		}


		if (apply_button.DrawApplyButton(window_x - (100 + apply_button.apply.size_x * 2), window_y - (50 + apply_button.apply.size_y), wire) == true)
		{
			se_apply_click.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
			config.FileWrite_Config();//設定ファイルに書き込み
			config.FileOpen_Config();//設定ファイルを読み込む

			if (language_change_flag == true)
			{
				config.FileOpen_Language();//言語ファイルを読み込む
				language_change_flag = false;
			}
		}
		else
		{
			se_apply_click.OneShotReset();
		}

		if (apply_button.apply.box_collision.hit == true)
		{
			se_apply.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
		}
		else
		{
			se_apply.OneShotReset();
		}

		//オプション画面から抜けるボタン
		if (option_return.DrawOtpionReturnButton(window_x - (50 + option_return.option_return.size_x), window_y - (50 + option_return.option_return.size_y), wire) == 1)
		{
			se_option_return_click.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
			flag = true;
		}
		else
		{
			se_option_return_click.OneShotReset();
		}

		if (option_return.option_return.box_collision.hit == true)
		{
			se_option_return.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
		}
		else
		{
			se_option_return.OneShotReset();
		}

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//透過処理をもどす

		if (flag == true)//フェードイン
		{
			if (fade_in.DrawFadeIn(0, 0, 15.0f) == true)
			{
				config.FileOpen_Config();//設定ファイルを読み込む
				OptionScene::Init(config);//初期化してから
				flag = false;
				return back_flag = true;
			}
		}
	}
}