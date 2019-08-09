#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"

//さいころの処理
class Dice
{
private:
	int roll_time;//振り続ける時間

	DiploidObject dice_1;
	DiploidObject dice_2;
	DiploidObject dice_3;
	DiploidObject dice_4;
	DiploidObject dice_5;
	DiploidObject dice_6;

	DiploidBox box;

	DiploidEngineInput input;

	bool dice_roll;//さいころを振るか降らないか

public:
	Dice();
	~Dice() {};

	int dice_number;//さいころの目を返す。

	bool dice_roll_active;//さいころを振っている最中か、そうじゃないか。

	void Load();//画像の読み込み。
	void Init(VECTOR pos = { 0.0f,0.0f,0.0f }, float scale = 1.0f);//初期化
	void Push(DiploidEngineImpact& impact, VECTOR pos, float scale);//当たり判定追加
	void Update();//更新処理
	void Draw(bool draw = true);//描写処理

	void Roll();//ダイスを振る

};