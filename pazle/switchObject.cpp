#include "switchObject.h"

void SwitchObject::init()
{
	blue_light = true;
	green_light = false;
	orange_light = false;
	purple_light = false;


	light_grahics_blue_alph = 0;
	light_grahics_green_alph = 255;
	light_grahics_orange_alph = 255;
	light_grahics_purple_alph = 255;

	red = 0;
	blue = 0;
	green = 0;
	r = 0;
	r_buffer = 0;
	click_r = 0;

	rand_pos = { 0,0,0 };

	object_switch_flag = 0;
	switch_object.Init();
}

void SwitchObject::Load()
{
	light_grahics_blue = LoadGraph("pack/GameObject/blue.png");
	light_grahics_green = LoadGraph("pack/GameObject/green.png");
	light_grahics_orange = LoadGraph("pack/GameObject/orange.png");
	light_grahics_purple = LoadGraph("pack/GameObject/purple.png");

	light_white = LoadGraph("pack/GameObject/light.png");

	click_se.LoadSound("pack/GameObject/se/GameObjectSE/click.wav");
	hit_se.LoadSound("pack/GameObject/se/GameObjectSE/hit.wav");
	switch_object.Load("pack/GameObject/on.png", "pack/GameObject/off.png");
}

void SwitchObject::Draw(int pos_x, int pos_y, Filer config, bool wire)
{	
	//オブジェクトの位置を保存
	pos.x = pos_x + rand_pos.x;
	pos.y = pos_y + rand_pos.y;

	SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)

	//円を表示
	DrawCircleAA(pos.x, pos.y, 18 + r + click_r, 256, GetColor(red, green, blue), TRUE);

	//オブジェクトの光を描写
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, light_grahics_blue_alph);
	DrawGraph(pos.x - (32 / 2), pos.y - (32 / 2), light_grahics_blue, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, light_grahics_green_alph);
	DrawGraph(pos.x - (32 / 2), pos.y - (32 / 2), light_grahics_green, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, light_grahics_orange_alph);
	DrawGraph(pos.x - (32 / 2), pos.y - (32 / 2), light_grahics_orange, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, light_grahics_purple_alph);
	DrawGraph(pos.x - (32 / 2), pos.y - (32 / 2), light_grahics_purple, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	/*
	DrawFormatString(0, 20, GetColor(0, 0, 0), "blue %d", light_grahics_blue_alph);
	DrawFormatString(0, 40, GetColor(0, 0, 0), "green %d", light_grahics_green_alph);
	DrawFormatString(0, 60, GetColor(0, 0, 0), "orange %d", light_grahics_orange_alph);
	DrawFormatString(0, 80, GetColor(0, 0, 0), "purple %d", light_grahics_purple_alph);

	DrawFormatString(0, 100, GetColor(0, 0, 0), "blue %d", blue_light);
	DrawFormatString(0, 120, GetColor(0, 0, 0), "green %d", green_light);
	DrawFormatString(0, 140, GetColor(0, 0, 0), "orange %d", orange_light);
	DrawFormatString(0, 160, GetColor(0, 0, 0), "purple %d", purple_light);
	*/

	//画像を変える処理
	if (blue_light == true)
	{
		light_grahics_blue_alph++;
		light_grahics_green_alph--;
		light_grahics_orange_alph++;
		light_grahics_purple_alph++;
		
		if (light_grahics_blue_alph >= 255)
		{
			blue_light = false;
			orange_light = false;
			purple_light = false;		
			green_light = true;
		}
	}

	if (green_light == true)
	{
		light_grahics_blue_alph++;
		light_grahics_green_alph++;
		light_grahics_orange_alph--;
		light_grahics_purple_alph++;

		if (light_grahics_green_alph >= 255)
		{
			blue_light = false;
			green_light = false;
			purple_light = false;		
			orange_light = true;
		}
	}

	if (orange_light == true)
	{
		light_grahics_blue_alph++;
		light_grahics_green_alph++;
		light_grahics_orange_alph++;
		light_grahics_purple_alph--;

		if (light_grahics_orange_alph >= 255)
		{
			blue_light = false;
			green_light = false;
			orange_light = false;
			purple_light = true;
		}
	}

	if (purple_light == true)
	{
		light_grahics_blue_alph--;
		light_grahics_green_alph++;
		light_grahics_orange_alph++;
		light_grahics_purple_alph++;

		if (light_grahics_purple_alph >= 255)
		{
			green_light = false;
			orange_light = false;
			purple_light = false;		
			blue_light = true;
		}
	}

	//上限値を超えないように処理
	if (light_grahics_blue_alph > 255)
	{
		light_grahics_blue_alph = 255;
	}

	if (light_grahics_green_alph > 255)
	{
		light_grahics_green_alph = 255;
	}

	if (light_grahics_orange_alph > 255)
	{
		light_grahics_orange_alph = 255;
	}

	if (light_grahics_purple_alph > 255)
	{
		light_grahics_purple_alph = 255;
	}
	

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
		click_r = 15;
		click_se.OneShotPlay(config.sound_data.se_volume * -config.sound_data.se_mute, DX_PLAYTYPE_BACK);//ワンショット再生
	}
	else
	{	
		//クリックしたときに円を大きくする
		if (click_r < 0)click_r = 0;
		click_r--;


		click_se.OneShotReset();//ワンショット再生をリセット
	}

	object_switch_flag = switch_object.CircleUI_Button_Switch(pos.x, pos.y, 18 + r + click_r, 1, wire);


	//拡散光
	if (light_white_alph > 255)
	{
		white_light = true;
	}
	else if (light_white_alph < 0)
	{
		white_light = false;
	}

	if (white_light == true)
	{
		light_white_alph--;
	}
	else
	{
		light_white_alph++;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, light_white_alph);
	DrawGraph(pos.x - (64 / 2), pos.y - (64 / 2), light_white, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
