#pragma once
#include "data/res_data/game_define.h"
#include "DxLib.h"
#include "data/res_data/parameter/base_parameter_ui.h"
#include "diploidInput/DiploidEngineInput.h"

class ParameterScreen
{
private:
	//プレイヤー情報関連
	BaseParameterUI profession_button;//職業
	BaseParameterUI birth_button;//生まれ

	//パラメータ値関連
	BaseParameterUI str_button;
	BaseParameterUI dex_button;
	BaseParameterUI con_button;
	BaseParameterUI int_button;
	BaseParameterUI luk_button;
	BaseParameterUI agi_button;
	BaseParameterUI res_button;
	BaseParameterUI atk_button;
	BaseParameterUI cri_button;
	BaseParameterUI def_button;
	BaseParameterUI san_button;
	BaseParameterUI will_button;

	VECTOR parameter_pos = { 0, 512, 0 };
	VECTOR player_info_pos = { 0, 0, 0 };

	int profession = PROFESSUON_NONE;
	int birth = BIRTH_NONE;

	//ボタンオフ処理関数
	void birth_button_update();
	void profession_button_update();
	void str_button_update();//ここから下はパラメータ関連
	void dex_button_update();
	void con_button_update();
	void int_button_update();
	void luk_button_update();
	void agi_button_update();
	void res_button_update();
	void atk_button_update();
	void cri_button_update();
	void def_button_update();
	void san_button_update();
	void will_button_update();

	void profession_update();//職業数値のアップデート
	void profession_button_draw(bool draw, bool debug);//職業の表示

	void birth_update();//生まれ数値のアップデート
	void birth_button_draw(bool draw, bool debug);//生まれの表示


public:
	void Load();
	void Init();
	void Update(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);

	int GetProfessionValue();//選択中の職業の値を返す。
	int GetBirthValue();//選択中の生まれの値を返す。

};