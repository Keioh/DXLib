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
	//one����two�ɉ��Z���Z�����s���Ă��܂��B
	Vector2 VectorAdd(Vector2 one, Vector2 two);//�x�N�g�����Z(x,y�̍��W�ŕԂ��Ă��܂��B)
	Vector2 VectorSub(Vector2 one, Vector2 two);//�x�N�g�����Z(x,y�̍��W�ŕԂ��Ă��܂��B)
	float DotProduct(float a, float b);//�h�b�g��(����)�x�N�g������Z�o���܂��B(���p�O�p�`�Ƃ��Č����Ƃ������n�_�Ƃ�b����ӂ�a���ΕӂƂȂ�Ƃ�cos�Ōv�Z)
	float CrossProduct(float one, float two);//�N���X��(�O��)

	float ThreeSquares(float a, float b);//���p�O�p�`�̎Εӂ̒l���擾���܂��B

};

