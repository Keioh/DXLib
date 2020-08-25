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


	bool press_click_mouse;
	bool release_click_mouse;

	int press_time_mouse = 0;
	int release_time_mouse = 0;

	int press_time = 0;//�����Ă��鎞��
	int release_time = 0;//�����Ă��鎞��

	//�^�b�`�֘A
	int touch_position_x;//�^�b�`���Ă���X���W
	int touch_position_y;//�^�b�`���Ă���Y���W
	int touch_id;//�^�b�`ID
	int touch_device_id;//�f�o�C�XID

	int touch_size;//�^�b�`���Ă��鐔

	int touch_release_flag;


public:	

	//���݂̃}�E�X���W
	int mouse_pos_adr_x;
	int mouse_pos_adr_y;

	//�}�E�X�z�C�[���̉�]�֌W
	float mouse_whell_volume = 0;
	float mouse_whell_scale = 1.0f;

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
	bool GetPressKey(int DXLIB_KEY_CODE);//�L�[���������u�Ԃ̔���B(�����u�Ԃ�true���Ԃ�)
	bool GetReleaseKey(int DXLIB_KEY_CODE);//�L�[�𗣂��ꂽ�u�Ԃ̔���B(�������u�Ԃ�true���Ԃ�)

	bool GetMouse(int DXLIB_MOUSE_CODE);//�}�E�X���������������Ă��Ȃ����̔���B(�����Ă�����true���Ԃ�)
	bool GetPressMouse(int DXLIB_MOUSE_CODE);//�}�E�X���������u�Ԃ̔���B(�������u�Ԃ�true���Ԃ�)
	bool GetReleaseMouse(int DXLIB_MOUSE_CODE);//�}�E�X�𗣂����u�Ԃ̔���B(�������u�Ԃ�true���Ԃ�)
	int GetWhellVolume();//�}�E�X�z�C�[���̉�]�����u�ԓI�Ɏ擾���܂��B
	float GetWhellVolume_Scale(float max = 5.0f, float min = 0.2f, float scale = 0.1f);//�}�E�X�z�C�[���̉�]�������ɃX�P�[���l���擾���܂��B(�����l��1.0f�Amax�ɂ̓X�P�[���ő�l���w��Amin�ɂ͍ŏ��l���w��, scale�ɂ͉�]���̔{�����w��)

	VECTOR GetMousePressPosition();//�������u�Ԃ̃}�E�X���W�̎擾�B
	VECTOR GetMouseReleasePosition();//�������u�Ԃ̃}�E�X���W�̎擾�B
	VECTOR GetMousePosition();//���݂̃}�E�X���W�̎擾�B

	bool GetTouch();//�^�b�`���Ă���ԁAtrue���Ԃ�B
	bool GetReleaseTouch();//�w�������ꂽ�u�Ԃ̔���B(�������u�Ԃ�true���Ԃ�B)
	int GetTouchPositionX();//�^�b�`���ꂽ�u�Ԃ�X���W
	int GetTouchPositionY();//�^�b�`���ꂽ�u�Ԃ�Y���W

	int GetTouchReleaseFlag();
};