#pragma once
#include <vector>
#include "DxLib.h"
//#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidEngineInput
{

private:

	int press_time = 0;//�����Ă��鎞��
	int release_time = 0;//�����Ă��鎞��

public:	
	char Key[256];

	int Check_Mouse;
	int MOUSE_BUTTON = 0;
	int CLICK_X = 0;
	int CLICK_Y = 0;
	int LOG_TYPE = 0;


	void Init();
	void Update();
	void Draw(int x, int y, bool debug = false);

	bool GetKey(int DXLIB_KEY_CODE);//�L�[���������������Ă��Ȃ����̔���B(�����Ă�����true���Ԃ�)
	bool GetPressKey(int DXLIB_KEY_CODE);//�L�[���������u�Ԃ̔���B(�����Ă�����true���Ԃ�)
	bool GetReleaseKey(int DXLIB_KEY_CODE);//�L�[�𗣂��ꂽ�u�Ԃ̔���B(�����Ă�����true���Ԃ�)

	bool GetMouse(int DXLIB_MOUSE_CODE);//�}�E�X���������������Ă��Ȃ����̔���B(�����Ă�����true���Ԃ�)
	bool GetPressMouse(int DXLIB_MOUSE_CODE);//�}�E�X���������u�Ԃ̔���B(�����Ă�����true���Ԃ�)
	bool GetReleaseMouse(int DXLIB_MOUSE_CODE);//�}�E�X�𗣂����u�Ԃ̔���B(�����Ă�����true���Ԃ�)

};