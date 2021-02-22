#include "ver2.0/Objects/ui/text_speed_auto_setting_ui.h"

void TextSpeedAutoSettingUI::Load()
{
	string_speed_slider.Load();
	auto_speed_slider.Load();
	string_background_alpha_slider.Load();

	test_string.CreateFontData(20, 2, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	test_string.Load("現在の表示速度です。\nThis is Test.");

	draw_speed_image.Load("texter/basic/option/game_play/draw_speed.png");
	auto_speed_image.Load("texter/basic/option/game_play/auto_speed.png");
	string_background_alpha_image.Load("texter/basic/option/game_play/alpha.png");
}

void TextSpeedAutoSettingUI::Init(VECTOR pos)
{
	draw_speed_image.Init(VGet(pos.x, pos.y + 55 + (32 + 12), 0));
	string_speed_slider.Init(VGet(pos.x, pos.y + 55 + (32 + 12), 0), VGet(200, 0, 0));
	string_speed_slider.SetParameter(VGet(100, 0, 0));

	test_string.Init(pos.x, pos.y + (32 + 4));

	test_string_box.Init(VGet(pos.x + 151, pos.y + 36 + (32 + 4), 0), VGet(0, 8, 0), GetColor(255, 255, 255));
	test_string_box.SetFill(true);

	auto_speed_slider.Init(VGet(pos.x, pos.y + 95 + (32 + 12), 0), VGet(200, 0, 0));
	auto_speed_image.Init(VGet(pos.x, pos.y + 95 + (32 + 12), 0));
	auto_speed_slider.SetParameter(VGet(50, 0, 0));


	string_background_alpha_slider.Init(VGet(pos.x, pos.y + 135 + (32 + 12), 0), VGet(200, 0, 0));
	string_background_alpha_image.Init(VGet(pos.x, pos.y + 135 + (32 + 12), 0));
	string_background_alpha_slider.SetParameter(VGet(50, 0, 0));

	string_background_box.Init(VGet(pos.x, pos.y + (32 + 4), pos.z), VGet(216, 50, 0), GetColor(0, 0, 0));
	string_background_box.SetFill(true);
}

void TextSpeedAutoSettingUI::Update(DiploidEngineScreen& screen)
{
	string_speed_slider.Updata();
	auto_speed_slider.Updata();
	string_background_alpha_slider.Updata();


	background_alpha = string_background_alpha_slider.GetParameter().x;

	test_string.SetSpeed(string_speed_slider.GetParameter().x * 50);//表示速度を反映

	if (next_flag == true)
	{
		test_string.Reset();//文字列データをリセットする
	}

	//文字の描画が完了していたら
	if (test_string.GetEnd() == 1)
	{
		if (time >= target_time)
		{
			next_flag = true;//次へ行くflagを立てる
			time = 0;
		}
		else
		{
			next_flag = false;
			time += auto_speed * screen.GetFrameTime();//オートの時間を進める。
		}
	}
	else
	{
		next_flag = false;
	}

	auto_speed = auto_speed_slider.GetParameter().x * 0.8f;//オート速度を変更

	test_string_box.SetSize(VGet(time, 8, 0));//オートのtimeをビジュアルに反映
}

void TextSpeedAutoSettingUI::Draw(float frame_time, bool draw, bool debug)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, background_alpha);
	string_background_box.Draw(draw);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


	string_speed_slider.Draw(draw, debug);
	test_string.Draw(frame_time);
	draw_speed_image.Draw(draw);

	auto_speed_slider.Draw(draw, debug);
	test_string_box.Draw(draw);
	auto_speed_image.Draw(draw);

	string_background_alpha_slider.Draw(draw, debug);
	string_background_alpha_image.Draw(draw);
}


void TextSpeedAutoSettingUI::SetParameterAutoSpeed(float new_parameter)
{
	auto_speed_slider.SetParameter(VGet(new_parameter, 0, 0));

	auto_speed = auto_speed_slider.GetParameter().x * 0.8f;//オート速度を変更
}

void TextSpeedAutoSettingUI::SetParameterDrawSpeed(float new_parameter)
{
	string_speed_slider.SetParameter(VGet(new_parameter, 0, 0));

	test_string.SetSpeed(string_speed_slider.GetParameter().x * 50);
}

void TextSpeedAutoSettingUI::SetParameterBackGroundAlpha(float new_parameter)
{
	string_background_alpha_slider.SetParameter(VGet(new_parameter, 0, 0));

	background_alpha = string_background_alpha_slider.GetParameter().x;
}


bool TextSpeedAutoSettingUI::GetHit()
{
	if ((string_speed_slider.GetHit() == true) || (auto_speed_slider.GetHit() == true))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TextSpeedAutoSettingUI::GetClick()
{
	if ((string_speed_slider.GetClick() == true) || (auto_speed_slider.GetClick() == true) || (string_background_alpha_slider.GetClick() == true))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int TextSpeedAutoSettingUI::GetSelected()
{
	if ((string_speed_slider.GetSelectedUI() == 1) || (auto_speed_slider.GetSelectedUI() == 1) || (string_background_alpha_slider.GetSelectedUI() == 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}


float TextSpeedAutoSettingUI::GetParameterAutoSpeed()
{
	return auto_speed;
}

float TextSpeedAutoSettingUI::GetParameterDrawSpeed()
{
	return string_speed_slider.GetParameter().x;
}

float TextSpeedAutoSettingUI::GetParameterBackGroundAlpha()
{
	return background_alpha;
}


float TextSpeedAutoSettingUI::GetParameterAbsoluteAutoSpeed()
{
	return auto_speed_slider.GetParameter().x;
}

float TextSpeedAutoSettingUI::GetParameterAbsoluteDrawSpeed()
{
	return string_speed_slider.GetParameter().x;
}

float TextSpeedAutoSettingUI::GetParameterAbsoluteBackGroundAlpha()
{
	return string_background_alpha_slider.GetParameter().x;
}


float TextSpeedAutoSettingUI::GetParameterScaleAutoSpeed()
{
	return auto_speed_slider.GetParameter().x * 0.8f;
}

float TextSpeedAutoSettingUI::GetParameterScaleDrawSpeed()
{
	return string_speed_slider.GetParameter().x * 50;
}

