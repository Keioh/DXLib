#include "load.h"

Load::Load()
{
	Load::init();
}

void Load::init()
{
	load.Init();
	hit_buffer = 0;
	anime_alph = 0;
}

void Load::LoadData()
{
	load.Load("pack/UI/Title/load.png");
	se_load.LoadSound("pack/GameObject/se/cursor_hit.wav");
	se_load_click.LoadSound("pack/GameObject/se/click.wav");

}

void Load::CollisionHit(Filer config)
{
	if (load.box_collision.hit == true)
	{
		se_load.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
		SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)
	}
	else
	{
		se_load.OneShotReset();//ワンショット再生を初期化
	}
}

int Load::DrawLoadButton(int x, int y, float speed, Filer config, bool wire)
{
	if (anime_alph > 255)
	{
		anime_alph = 255;
	}

	anime_alph += speed;

	Load::CollisionHit(config);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, anime_alph);

	if (load.BoxUI_Button(x, y, 1.0f, 1.0f, 1, wire) == true)
	{
		hit_buffer = true;	
		se_load_click.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
	}
	else
	{
		se_load_click.OneShotReset();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	return hit_buffer;
}