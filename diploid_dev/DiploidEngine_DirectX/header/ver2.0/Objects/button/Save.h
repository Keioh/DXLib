#pragma once
#include "DxLib.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"
#include "system\DiploidEngineSetting.h"

class Save
{
private:
	DiploidAnimation button_animation;//戻るボタンのアニメーション画像
	DiploidSelectedUIV2 button;//戻るボタン

public:
	void Load();
	void Init(VECTOR pos);
	void Update(DiploidEngineInput& input);
	void Draw(float frame_time = 1.0f, bool draw = true, bool debug = false);

	bool GetHit();//カーソルが当たっているか
	bool GetClick();//クリックされたか
	int GetSelected();//選択状態か

	void SetPosition(VECTOR new_pos);

	void SetSelectedFlag(int new_flag);
};