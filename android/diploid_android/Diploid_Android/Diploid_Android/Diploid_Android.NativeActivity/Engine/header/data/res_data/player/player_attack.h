#pragma once
#include "DxLib.h"

#include "ver2.0/Graphics/DiploidCircleV2.h"
#include "diploidInput/DiploidEngineInput.h"

class PlayerAttack
{
private:
	DiploidCircleV2 circle;

	float attack_size = 30.0f;

public:
	void Init(VECTOR pos);
	void Updata(DiploidEngineInput* input);
	void Draw(bool debug = false, bool draw = true);

	void SetAttackSize(float new_size);//�U���̑傫����ݒ肵�܂��B


	DiploidCircleV2* GetAttackCircleObjectPtr();//circle�ւ̃|�C���^���擾���܂��B
};