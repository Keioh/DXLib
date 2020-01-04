#pragma once
#include "DxLib.h"

class Transform//�ϊ��n�ƐF�n�Ǝ擾�n����
{
private:

protected:
	VECTOR position;//�ʒu
	VECTOR size;//�傫��

	int red;//��
	int blue;//��
	int green;//��

public:
	virtual VECTOR GetPosition();//�ʒu���擾���܂��B
	virtual VECTOR GetSize();//�傫�����擾���܂��B

	virtual int GetColorRed();//�ԐF�̐��l���擾���܂��B(�����l)
	virtual int GetColorBlue();//�F�̐��l���擾���܂��B(�����l)
	virtual int GetColorGreen();//�ΐF�̐��l���擾���܂��B(�����l)

	virtual void SetPosition(VECTOR new_position);//�V�����ʒu��ݒ肵�܂��B
	virtual void SetSize(VECTOR new_size);//�V�����傫����ݒ肵�܂��B

	virtual void SetColorRed(int new_color);//�V�����F���w�肵�܂��B(��)
	virtual void SetColorBlue(int new_color);//�V�����F���w�肵�܂��B(��)
	virtual void SetColorGreen(int new_color);//�V�����F���w�肵�܂��B(��)

};
