#include "switchObject.h"

void SwitchObject::init()
{
	red = 0;
	blue = 0;
	green = 0;
	r = 0;
	r_buffer = 0;

	rand_pos = { 0,0,0 };

	object_switch_flag = 0;
	switch_object.Init();
}

void SwitchObject::Load()
{
	click_se.LoadSound("pack/GameObject/se/GameObjectSE/click.wav");
	hit_se.LoadSound("pack/GameObject/se/GameObjectSE/hit.wav");
	switch_object.Load("pack/GameObject/on.png", "pack/GameObject/off.png");
}

void SwitchObject::Draw(int pos_x, int pos_y, Filer config, bool wire)
{
	SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)

	//円を表示
	DrawCircleAA(pos_x + rand_pos.x, pos_y + rand_pos.y, 18 + r, 256, GetColor(red, green, blue), TRUE);

	//コリジョンにヒットしたら
	if (switch_object.circle_collision.hit == true)
	{
		hit_se.Play(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_LOOP);//音を再生

		r_buffer += 0.1f;
		r = sin(r_buffer) * 4;

		red += 3;
		green += 4;
		blue += 5;
	}
	else
	{		

		hit_se.Stop();//音を止める

		r_buffer = 0;
		r = 0;

		if (switch_object.switch_flag == -1)
		{
			red = 0;
			green = 0;
			blue = 0;
		}
		else if (switch_object.switch_flag == 1)
		{
			red = 255;
			green = 0;
			blue = 0;

		}
	}

	//クリックしたら
	if (switch_object.mouse_input.click == true)
	{
		click_se.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);//ワンショット再生
	}
	else
	{	
		click_se.OneShotReset();//ワンショット再生をリセット
	}

	object_switch_flag = switch_object.CircleUI_Button_Switch(pos_x + rand_pos.x, pos_y + rand_pos.y, 18, 1, wire);

	//オブジェクトの位置を保存
	pos.x = pos_x + rand_pos.x;
	pos.y = pos_y + rand_pos.y;
}
