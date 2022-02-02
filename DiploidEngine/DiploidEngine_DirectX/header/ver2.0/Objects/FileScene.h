#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidSoftImage.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Graphics/DiploidScreenGraphics.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Graphics/DiploidStrings.h"
#include "diploidScreen\DiploidEngineScreen.h"
#include "system/define.h"

#include "ver2.0/Objects/string_image/load/load_string_image.h"
#include "ver2.0/Objects/string_image/save/save_string_image.h"

#include "ver2.0/Objects/button/Back.h"


class FileScene
{
private:
	DiploidScreenGraphics scr_gra;//モザイク処理用

	DiploidBoxV2 box;//フェードイン、アウト用BOX

	DiploidImageV2 save_load_object_image;
	DiploidSelectedUIV2 save_load_object_button;

	LoadStringImage load_string_image;//ロード画面のタイトル画像
	SaveStringImage save_string_image;//セーブ画面のタイトル画像

	Back back_button;//戻るボタン


	//透過値とそのスピード
	int alpha = 255, alpha_speed = 500;
	int box_draw_flag = 0;

	//モザイク値とそのスピードとモザイク最大値
	float mosaic = 0.0f, mosaic_speed = 0.01f, mosaic_max = 0.4f;

	int secen_select = GAME_TITLE;//どのボタンを押したかのか
	int button_click = 0;//各ボタンのどれかを押したら1が返る。

	bool in_game_flag_buffer;//ゲーム中かのフラグ
	int save_or_load_flag_buffer;//ロード画面へ行くのかセーブ画面へ行くのかのフラグ

public:

	void Load();

	void Init(DiploidEngineSetting& setting);

	void Updata(DiploidEngineInput& input, DiploidEngineSetting& setting, DiploidEngineScreen& screen, bool in_game_flag, int save_or_load_flag);

	void Draw(DiploidEngineScreen& screen, bool draw = true, bool debug = false);

	int GetReturnButton();//最後に押したボタンがどれかを取得する。(値はdefine.hを参照)
	void SetSecne(int scene_type);//defineファイルに記載されているマクロにしたがってシーンを変更します。(GAME_TITLEでタイトル画面)
};