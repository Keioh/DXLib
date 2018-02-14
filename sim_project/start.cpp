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

void Start::Load()
{
	start.Load("pack/UI/Title/new_game.png");
	se_start.LoadSound("pack/GameObject/se/cursor_hit.wav");
	se_start_click.LoadSound("pack/GameObject/se/click.wav");
}

void Start::CollisionHit(Filer config)
{
	if (start.box_collision.hit == true)
	{
		se_start.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
		SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)
	}
	else
	{
		se_start.OneShotReset();//ワンショット再生を初期化
	}
}

int Start::DrawStartButton(int x, int y, float speed, Filer config, bool wire)
{
	if (anime_alph > 255)
	{
		anime_alph = 255;
	}

	anime_alph += speed;

	Start::CollisionHit(config);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, anime_alph);
	if (start.BoxUI_Button(x, y, 1, wire) == true)
	{
		hit_buffer = true;

		se_start_click.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
		SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)
	}
	else
	{
		se_start_click.OneShotReset();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	return hit_buffer;
}