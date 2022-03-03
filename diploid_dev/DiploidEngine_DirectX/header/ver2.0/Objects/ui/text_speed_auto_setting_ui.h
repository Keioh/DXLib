#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
//#include "ver2.0/Objects/DiploidAnimation.h"
#include "ver2.0/Objects/DiploidSlider.h"
#include "ver2.0/Graphics/DiploidStrings.h"
#include "ver2.0/Graphics/DiploidStringV2.h"

class TextSpeedAutoSettingUI
{
private:
	DiploidSlider string_speed_slider;//文字速度変更スライダー
	DiploidSlider auto_speed_slider;//オート速度変更スライダー
	DiploidStringV2 test_string;//変更確認用文字
	DiploidBoxV2 test_string_box;//オート速度確認用BOX
	float auto_speed;//時間に加算する量
	float time;//現在の加算された時間の保存用
	float target_time = 64;//この時間になったらnext_flagを立てる
	bool next_flag = false;//次に行っていいよのflag
	DiploidImageV2 draw_speed_image;//文字速度変更スライダーの画像
	DiploidImageV2 auto_speed_image;//オート速度変更スライダーの画像
	DiploidBoxV2 string_background_box;//文字の背景


	DiploidSlider string_background_alpha_slider;//文字背景透過度変更スライダー
	DiploidImageV2 string_background_alpha_image;//文字背景透過度変更画像
	int background_alpha;

public:
	void Load();
	void Init(VECTOR pos);
	void Update(DiploidEngineScreen& screen);
	void Draw(float frame_time = 1.0f, bool draw = true, bool debug = false);

	bool GetHit();//カーソルが当たっているか
	bool GetClick();//クリックされたか
	int GetSelected();//選択状態か

	void SetParameterAutoSpeed(float new_parameter);
	void SetParameterDrawSpeed(float new_parameter);
	void SetParameterBackGroundAlpha(float new_parameter);

	float GetParameterAutoSpeed();//変更された相対値を得る。(オートスピード)
	float GetParameterDrawSpeed();//変更された相対値を得る。(描画スピード)
	float GetParameterBackGroundAlpha();//変更された相対値を得る。(文字背景の透過値)


	float GetParameterAbsoluteAutoSpeed();//スクリーン座標からの絶対値を得る。(オートスピード)
	float GetParameterAbsoluteDrawSpeed();//スクリーン座標からの絶対値を得る。(描画スピード)
	float GetParameterAbsoluteBackGroundAlpha();//スクリーン座標からの絶対値を得る。(文字背景の透過値)


	float GetParameterScaleAutoSpeed();//１フレーム換算時に得られる値を取得する。(オートスピード)
	float GetParameterScaleDrawSpeed();//１フレーム換算時に得られる値を取得する。(描画スピード)

};