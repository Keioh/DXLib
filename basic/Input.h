#pragma once
#include "Object_Base.h"

class Input : public ObjectBase
{
private:
	int button_buffer, button_input_log_buffer, x_buffer, y_buffer;//�u�ԃN���b�N�̃f�[�^�ۑ��p

public:
	~Input(){};		//�f�X�g���N�^

	bool click;

	void init();

	bool MouseCilck(int MouseInput);//�u�Ԃ̃N���b�N
	bool MouseClickContinuation(int mouseinput);//�p���N���b�N
		
};