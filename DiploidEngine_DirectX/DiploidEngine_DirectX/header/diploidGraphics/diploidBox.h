#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObject.h"

class DiploidBox : public DiploidEngineObject
{
private:

public:

	void Init(VECTOR position);//ƒ}ƒEƒX‚É’Ç]‚³‚¹‚éê‡‚Í{0,0,0}‚ğ‘ã“ü
	void Update();
	void Draw(bool wire = true);

};