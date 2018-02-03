#include "option.h"

Option::Option()
{
	Option::init();
}

void Option::init()
{
	option.Init();
	hit_buffer = 0;
	anime_alph = 0;
}

void Option::Load()
{
	option.Load("pack/UI/Title/option.png");
	se_option.LoadSound("pack/GameObject/se/cursor_hit.wav");
	se_option_click.LoadSound("pack/GameObject/se/click.wav");
}

void Option::CollisionHit(Filer config)
{
	if (option.box_collision.hit == true)
	{
		se_option.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
		SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)
	}
	else
	{
		se_option.OneShotReset();//ワンショット再生を初期化
	}
}

int Option::DrawOptionButton(int x, int y, float speed, Filer config, bool wire)
{
	if (anime_alph > 255)
	{
		anime_alph = 255;
	}

	anime_alph += speed;

	Option::CollisionHit(config);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, anime_alph);
	if (option.BoxUI_Button(x, y, 1.0f, 1.0f, 1, wire) == true)
	{
		hit_buffer = true;
		se_option_click.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
	}
	else
	{
		se_option_click.OneShotReset();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	return hit_buffer;
}