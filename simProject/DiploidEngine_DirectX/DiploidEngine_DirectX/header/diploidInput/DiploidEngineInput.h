#pragma once
#include <vector>
#include "DxLib.h"
//#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidEngineInput
{

private:
	int release_key_flag = -1;

	//�������u�Ԃ̃}�E�X���W
	int press_click_position_x;
	int press_click_position_y;

	//�������u�Ԃ̃}�E�X���W
	int release_click_position_x;
	int release_click_position_y;

	//���݂̃}�E�X���W
	int mouse_pos_adr_x;
	int mouse_pos_adr_y;


	int press_time = 0;//�����Ă��鎞��
	int release_time = 0;//�����Ă��鎞��

public:	
	char key[256];
	//char buffer[256];

	int Check_Mouse;
	int MOUSE_BUTTON = 0;
	int CLICK_X = 0;
	int CLICK_Y = 0;
	int LOG_TYPE = 0;


	void Init();
	void Update();
	void Draw(int x, int y, bool debug = false);

	bool GetKey(int DXLIB_KEY_CODE);//�L�[���������������Ă��Ȃ����̔���B(�����Ă�����true���Ԃ�)
	bool GetPressKey(int DXLIB_KEY_CODE);//�L�[���������u�Ԃ̔���B(�����u�Ԃ�true���Ԃ�)
	bool GetReleaseKey(int DXLIB_KEY_CODE);//�L�[�𗣂��ꂽ�u�Ԃ̔���B(�������u�Ԃ�true���Ԃ�)

	bool GetMouse(int DXLIB_MOUSE_CODE);//�}�E�X���������������Ă��Ȃ����̔���B(�����Ă�����true���Ԃ�)
	bool GetPressMouse(int DXLIB_MOUSE_CODE);//�}�E�X���������u�Ԃ̔���B(�������u�Ԃ�true���Ԃ�)
	bool GetReleaseMouse(int DXLIB_MOUSE_CODE);//�}�E�X�𗣂����u�Ԃ̔���B(�������u�Ԃ�true���Ԃ�)

	VECTOR GetMousePressPosition();//�������u�Ԃ̃}�E�X���W�̎擾�B
	VECTOR GetMouseReleasePosition();//�������u�Ԃ̃}�E�X���W�̎擾�B
	VECTOR GetMousePosition();//���݂̃}�E�X���W�̎擾�B

};