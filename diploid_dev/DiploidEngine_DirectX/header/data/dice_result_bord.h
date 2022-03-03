#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "data/number.h"

//îwåiÇ†ÇËÇÃêîílï\é¶
class DiceResultBord
{
private:
	Number number_1;
	Number number_2;
	Number number_3;

	DiploidObject edge;
	DiploidObject back;

public:
	DiceResultBord();
	~DiceResultBord() {};

	void Load();
	void Init(VECTOR pos = { 0.0f,0.0f,0.0f }, float scale = 1.0f);
	void Update();
	void Draw(int result_number, bool draw = true);

};