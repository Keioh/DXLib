#pragma once
#include <string>
#include "DxLib.h"
#include "diploidObject/DiploidEngineObjectInformation.h"
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"

class DiploidUI : public DiploidObject
{
private:

public:
	DiploidUI();//コンストラクタ
	~DiploidUI();//デストラクタ

	//ワンクリックボタン(押してすぐに元に戻るボタン)
	void OneClickButtonBOX_Init(VECTOR position = { 0.0f,0.0f,0.0f }, VECTOR size = { 0.0f,0.0f,0.0f }, std::string name_tag = "unknown", int layer_number = DIPLOID_LAYER_00);//ワンクリックボタンの初期化処理
	void OneClickButtonBOX_Push(DiploidEngineImpact& impact);//ワンクリックボタンのimpactデータのプッシュ
	void OneClickButtonBOX_Load();//ワンクリックボタンの読み込み処理
	bool OneClickButtonBOX_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);//ワンクリックボタンのアプデ処理
	void OneClickButtonBOX_Draw();//ワンクリックボタンの描写処理

	//ワンクリックボタン(押してすぐに元に戻るボタン)
	void OneClickButtonCIRCLE_Init(VECTOR position = { 0.0f,0.0f,0.0f }, float radius = 0.0f, std::string name_tag = "unknown", int layer_number = DIPLOID_LAYER_00);//ワンクリックボタンの初期化処理
	void OneClickButtonCIRCLE_Push(DiploidEngineImpact& impact);//ワンクリックボタンのimpactデータのプッシュ
	void OneClickButtonCIRCLE_Load();//ワンクリックボタンの読み込み処理
	bool OneClickButtonCIRCLE_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);//ワンクリックボタンのアプデ処理
	void OneClickButtonCIRCLE_Draw();//ワンクリックボタンの描写処理

	void Draw() {};//たぶん使わない。
};