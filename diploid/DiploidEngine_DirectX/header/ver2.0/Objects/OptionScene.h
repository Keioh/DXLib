#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"
#include "system\DiploidEngineMath.h"

#include "ver2.0/Objects/button/Back.h"
#include "ver2.0/Objects/button/Save.h"
#include "ver2.0/Objects/button/WindowSize.h"

#include "ver2.0/Objects/string_image/option/option_string_image.h"
#include "ver2.0/Objects/string_image/option/display_string_image.h"

#include "ver2.0/Graphics/DiploidTriangle.h"
#include "ver2.0/Objects/ContinuousTriangle.h"


class OptionScene
{
private:
	DiploidEngineMath math;

	ContinuousTriangle continuous_triangle;

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

	//ウィンドウサイズ変更ボタン群の位置
	int window_resize_button_position_x = 100;
	int window_resize_button_position_y = 100;


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