#include "ver2.0/Main/Transform.h"

VECTOR Transform::GetPosition()//位置を取得します。
{
	return Transform::position;
}

VECTOR Transform::GetSize()//大きさを取得します。
{
	return Transform::size;
}


int Transform::GetColorRed()//赤色の数値を取得します。(整数値)
{
	return Transform::red;
}

int Transform::GetColorBlue()//青色の数値を取得します。(整数値)
{
	return Transform::blue;
}

int Transform::GetColorGreen()//緑色の数値を取得します。(整数値)
{
	return Transform::green;
}


void Transform::SetPosition(VECTOR new_position)//新しい位置を設定します。
{
	Transform::position = new_position;
}

void Transform::SetSize(VECTOR new_size)//新しい大きさを設定します。
{
	Transform::size = new_size;
}


void Transform::SetColorRed(int new_color)//新しい色を指定します。(赤)
{
	Transform::red = new_color;
}

void Transform::SetColorBlue(int new_color)//新しい色を指定します。(青)
{
	Transform::blue = new_color;
}

void Transform::SetColorGreen(int new_color)//新しい色を指定します。(緑)
{
	Transform::green = new_color;
}