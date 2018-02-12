#pragma once
#include "Object_Base.h"

class Input : public ObjectBase
{
private:
	int button_buffer, button_input_log_buffer, x_buffer, y_buffer;//�u�ԃN���b�N�̃f�[�^�ۑ��p
	bool key_press_flag, press_one;

	char key[256];
	int frame[256];//�J�E���^�[

public:
	~Input(){};		//�f�X�g���N�^

	bool click, key_press;

	void init();

	int GetKeyFrame();//�L�[�t���[�����K��

	bool MouseCilck(int MouseInput);//�u�Ԃ̃N���b�N
	bool MouseClickContinuation(int mouseinput);//�p���N���b�N

	bool KeyCilick(int keyInput);//�u�Ԃ̃N���b�N
	bool KeyCilickContinuation(int keyInput);//�u�Ԃ̃N���b�N

};