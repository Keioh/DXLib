#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"


//���C���[�ԍ���DIPLOID_LAYER_01
class CommandUI
{
private:
	bool development_button_flag = false;//�J���{�^���̉�����Ă�t���O�ۑ��p


	DiploidSystem agriculture_button_systme;//�_�ƃ{�^���̃^�C�~���O���[�f�B���O����
	DiploidSystem industrial_button_systme;//�H�ƃ{�^���̃^�C�~���O���[�f�B���O����
	DiploidSystem science_button_system;//�Ȋw�{�^���̃^�C�~���O���[�f�B���O����


	DiploidUI development_button;//�J���{�^��
	DiploidUI research_button;//�����{�^��
	DiploidUI policy_button;//����{�^��
	DiploidUI defense_button;//�h�q�{�^��
	DiploidUI information_button;//���{�^��

	DiploidUI agriculture_button;//�_�ƃ{�^��
	DiploidUI industrial_button;//�H�ƃ{�^��
	DiploidUI science_button;//�Ȋw�{�^��


public:
	CommandUI() {};
	~CommandUI() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);
};