#include "data/res_data/parameter/base_parameter_ui.h"


void BaseParameterUI::Load()
{
	//画像の読み込み
	image_down.Load("res/button/down.png");
	image_up.Load("res/button/up.png");

	//グラフィックハンドルを読み込む
	touch_ui_down.Load(image_down.GetGraphicsHandl());	
	touch_ui_up.Load(image_up.GetGraphicsHandl());
}

void BaseParameterUI::Init(VECTOR pos, VECTOR size, const char* name)
{
	//名前を変える
	string = name;

	//ボタンの初期位置と大きさを決定
	touch_ui_down.Init(pos, size);
	touch_ui_up.Init(VGet(pos.x + 256, pos.y, pos.z), size);	
	
	//タッチ操作用にボタン仕様を変更
	touch_ui_down.SetTouchFlag(true);	
	touch_ui_up.SetTouchFlag(true);
}

void BaseParameterUI::Update(DiploidEngineInput* input)
{
	//それぞれのボタンの座標を保存
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
	touch_ui_down.Draw(draw, debug);//下げるボタンの描画
	touch_ui_up.Draw(draw, debug);//上げるボタンの描画

	DrawString(down_position.x + 24, down_position.y + 24, string, GetColor(255, 255, 255));//パラメータの名前(左)
	DrawFormatString(up_position.x + 24, up_position.y + 24, GetColor(255, 255, 255), "%d", BaseParameterUI::GetParameterValue());//パラメータ値(左)

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