#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Graphics/DiploidImageV2.h"

//条件付きボタン
class ConditionalButton
{
private:
	DiploidSelectedUIV2 button;
	DiploidImageV2 image;

	int conditional = 0;

public:
	void LoadGraphics();
	void LoadHandl();
	void Init(VECTOR pos, float scale);
	void Updata(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);

	DiploidSelectedUIV2* GetButtonInfo();//DiploidSelectedUIV2の情報を得る。
	DiploidImageV2* GetImageInfo();//DiploidImageV2の情報を得る。(LOCK画像)

};