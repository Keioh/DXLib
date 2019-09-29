
/*---------------------------------------------------------*/
/*--------------�Q�[���R�}���h�̂��ׂĂ�������-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"

#include "data/game_data/UI/information_command.h"

//���C���[�ԍ���DIPLOID_LAYER_00
class CommandUI
{
private:
	DiploidSystem system_production_button;
	DiploidSystem system_research_button;
	DiploidSystem system_camp_button;
	DiploidSystem system_information_button;
	DiploidSystem system_explore_button;
	DiploidSystem system_move_button;

	DiploidUI production_button;//����{�^��
	DiploidUI research_button;//�����{�^��
	DiploidUI camp_button;//��c�{�^��
	DiploidUI information_button;//���{�^��
	DiploidUI explore_button;//�T���{�^��
	DiploidUI move_button;//�ړ��{�^��

	int select_command;//���ݑI������Ă���R�}���h
	int command_ui_on = -1;//�R�}���hUI���I���ɂȂ��Ă���ꍇ��1


public:
	CommandUI() {};
	~CommandUI() {};

	InformationCommand information_command;

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

	int GetCommand();//�ǂ̃R�}���h���I������Ă��邩�𓾂�B
	bool GetUIFlag();//�R�}���hUI�̃I���I�t��m��B

};