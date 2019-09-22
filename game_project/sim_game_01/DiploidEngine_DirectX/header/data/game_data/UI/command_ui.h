#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"

class CommandUI
{
private:

	DiploidUI development_button;//開発ボタン
	DiploidUI research_button;//研究ボタン
	DiploidUI policy_button;//政策ボタン
	DiploidUI defense_button;//防衛ボタン
	DiploidUI information_button;//情報ボタン

public:
	CommandUI() {};
	~CommandUI() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);
};