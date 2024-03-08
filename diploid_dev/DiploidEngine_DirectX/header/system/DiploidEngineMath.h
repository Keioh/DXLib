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
	//a����b�ɉ��Z���Z�����s���Ă��܂��B(a + b)
	float VectorAdd(float a, float b);//�x�N�g�����Z(�ꎟ��)
	float VectorSub(float a, float b);//�x�N�g�����Z(�ꎟ��)

	//a����b�ɉ��Z���Z�����s���Ă��܂��B{(a.x + b.x),(a.y + b.y)} 
	Vector2 Vector2Add(Vector2 a, Vector2 b);//�x�N�g�����Z(�񎟌�)
	Vector2 Vector2Sub(Vector2 a, Vector2 b);//�x�N�g�����Z(�񎟌�)

	float ThreeSquares(float a, float b);//���p�O�p�`�̎Εӂ̒l���擾���܂��B(a��b�͒��p�Ɍ����B)

	float ToDegree(float radian_angle);//���W�A����x���ɕϊ�
	float ToRadian(float degree_angle);//�x�������W�A���ɕϊ�

	float EquilateralTriangleHeight(float length);//�Εӂ̒������琳�O�p�`�̍������v�Z���܂��B
	float EquilateralTriangleLength(float height);//�������琳�O�p�`�̎Εӂ̒������v�Z���܂��B

};
