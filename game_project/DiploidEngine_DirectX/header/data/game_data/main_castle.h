#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidUI/diploidUI.h"

class MyCastle
{
private:
	DiploidObject json;//JSONファイル読み込み用
	DiploidObject back_color_circle_object;//拠点の背景色
	DiploidObject defense_circle_object;//防壁オブジェクト

	DiploidUI ui;//拠点選択UIオブジェクト

	int population;
	int defense;
	int money;
	int size;

public:
	MyCastle();//コンストラクタ
	
	void Load();//Jsonファイルと画像や音など
	void Inti(VECTOR position = { 0.0f,0.0f,0.0f }, float radius = 10.0f);
	void Push(DiploidEngineImpact& impact);
	void Updata(DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool wire = true, bool debug = false);

};