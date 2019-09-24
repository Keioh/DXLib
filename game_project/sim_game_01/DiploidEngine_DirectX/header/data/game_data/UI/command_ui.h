
/*---------------------------------------------------------*/
/*--------------ゲームコマンドのすべてがここに-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"


//レイヤー番号はDIPLOID_LAYER_00
class CommandUI
{
private:
	DiploidUI production_button;//製作ボタン
	DiploidUI research_button;//研究ボタン
	DiploidUI shopping_button;//買い物ボタン
	DiploidUI camp_button;//野営ボタン
	DiploidUI information_button;//情報ボタン
	DiploidUI explore_button;//探索ボタン
	DiploidUI move_button;//移動ボタン

	int select_command;//現在選択されているコマンド

public:
	CommandUI() {};
	~CommandUI() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

	int GetCommand();//どのコマンドが選択されているかを得る。
};