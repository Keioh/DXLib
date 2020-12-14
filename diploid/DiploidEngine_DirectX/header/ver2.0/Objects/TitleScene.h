#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidSoftImage.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Graphics/DiploidScreenGraphics.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Graphics/DiploidStrings.h"


class TitleScene
{
private:
	DiploidEngineInput input;//入力関連
	DiploidEngineSetting setting;//WindowSize取得用

	DiploidScreenGraphics scr_gra;//モザイク処理用

	DiploidBoxV2 box;//フェードイン、アウト用BOX

	DiploidImageV2 test_back;//テスト背景


	//各種ボタンの文字列
	DiploidStrings start_string;
	DiploidStrings exit_string;

	//各種ボタンの画像
	DiploidImageV2 button_back_image;

	//各種ボタン
	DiploidSelectedUIV2 start_button;
	DiploidSelectedUIV2 exit_button;

	//透過値とそのスピード
	int alpha = 255, alpha_speed = 5;

	//モザイク値とそのスピードとモザイク最大値
	float mosaic = 0.0f, mosaic_speed = 0.01f, mosaic_max = 0.4f;

public:

	void Load();

	void Init();

	void Updata();

	void Draw();

	bool GetFinalScene();

};