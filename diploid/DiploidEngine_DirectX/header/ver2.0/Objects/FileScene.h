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

#include "ver2.0/Objects/button/Back.h"

class FileScene
{
private:
	DiploidEngineInput input;//入力関連
	DiploidEngineSetting setting;//WindowSize取得用

	DiploidScreenGraphics scr_gra;//モザイク処理用

	DiploidBoxV2 box;//フェードイン、アウト用BOX

	DiploidImageV2 test_back;//テスト背景


	Back back_button;


	//透過値とそのスピード
	int alpha = 255, alpha_speed = 10;
	int box_draw_flag = 0;

	//モザイク値とそのスピードとモザイク最大値
	float mosaic = 0.0f, mosaic_speed = 0.01f, mosaic_max = 0.4f;

	int secen_select = GAME_TITLE;//どのボタンを押したかのか
	int button_click = 0;//各ボタンのどれかを押したら1が返る。

public:

	void Load();

	void Init();

	void Updata();

	void Draw();

	int GetReturnButton();//最後に押したボタンがどれかを取得する。(値はdefine.hを参照)
	void SetSecne(int scene_type);//defineファイルに記載されているマクロにしたがってシーンを変更します。(GAME_TITLEでタイトル画面)
};