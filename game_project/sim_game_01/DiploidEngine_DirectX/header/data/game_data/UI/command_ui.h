
/*---------------------------------------------------------*/
/*--------------�Q�[���R�}���h�̂��ׂĂ�������-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"


//���C���[�ԍ���DIPLOID_LAYER_00
class CommandUI
{
private:
	DiploidUI production_button;//����{�^��
	DiploidUI research_button;//�����{�^��
	DiploidUI shopping_button;//�������{�^��
	DiploidUI camp_button;//��c�{�^��
	DiploidUI information_button;//���{�^��
	DiploidUI explore_button;//�T���{�^��
	DiploidUI move_button;//�ړ��{�^��

	int select_command;//���ݑI������Ă���R�}���h

public:
	CommandUI() {};
	~CommandUI() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

	int GetCommand();//�ǂ̃R�}���h���I������Ă��邩�𓾂�B
};