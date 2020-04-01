#pragma once
#include <math.h>
#include "DxLib.h"

//主に2Dベクトル計算のために作成

struct Vector2
{
	float x;
	float y;
};


class DiploidEngineMath
{
private:

public:
	//aからbに加算減算等を行っています。
	float VectorAdd(float a, float b);//ベクトル加算(一次式)
	float VectorSub(float a, float b);//ベクトル減算(一次式)

	float ThreeSquares(float a, float b);//直角三角形の斜辺の値を取得します。(aとbは直角に交わる。)

	float ToDegree(float radian_angle);//ラジアンを度数に変換
	float ToRadian(float degree_angle);//度数をラジアンに変換
};

