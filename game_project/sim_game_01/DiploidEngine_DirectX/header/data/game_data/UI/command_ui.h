#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"


//レイヤー番号はDIPLOID_LAYER_01
class CommandUI
{
private:
	bool development_button_flag = false;//開発ボタンの押されてるフラグ保存用


	DiploidSystem agriculture_button_systme;//農業ボタンのタイミングローディング処理
	DiploidSystem industrial_button_systme;//工業ボタンのタイミングローディング処理
	DiploidSystem science_button_system;//科学ボタンのタイミングローディング処理


	DiploidUI development_button;//開発ボタン
	DiploidUI research_button;//研究ボタン
	DiploidUI policy_button;//政策ボタン
	DiploidUI defense_button;//防衛ボタン
	DiploidUI information_button;//情報ボタン

	DiploidUI agriculture_button;//農業ボタン
	DiploidUI industrial_button;//工業ボタン
	DiploidUI science_button;//科学ボタン


public:
	CommandUI() {};
	~CommandUI() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);
};