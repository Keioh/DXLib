#include "ver2.0/Main/Transform.h"

VECTOR Transform::GetPosition()//�ʒu���擾���܂��B
{
	return Transform::position;
}

VECTOR Transform::GetSize()//�傫�����擾���܂��B
{
	return Transform::size;
}


int Transform::GetColorRed()//�ԐF�̐��l���擾���܂��B(�����l)
{
	return Transform::red;
}

int Transform::GetColorBlue()//�F�̐��l���擾���܂��B(�����l)
{
	return Transform::blue;
}

int Transform::GetColorGreen()//�ΐF�̐��l���擾���܂��B(�����l)
{
	return Transform::green;
}


void Transform::SetPosition(VECTOR new_position)//�V�����ʒu��ݒ肵�܂��B
{
	Transform::position = new_position;
}

void Transform::SetSize(VECTOR new_size)//�V�����傫����ݒ肵�܂��B
{
	Transform::size = new_size;
}


void Transform::SetColorRed(int new_color)//�V�����F���w�肵�܂��B(��)
{
	Transform::red = new_color;
}

void Transform::SetColorBlue(int new_color)//�V�����F���w�肵�܂��B(��)
{
	Transform::blue = new_color;
}

void Transform::SetColorGreen(int new_color)//�V�����F���w�肵�܂��B(��)
{
	Transform::green = new_color;
}