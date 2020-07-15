#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "data/res_data/game_define.h"
#include "data/res_data/player/player.h"
#include "data/res_data/UI/day_ui.h"

class ResultUI
{
private:
	DiploidEngineInput input;

	DiploidImageV2 as_up_image;
	DiploidImageV2 hp_up_image;
	DiploidImageV2 cp_up_image;
	DiploidImageV2 confirm_image;

	DiploidImageV2 back_image;
	DiploidImageV2 string_image;
	DiploidImageV2 string_00_image;
	DiploidImageV2 string_01_image;
	DiploidImageV2 string_02_image;

	DiploidSelectedUIV2 as_up_button;
	DiploidSelectedUIV2 hp_up_button;
	DiploidSelectedUIV2 cp_up_button;
	DiploidSelectedUIV2 confirm_button;

	int any_button_active_flags = NO_SELECTED;//�ǂ̃{�^���������Ă��邩

	int state = NO_SELECTED;//�������{�^����ۑ�

	bool active_flag = false;//UI�̃A�N�e�B�u���


public:
	void Load();
	void Init(VECTOR pos);
	void Update(Player* player, DayUI* day_ui);
	void Draw(bool draw = true);

	void SetActiveFlag(bool new_flag);

	int GetState();//�ǂ̃X�e�[�^�X���I������Ă��邩�擾���܂��B

	bool GetActiveFlag();

};