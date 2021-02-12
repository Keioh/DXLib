#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"
#include "system\DiploidEngineMath.h"
#include "ver2.0/Objects/DiploidSliderObject.h"
#include "ver2.0/Objects/DiploidSlider.h"

#include "ver2.0/Objects/button/Back.h"
#include "ver2.0/Objects/button/Save.h"
#include "ver2.0/Objects/button/WindowSize.h"

#include "ver2.0/Objects/string_image/option/option_string_image.h"
#include "ver2.0/Objects/string_image/option/display_string_image.h"
#include "ver2.0/Objects/string_image/option/game_play_string_image.h"

#include "ver2.0/Graphics/DiploidTriangle.h"
#include "ver2.0/Objects/ContinuousTriangle.h"

#include "ver2.0/Graphics/DiploidStrings.h"


class OptionScene
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



	DiploidEngineMath math;//数学関数

	ContinuousTriangle continuous_triangle;//連続した三角形

	DiploidBoxV2 box;//フェード用BOX

	Back back_button;//戻るボタン
	Save save_button;//保存ボタン

	WindowSize window_resize_button_960_540;//ウィンドウサイズ変更ボタン(960_540)
	WindowSize window_resize_button_1280_720;//ウィンドウサイズ変更ボタン(1280_720)
	WindowSize window_resize_button_1600_900;//ウィンドウサイズ変更ボタン(1600_900)
	WindowSize window_resize_button_1920_1080;//ウィンドウサイズ変更ボタン(1920_1080)

	//Optionの画像
	OptionStringImage option_string_image;
	DisplayStringImage display_string_image;
	GamePlayStringImage game_play_string_image;

	//ウィンドウサイズ変更ボタン群の位置
	int window_resize_button_position_x = 100;
	int window_resize_button_position_y = 100;

	//文字表示速度、オート速度変更ボタン群の位置
	int string_speed_button_position_x = 300;
	int string_speed_button_position_y = 100;



	//透過処理の変数
	int alpha = 255;
	int alpha_speed = 8;//透過速度

	int box_draw_flag = 0;//0でフェードアウト、1でフェードアウト完了、2でフェードイン、3でフェードイン完了

public:

	void Load();
	void Init(DiploidEngineSetting& setting);
	void Updata(DiploidEngineInput& input, DiploidEngineSetting& setting);
	void Draw(bool draw = true, bool debug = false);

	bool GetReturnFlag();//戻るボタンが押されたらtrueが返る。
};