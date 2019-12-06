#pragma once
#include <string>
#include "DxLib.h"
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"

class DiploidUI : public DiploidObject
{
private:

	bool button_flag = false;//ボタンが押されていればtrue（スイッチボタンで使用）
	VECTOR image_size = { 0.0f,0.0f,0.0f };//画像の大きさを保存
	VECTOR image_size_1 = { 0.0f,0.0f,0.0f };//画像の大きさを保存
	VECTOR image_size_2 = { 0.0f,0.0f,0.0f };//画像の大きさを保存
	VECTOR image_size_3 = { 0.0f,0.0f,0.0f };//画像の大きさを保存

	bool bright_one = false, bright_two = false, bright_three = false;//画像の明るさフラウ

	DiploidImage image_1, image_2, image_3;

public:
	DiploidUI();//コンストラクタ
	~DiploidUI();//デストラクタ

	bool* button_flag_ptr = &button_flag;//ボタンのフラグ変数へのポインター

	//ワンクリックボタン箱(押してすぐに元に戻るボタン)
	void OneClickButtonBOX_Init(VECTOR position = { 0.0f,0.0f,0.0f }, VECTOR size = { 0.0f,0.0f,0.0f }, std::string name_tag = "unknown", int layer_number = DIPLOID_LAYER_00);//ワンクリックボタンの初期化処理
	void OneClickButtonBOX_Push(DiploidEngineImpact& impact);//ワンクリックボタンのimpactデータのプッシュ
	void OneClickButtonBOX_Load(const char* path, int size_x, int size_y);//ワンクリックボタンの読み込み処理
	void OneClickButtonBOX_Load(const char* path_1, const char* path_2, const char* path_3, int size_x, int size_y);//ワンクリックボタンの読み込み処理(3つ)
	bool OneClickButtonBOX_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);//ワンクリックボタンのアプデ処理
	void OneClickButtonBOX_Draw(int image_number = 0, bool image_draw = true, bool draw = false);//ワンクリックボタンの描写処理

	//ワンクリックボタン円(押してすぐに元に戻るボタン)
	void OneClickButtonCIRCLE_Init(VECTOR position = { 0.0f,0.0f,0.0f }, float radius = 0.0f, std::string name_tag = "unknown", int layer_number = DIPLOID_LAYER_00);//ワンクリックボタンの初期化処理
	void OneClickButtonCIRCLE_Push(DiploidEngineImpact& impact);//ワンクリックボタンのimpactデータのプッシュ
	void OneClickButtonCIRCLE_Load(const char* path, int size_x, int size_y);//ワンクリックボタンの読み込み処理
	bool OneClickButtonCIRCLE_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);//ワンクリックボタンのアプデ処理
	void OneClickButtonCIRCLE_Draw();//ワンクリックボタンの描写処理

	//スイッチボタン箱(押すとオンオフ切り替わるボタン)
	void SwitchButtonBOX_Init(VECTOR position = { 0.0f,0.0f,0.0f }, VECTOR size = { 0.0f,0.0f,0.0f }, std::string name_tag = "unknown", int layer_number = DIPLOID_LAYER_00);//スイッチボタンの初期化処理
	void SwitchButtonBOX_Push(DiploidEngineImpact& impact);//スイッチボタンのimpactデータのプッシュ
	void SwitchButtonBOX_Load(const char* path, int size_x, int size_y);//スイッチボタンの読み込み処理
	void SwitchButtonBOX_Load(const char* path_1, const char* path_2, const char* path_3, int size_x, int size_y);//スイッチボタンの読み込み処理(3つ)
	void SwitchButtonBOX_Load(const char* path_1, const char* path_2, const char* path_3, const char* path_4, int size_x, int size_y);//スイッチボタンの読み込み処理(4つ)
	bool SwitchButtonBOX_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);//スイッチボタンのアプデ処理
	void SwitchButtonBOX_Draw(int image_number = 0, bool image_draw = true, bool draw = false);//スイッチボタンの描写処理
	bool SwitchButton_Flag_Change(bool flag);//スイッチのフラグを強制的に変更する
	bool GetSwitchButton_Flag();//現在のスイッチのフラグを得る


	void Draw() {};//たぶん使わない。
};