#pragma once
#include "Object_Base.h"

class Input : public ObjectBase
{
private:
	int button_buffer, x_buffer, y_buffer;//�u�ԃN���b�N�̃f�[�^�ۑ��p

public:
	Input();		//�R���X�g���N�^
	~Input(){};		//�f�X�g���N�^

	bool MouseCilck(int MouseInput, int flag);//�u�Ԃ̃N���b�N
	bool MouseInputClick(int mouseinput);//�p���N���b�N
		
};