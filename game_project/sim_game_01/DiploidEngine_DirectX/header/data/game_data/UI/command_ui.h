
/*---------------------------------------------------------*/
/*--------------ゲームコマンドのすべてがここに-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"

#include "data/game_data/UI/information_command.h"

//レイヤー番号はDIPLOID_LAYER_00
class CommandUI
{
private:
	DiploidSystem system_production_button;
	DiploidSystem system_research_button;
	DiploidSystem system_camp_button;
	DiploidSystem system_information_button;
	DiploidSystem system_explore_button;
	DiploidSystem system_move_button;

	DiploidUI production_button;//製作ボタン
	DiploidUI research_button;//研究ボタン
	DiploidUI camp_button;//野営ボタン
	DiploidUI information_button;//情報ボタン
	DiploidUI explore_button;//探索ボタン
	DiploidUI move_button;//移動ボタン

	int select_command;//現在選択されているコマンド
	int command_ui_on = -1;//コマンドUIがオンになっている場合は1


public:
	CommandUI() {};
	~CommandUI() {};

	InformationCommand information_command;

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

	int GetCommand();//どのコマンドが選択されているかを得る。
	bool GetUIFlag();//コマンドUIのオンオフを知る。

};