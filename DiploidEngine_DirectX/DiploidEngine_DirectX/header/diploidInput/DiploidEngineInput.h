#pragma once
#include "DxLib.h"
//#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidEngineInput
{

private:
	int press_time;//�����Ă��鎞��
	int release_time;//�����Ă��鎞��

public:	

	void Init();
	void Update();
	void Draw(bool debug = false);

	bool GetKey(int DXLIB_KEY_CODE);//�L�[���������������Ă��Ȃ����̔���B(�����Ă�����true���Ԃ�)
};