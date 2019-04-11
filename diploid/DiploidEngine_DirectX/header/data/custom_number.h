#pragma once
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidObject/DiploidEngineObject.h"
#include "diploidObject/DiploidEngineTag.h"
#include "data/number.h"

//ユーザーの入力によって数値を決定する処理。
class CustomNumber
{
private:
	DiploidObject plus;
	DiploidObject minus;
	DiploidObject clear;
	DiploidObject in;

	DiploidObject back_3;


	DiploidObject back_1;
	DiploidObject edge_1;
	DiploidObject mark_1;

	DiploidObject back_1_copy;
	DiploidObject edge_1_copy;
	DiploidObject mark_1_copy;


	DiploidObject back_2;
	DiploidObject edge_2;
	DiploidObject mark_2;

	DiploidObject back_2_copy;
	DiploidObject edge_2_copy;
	DiploidObject mark_2_copy;

	DiploidBox box;

	Number number_1;
	Number number_2;
	Number number_3;
	Number number_4;


	DiploidEngineInput input;

	bool in_active = false;

	int key_input_handl;

public:
	CustomNumber();
	~CustomNumber() {};

	int custom_number;//変更したり入力した数値の結果。

	void Load();
	void Push(DiploidEngineImpact& impact, VECTOR pos, float scale);
	void Init(VECTOR pos = {0.0f,0.0f,0.0f}, float scale = 1.0f);
	void Update(DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(DiploidEngineImpact& impact, bool draw = true);
};