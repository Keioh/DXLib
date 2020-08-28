#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidTouchUI.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "diploidInput/DiploidEngineInput.h"

class BaseParameterUI
{
private:
	DiploidTouchUI touch_ui_up;//数値を上げる用
	DiploidTouchUI touch_ui_down;//数値を下げる用

	DiploidImageV2 image_up;//数値を上げるボタンの画像
	DiploidImageV2 image_down;//数値を下げるボタンの画像

	int parameter = 0;//パラメータ値保存用

	int max_value = 9999;//パラメータの最大値
	int mini_value = 0;//パラメータの最小値

	const char* string = "no_name_parameter";

	VECTOR down_position;
	VECTOR up_position;


public:
	void Load();
	void Init(VECTOR pos, VECTOR size, const char* name = "no_name_parameter");
	void Update(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);

	void SetParameterValue(int new_value);//パラメータ値を新しく設定します。
	void SetMaxValue(int new_max_value);//パラメータ値の最大上限を設定します。
	void SetMiniValue(int new_mini_value);//パラメータ値の最小下限値を設定します。
	void SetParameterName(const char* new_stirng);

	void AddValue(int add_value);//パラメータ値をadd_valueだけ増やします。
	void SubValue(int sub_value);//パラメータ値をadd_valueだけ減らします。

	int GetParameterValue();//現在のパラメータ値を得ます。

};