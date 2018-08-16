#pragma once
#include "DxLib.h"
//#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidEngineInput
{

private:
	int press_time;//‰Ÿ‚µ‚Ä‚¢‚éŠÔ
	int release_time;//—£‚µ‚Ä‚¢‚éŠÔ

public:	

	void Init();
	void Update();
	void Draw(bool debug = false);

	bool GetKey(int DXLIB_KEY_CODE);//ƒL[‚ğ‰Ÿ‚µ‚½‚©‰Ÿ‚µ‚Ä‚¢‚È‚¢‚©‚Ì”»’èB(‰Ÿ‚µ‚Ä‚¢‚½‚çtrue‚ª•Ô‚é)
};