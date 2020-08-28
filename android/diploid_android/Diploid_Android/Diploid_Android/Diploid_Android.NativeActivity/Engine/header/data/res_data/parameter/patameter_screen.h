#pragma once
#include "DxLib.h"
#include "data/res_data/parameter/base_parameter_ui.h"
#include "diploidInput/DiploidEngineInput.h"

class ParameterScreen
{
private:
	BaseParameterUI str_button;
	BaseParameterUI dex_button;
	BaseParameterUI con_button;
	BaseParameterUI int_button;
	BaseParameterUI luk_button;
	BaseParameterUI agi_button;
	BaseParameterUI res_button;
	BaseParameterUI atk_button;
	BaseParameterUI cri_button;
	BaseParameterUI def_button;
	BaseParameterUI san_button;
	BaseParameterUI will_button;


public:
	void Load();
	void Init();
	void Update(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);
};