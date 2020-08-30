#include "data/res_data/parameter/base_parameter_ui.h"


void BaseParameterUI::Load()
{
	//画像の読み込み
	image_info_back.Load("res/button/info_value.png");
	image_info.Load("res/button/info.png");
	image_down.Load("res/button/down.png");
	image_up.Load("res/button/up.png");
	image_parameter_ui_back.Load("res/button/parameter_back.png");


	//グラフィックハンドルを読み込む	
	selected_ui_info.Load(image_info.GetGraphicsHandl());
	touch_ui_down.Load(image_down.GetGraphicsHandl());	
	touch_ui_up.Load(image_up.GetGraphicsHandl());
}

void BaseParameterUI::Init(VECTOR pos, VECTOR size, const char* name, bool value_draw_flag)
{
	draw_value_flag = value_draw_flag;

	//名前を変える
	string = name;

	ui_size.x = image_info_back.GetSize().x + image_info.GetSize().x + image_down.GetSize().x + image_up.GetSize().x + 20;
	ui_size.y = image_info_back.GetSize().y + image_info.GetSize().y + image_down.GetSize().y + image_up.GetSize().y + 20;
	ui_size.z = image_info_back.GetSize().z + image_info.GetSize().z + image_down.GetSize().z + image_up.GetSize().z;

	//ボタンの初期位置と大きさを決定
	image_parameter_ui_back.Init(pos);
	image_info_back.Init(VGet(pos.x + 10, pos.y + 10, pos.z));
	selected_ui_info.Init(VGet(pos.x + 10, pos.y + image_info_back.GetSize().y + 10, pos.z), size);
	touch_ui_down.Init(VGet(pos.x + image_info.GetSize().x + 10, pos.y + image_info_back.GetSize().y + 10, pos.z), size);
	touch_ui_up.Init(VGet(pos.x + (image_down.GetSize().x + image_info.GetSize().x) + 10, pos.y + image_info_back.GetSize().y + 10, pos.z), size);
	
	//タッチ操作用にボタン仕様を変更
	touch_ui_down.SetTouchFlag(true);	
	touch_ui_up.SetTouchFlag(true);
	selected_ui_info.SetTouchFlag(true);

}

void BaseParameterUI::Update(DiploidEngineInput* input)
{
	//それぞれのボタンの座標を保存
	ui_back_position = image_parameter_ui_back.GetPosition();
	info_back_position = image_info_back.GetPosition();
	info_position = selected_ui_info.GetPosition();
	down_position = touch_ui_down.GetPosition();
	up_position = touch_ui_up.GetPosition();


	//最大値を超えないように
	if (max_value < parameter)
	{
		parameter = max_value;//超えた場合は設定したmax_valueの値を入れる。
	}

	//最小値を超えないように
	if (mini_value > parameter)
	{
		parameter = mini_value;//超えた場合は設定したmini_valueの値を入れる。
	}

	image_parameter_ui_back.MoveUpdate();
	image_info_back.MoveUpdate();
	selected_ui_info.Updata(input);
	touch_ui_down.Updata(input);
	touch_ui_up.Updata(input);

	//下げるボタンを押したときの処理
	if (touch_ui_down.GetClick() == true)
	{
		//設定した最小値より小さくなければ
		if (mini_value < parameter)
		{
			SubValue(1);//数値を下げる
		}
	}

	//上げるボタンを押したときの処理
	if (touch_ui_up.GetClick() == true)
	{
		//設定した最大値より大きくなければ
		if (max_value > parameter)
		{
			AddValue(1);//数値を上げる
		}
	}
}

void BaseParameterUI::Draw(bool draw, bool debug)
{
	image_parameter_ui_back.Draw(draw);
	image_info_back.Draw(draw);
	selected_ui_info.Draw(draw, debug);//情報ボタンの描画
	touch_ui_down.Draw(draw, debug);//下げるボタンの描画
	touch_ui_up.Draw(draw, debug);//上げるボタンの描画

	DrawString(info_back_position.x + 16, info_back_position.y, string, GetColor(255, 255, 255));//パラメータの名前(左)

	if (draw_value_flag == true)
	{
		DrawFormatString(info_back_position.x + 300, info_back_position.y, GetColor(255, 255, 255), "%d", BaseParameterUI::GetParameterValue());//パラメータ値(右)
	}

	/*
	DrawFormatString(0, 240, GetColor(255, 255, 255), "DownButtonTouchTime:%d", touch_ui_down.GetTime());
	DrawFormatString(0, 300, GetColor(255, 255, 255), "UpButtonTouchTime:%d", touch_ui_up.GetTime());
	DrawFormatString(0, 360, GetColor(255, 255, 255), "Value:%d", BaseParameterUI::GetParameterValue());
	*/
}


void BaseParameterUI::SetMaxValue(int new_max_value)
{
	max_value = new_max_value;
}

void BaseParameterUI::SetMiniValue(int new_mini_value)
{
	mini_value = new_mini_value;
}


void BaseParameterUI::SetParameterValue(int new_value)
{
	parameter = new_value;
}

void BaseParameterUI::SetParameterName(const char* new_stirng)
{
	string = new_stirng;
}


void BaseParameterUI::AddValue(int add_value)
{
	parameter += add_value;
}

void BaseParameterUI::SubValue(int sub_value)
{
	parameter -= sub_value;
}


int BaseParameterUI::GetParameterValue()
{
	return parameter;
}

int BaseParameterUI::GetParameterMaxValue()
{
	return max_value;
}

int BaseParameterUI::GetParameterMiniValue()
{
	return mini_value;
}


VECTOR BaseParameterUI::GetSize()
{
	return ui_size;
}


DiploidSelectedUIV2* BaseParameterUI::GetInfoButtonPtr()
{
	return& selected_ui_info;
}