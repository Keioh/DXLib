#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"

class ResultUI
{
private:
	DiploidEngineInput input;

	DiploidImageV2 as_up_image;
	DiploidImageV2 hp_up_image;
	DiploidImageV2 cp_up_image;

	DiploidImageV2 back_image;
	DiploidImageV2 string_image;
	DiploidImageV2 string_00_image;
	DiploidImageV2 string_01_image;
	DiploidImageV2 string_02_image;

	DiploidSelectedUIV2 as_up_button;
	DiploidSelectedUIV2 hp_up_button;
	DiploidSelectedUIV2 cp_up_button;

	bool active_flag = true;


public:
	void Load();
	void Init(VECTOR pos);
	void Update();
	void Draw(bool draw = true);

	void SetActiveFlag(bool new_flag);

	bool GetActiveFlag();

};