#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
//#include "ver2.0/Objects/DiploidAnimation.h"
#include "ver2.0/Objects/DiploidSlider.h"
#include "ver2.0/Graphics/DiploidStrings.h"

class TextSpeedAutoSettingUI
{
private:
	DiploidSlider string_speed_slider;//文字速度変更スライダー
	DiploidSlider auto_speed_slider;//オート速度変更スライダー
	DiploidStrings test_string;//変更確認用文字
	DiploidBoxV2 test_string_box;//オート速度確認用BOX
	float auto_speed;//時間に加算する量
	float time;//現在の加算された時間の保存用
	float target_time = 64;//この時間になったらnext_flagを立てる
	bool next_flag = false;//次に行っていいよのflag
	DiploidImageV2 draw_speed_image;//文字速度変更スライダーの画像
	DiploidImageV2 auto_speed_image;//オート速度変更スライダーの画像

public:
	void Load();
	void Init(VECTOR pos);
	void Update();
	void Draw(bool draw = true, bool debug = false);

	bool GetHit();//カーソルが当たっているか
	bool GetClick();//クリックされたか
	int GetSelected();//選択状態か

	void SetParameterAutoSpeed(float new_parameter);
	void SetParameterDrawSpeed(float new_parameter);

	float GetParameterAutoSpeed();//変更された相対値を得る。(オートスピード)
	float GetParameterDrawSpeed();//変更された相対値を得る。(描画スピード)

	float GetParameterAbsoluteAutoSpeed();//スクリーン座標からの絶対値を得る。(オートスピード)
	float GetParameterAbsoluteDrawSpeed();//スクリーン座標からの絶対値を得る。(描画スピード)

};