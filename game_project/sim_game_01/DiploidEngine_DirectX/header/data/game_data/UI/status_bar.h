/*---------------------------------------------------------*/
/*--------------�X�e�[�^�X�o�[�̂��ׂĂ�������-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"
#include "data/game_data/UI/information_command.h"

class StatusBar
{
private:

	DiploidObject status_bar;//�X�e�[�^�X�o�[

	VECTOR health_position;//HP�����̈ʒu
	VECTOR mana_position;//MP�����̈ʒu
	VECTOR stamina_position;//SP�����̈ʒu

	int hp_buffer = 0;
	int mp_buffer = 0;
	int sp_buffer = 0;

public:
	StatusBar() {};
	~StatusBar() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);
	void StatusUpdate(InformationCommand& info_command);
	void StatusDraw(InformationCommand& info_command);

	int SubHP(int val, InformationCommand& info_command);//HP�̌��ݒl�����炷
	int AddHP(int val, InformationCommand& info_command);//HP�̌��ݒl�𑝂₷
	//int GetHP();

	int SubMP(int val, InformationCommand& info_command);//MP�̌��ݒl�����炷
	int AddMP(int val, InformationCommand& info_command);//MP�̌��ݒl�𑝂₷
	//int GetMP();

	int SubSP(int val, InformationCommand& info_command);//SP�̌��ݒl�����炷
	int AddSP(int val, InformationCommand& info_command);//SP�̌��ݒl�𑝂₷
	//int GetSP();
};