#pragma once
#include "DxLib.h"

#include "ver2.0/Graphics/DiploidCircleV2.h"
#include "diploidInput/DiploidEngineInput.h"

class PlayerDefense
{
private:
	DiploidCircleV2 circle;

	float defense_size = 60.0f;

public:
	void Init(VECTOR pos);
	void Updata(DiploidEngineInput* input);
	void Draw(bool debug = false, bool draw = true);

	void SetDefenseSize(float new_size);//攻撃の大きさを設定します。


	DiploidCircleV2* GetDefenseCircleObjectPtr();//circleへのポインタを取得します。
};