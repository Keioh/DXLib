#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"

#include "ver2.0/Objects/button/Back.h"

class OptionScene
{
private:
	Back back_button;//�߂�{�^��

public:

	void Load();
	void Init(DiploidEngineSetting& setting);
	void Updata(DiploidEngineInput& input);
	void Draw(bool draw = true, bool debug = false);

	bool GetReturnFlag();//�߂�{�^���������ꂽ��true���Ԃ�B
};