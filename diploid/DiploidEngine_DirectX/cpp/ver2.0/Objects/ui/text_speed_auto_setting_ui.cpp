#include "ver2.0/Objects/ui/text_speed_auto_setting_ui.h"

void TextSpeedAutoSettingUI::Load()
{
	string_speed_slider.Load();
	auto_speed_slider.Load();

	test_string.CreateFontData(20, 2, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	test_string.Load("現在の表示速度です。\nThis is Test.");

	draw_speed_image.Load("texter/basic/option/game_play/draw_speed.png");
	auto_speed_image.Load("texter/basic/option/game_play/auto_speed.png");
}

void TextSpeedAutoSettingUI::Init(VECTOR pos)
{
	draw_speed_image.Init(VGet(pos.x, pos.y + 55 + (32 + 4), 0));
	string_speed_slider.Init(VGet(pos.x, pos.y + 55 + (32 + 4), 0), VGet(200, 0, 0));
	string_speed_slider.SetParameter(VGet(25, 0, 0));

	test_string.Init(pos.x, pos.y + (32 + 4));

	test_string_box.Init(VGet(pos.x + 152, pos.y + 36 + (32 + 4), 0), VGet(0, 8, 0), GetColor(100, 100, 100));
	test_string_box.SetFill(true);

	auto_speed_slider.Init(VGet(pos.x, pos.y + 95 + (32 + 4), 0), VGet(200, 0, 0));
	auto_speed_image.Init(VGet(pos.x, pos.y + 95 + (32 + 4), 0));
	auto_speed_slider.SetParameter(VGet(50, 0, 0));

}

void TextSpeedAutoSettingUI::Update()
{
	string_speed_slider.Updata();
	auto_speed_slider.Updata();

	test_string.SetSpeed(string_speed_slider.GetParameter().x);//表示速度を反映

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
			time += auto_speed;//オートの時間を進める。
		}
	}
	else
	{
		next_flag = false;
	}

	auto_speed = auto_speed_slider.GetParameter().x / 100.0f;//オート速度を変更

	test_string_box.SetSize(VGet(time, 8, 0));//オートのtimeをビジュアルに反映
}

void TextSpeedAutoSettingUI::Draw(bool draw, bool debug)
{
	string_speed_slider.Draw(draw, debug);
	test_string.Draw();
	draw_speed_image.Draw(draw);

	auto_speed_slider.Draw(draw, debug);
	test_string_box.Draw(draw);
	auto_speed_image.Draw(draw);
}


void TextSpeedAutoSettingUI::SetParameterAutoSpeed(float new_parameter)
{
	auto_speed_slider.SetParameter(VGet(new_parameter, 0, 0));

	auto_speed = auto_speed_slider.GetParameter().x / 100.0f;//オート速度を変更
}

void TextSpeedAutoSettingUI::SetParameterDrawSpeed(float new_parameter)
{
	string_speed_slider.SetParameter(VGet(new_parameter, 0, 0));

	test_string.SetSpeed(string_speed_slider.GetParameter().x);

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
	if ((string_speed_slider.GetClick() == true) || (auto_speed_slider.GetClick() == true))
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
	if ((string_speed_slider.GetSelectedUI() == 1) || (auto_speed_slider.GetSelectedUI() == 1))
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