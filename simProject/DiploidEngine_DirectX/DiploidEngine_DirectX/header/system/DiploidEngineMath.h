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
	float VectorAdd(float a, float b);//�x�N�g�����Z(x,y�̍��W�ŕԂ��Ă��܂��B)
	float VectorSub(float a, float b);//�x�N�g�����Z(x,y�̍��W�ŕԂ��Ă��܂��B)
	float DotProduct(float a, float b, float angle);//�h�b�g��(����)���Z�o���܂��B(���p�O�p�`�Ƃ��Č����Ƃ������_���n�_�Ƃ�b����ӂ�a���ΕӂƂȂ�Ƃ�cos�Ōv�Z)
	float CrossProduct(float one, float two);//�N���X��(�O��)

	float DotProduct(Vector2 a, Vector2 b);//�h�b�g��(����)�𐬕��ŎZ�o���܂��B(���p�O�p�`�Ƃ��Č����Ƃ������n�_�Ƃ�b����ӂ�a���ΕӂƂȂ�Ƃ�cos�Ōv�Z)

	float ThreeSquares(float a, float b);//���p�O�p�`�̎Εӂ̒l���擾���܂��B

	float DotProductPointAndLine(VECTOR point, VECTOR a, float angle);//�_�Ɛ����̌��݂̍ŒZ�������Z�o���܂��B(point���_�Aa�������n�_�A[b�������I�_])

	float ToDegree(float angle);//���W�A����x���ɕϊ�
};

