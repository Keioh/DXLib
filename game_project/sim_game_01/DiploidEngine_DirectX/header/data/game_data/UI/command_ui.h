#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"

class CommandUI
{
private:

	DiploidUI development_button;//�J���{�^��
	DiploidUI research_button;//�����{�^��
	DiploidUI policy_button;//����{�^��
	DiploidUI defense_button;//�h�q�{�^��
	DiploidUI information_button;//���{�^��

public:
	CommandUI() {};
	~CommandUI() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);
};