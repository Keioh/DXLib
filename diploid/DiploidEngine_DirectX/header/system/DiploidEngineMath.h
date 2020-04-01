#pragma once
#include <math.h>
#include "DxLib.h"

//���2D�x�N�g���v�Z�̂��߂ɍ쐬

struct Vector2
{
	float x;
	float y;
};


class DiploidEngineMath
{
private:

public:
	//a����b�ɉ��Z���Z�����s���Ă��܂��B
	float VectorAdd(float a, float b);//�x�N�g�����Z(�ꎟ��)
	float VectorSub(float a, float b);//�x�N�g�����Z(�ꎟ��)

	float ThreeSquares(float a, float b);//���p�O�p�`�̎Εӂ̒l���擾���܂��B(a��b�͒��p�Ɍ����B)

	float ToDegree(float radian_angle);//���W�A����x���ɕϊ�
	float ToRadian(float degree_angle);//�x�������W�A���ɕϊ�
};

