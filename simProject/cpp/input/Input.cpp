#include "Input.h"


void Input::init()
{
	key_press = false;
	click = false;
	//button_buffer = -1;
	//x_buffer = -1;
	//y_buffer = -1;
	//button_input_log_buffer = -1;
}

int Input::GetKeyFrame()//�L�[�t���[�����K��
{
	GetHitKeyStateAll(key); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int n = 0; n < 256; n++) {
		if (key[n] != 0) { // n�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			frame[n]++;     // ���Z
		}
		else {              // ������Ă��Ȃ����
			frame[n] = 0;   // 0�ɂ���
		}
	}
	return 0;
}

//�u�Ԃ̃N���b�N
bool Input::MouseCilck(int MouseInput)//�኱������������������
{
	//int Button, x, y;

	// �N���b�N�����擾����
	if (GetMouseInputLog2(&button_buffer, &x_buffer, &y_buffer, &button_input_log_buffer, TRUE) == 0)
	{
		if ((GetMouseInput() & button_buffer & MouseInput) != 0)
		{
			return click = true;
		}
	}
	return click = false;
}

//�}�E�X�̌p���N���b�N
bool Input::MouseClickContinuation(int mouseinput)
{
	if ((GetMouseInput() & mouseinput) != 0)
	{
		return  click = true;
	}
	else
	{
		return click = false;
	}
}

//�L�[�̏u�Ԃ̃N���b�N
bool Input::KeyCilick(int keyInput)
{
	if (frame[keyInput] == 1)
	{
		return key_press = true;
	}
	else
	{
		return key_press = false;
	}
}

//�L�[�̌p���N���b�N
bool Input::KeyCilickContinuation(int keyInput)
{
	if (key[keyInput] != 0)
	{
		return key_press = true;
	}
	else
	{
		return key_press = false;
	}
}
