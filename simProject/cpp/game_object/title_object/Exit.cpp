#include "Exit.h"

Exit::Exit()
{
	Exit::init();
}

void Exit::init()
{
	exit.Init();
	hit_buffer = 0;
	anime_alph = 0;
}

void Exit::Load()
{
	exit.Load("pack/UI/Title/exit.png");
	se_exit.LoadSound("pack/GameObject/se/cursor_hit.wav");
	se_exit_click.LoadSound("pack/GameObject/se/click.wav");
}

void Exit::CollisionHit(Filer config)
{
	if (exit.box_collision.hit == true)
	{
		se_exit.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
		SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)
	}
	else
	{
		se_exit.OneShotReset();//ワンショット再生を初期化
	}
}

int Exit::DrawExitButton(int x, int y, float speed, Filer config, bool wire)
{
	if (anime_alph > 255)
	{
		anime_alph = 255;
	}

	anime_alph += speed;

	Exit::CollisionHit(config);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, anime_alph);
	if (exit.BoxUI_Button(x, y, 1, wire) == true)
	{
		hit_buffer = true;
		se_exit_click.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);
	}
	else
	{
		se_exit_click.OneShotReset();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	return hit_buffer;
}