#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"

class OptionScene
{
private:
	DiploidAnimation return_button_animation;//戻るボタンのアニメーション画像
	DiploidSelectedUIV2 return_button;//戻るボタン

public:

	void Load();
	void Init(DiploidEngineSetting& setting);
	void Updata(DiploidEngineInput& input);
	void Draw(bool draw = true, bool debug = false);

	bool GetReturnFlag();//戻るボタンが押されたらtrueが返る。
};