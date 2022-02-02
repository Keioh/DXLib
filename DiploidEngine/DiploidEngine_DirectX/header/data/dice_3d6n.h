#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"

#include "data/dice.h"
#include "data/custom_number.h"
#include "data/number.h"

class Dice3D6n
{
private:
	DiploidObject result;

	Dice dice_1;
	Dice dice_2;
	Dice dice_3;

	CustomNumber custom_number;

	Number number_1;
	Number number_2;
	Number number_3;
	Number number_4;

public:
	Dice3D6n();
	~Dice3D6n() {};

	int number;

	void Load();
	void Init(DiploidEngineImpact& impact, VECTOR pos);
	void Update(DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(DiploidEngineImpact& impact, bool draw = true);

	bool DiceActiveFlags();
};