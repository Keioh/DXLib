#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidSoftImage.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Graphics/DiploidScreenGraphics.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Graphics/DiploidStrings.h"
#include "system/define.h"
#include "diploidScreen\DiploidEngineScreen.h"


class TitleScene
{
private:
	DiploidEngineInput input;//入力関連
	//DiploidEngineSetting setting;//WindowSize取得用

	DiploidScreenGraphics scr_gra;//モザイク処理用

	DiploidBoxV2 box;//フェードイン、アウト用BOX

	DiploidImageV2 test_back;//テスト背景


	//各種ボタンの文字列
	DiploidStrings start_string;
	DiploidStrings load_string;
	DiploidStrings option_string;
	DiploidStrings exit_string;

	//各種ボタンの画像
	DiploidImageV2 button_back_image;

	//各種ボタン
	DiploidSelectedUIV2 start_button;
	DiploidSelectedUIV2 load_button;
	DiploidSelectedUIV2 option_button;
	DiploidSelectedUIV2 exit_button;

	//透過値とそのスピード
	int alpha = 255, alpha_speed = 500;

	//モザイク値とそのスピードとモザイク最大値
	float mosaic = 0.0f, mosaic_speed = 2.0f, mosaic_max = 0.4f;

	int secen_select = GAME_TITLE;//どのボタンを押したかのか
	int button_click = 0;//各ボタンのどれかを押したら1が返る。

public:

	void Load();

	void Init(DiploidEngineSetting& setting);

	void Updata(DiploidEngineScreen& screen);

	void Draw(DiploidEngineScreen& screen);

	int GetFinalScene();//最後に押したボタンがどれかを取得する。(値はdefine.hを参照)
	void SetSecne(int scene_type);//defineファイルに記載されているマクロにしたがってシーンを変更します。(GAME_TITLEでタイトル画面)
};