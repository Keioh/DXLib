#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"
#include "system/DiploidEngineMath.h"
#include "system/define.h"
#include "ver2.0/Objects/DiploidSliderObject.h"
#include "ver2.0/Objects/DiploidSlider.h"
#include "diploidScreen\DiploidEngineScreen.h"

#include "ver2.0/Objects/button/Back.h"
#include "ver2.0/Objects/button/Save.h"
#include "ver2.0/Objects/button/Reset.h"
#include "ver2.0/Objects/button/Title.h"
#include "ver2.0/Objects/button/WindowSize.h"

#include "ver2.0/Objects/string_image/option/option_string_image.h"
#include "ver2.0/Objects/string_image/option/display_string_image.h"
#include "ver2.0/Objects/string_image/option/game_play_string_image.h"

#include "ver2.0/Graphics/DiploidTriangle.h"
#include "ver2.0/Objects/ContinuousTriangle.h"

#include "ver2.0/Graphics/DiploidStrings.h"

#include "ver2.0/Objects/ui/text_speed_auto_setting_ui.h"

#include "data/system_data/system_data.h"


class OptionScene
{
private:

	DiploidEngineMath math;//数学関数
	DiploidEngineFile file;

	ContinuousTriangle continuous_triangle;//連続した三角形

	DiploidBoxV2 box;//フェード用BOX

	Back back_button;//戻るボタン
	Save save_button;//保存ボタン
	Reset reset_button;//リセットボタン
	Title title_button;//タイトルボタン

	WindowSize window_resize_button_960_540;//ウィンドウサイズ変更ボタン(960_540)
	WindowSize window_resize_button_1280_720;//ウィンドウサイズ変更ボタン(1280_720)
	WindowSize window_resize_button_1600_900;//ウィンドウサイズ変更ボタン(1600_900)
	WindowSize window_resize_button_1920_1080;//ウィンドウサイズ変更ボタン(1920_1080)

	TextSpeedAutoSettingUI text_speed_auto_setting_ui;

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

	//設定したデータを一時保存する用
	SystemData system_data;

	//値の保存用
	float draw_speed = 80.0f;//設定した現在の文字描画速度
	float auto_speed = 50.0f;//設定した現在のオート速度
	float background_alpha = 100.0f;//設定した現在の文字背景の透過度

	//透過処理の変数
	int alpha = 255;
	int alpha_speed = 500;//透過速度

	int box_draw_flag = 0;//0でフェードアウト、1でフェードアウト完了、2でフェードイン、3でフェードイン完了

	bool in_game_flag_buffer;

public:

	void Load();
	void Init(DiploidEngineSetting& setting);
	void Updata(DiploidEngineInput& input, DiploidEngineSetting& setting, DiploidEngineScreen& screen, bool in_game_flag);
	void Draw(DiploidEngineScreen& screen, bool draw = true, bool debug = false);

	int GetReturnFlag();//戻るボタンが押されたらtrueが返る。

	SystemData GetSystemData();//一時保存されている現在の設定を呼び出す。
};