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
	//aからbに加算減算等を行っています。(a + b)
	float VectorAdd(float a, float b);//ベクトル加算(一次元)
	float VectorSub(float a, float b);//ベクトル減算(一次元)

	//aからbに加算減算等を行っています。{(a.x + b.x),(a.y + b.y)} 
	Vector2 Vector2Add(Vector2 a, Vector2 b);//ベクトル加算(二次元)
	Vector2 Vector2Sub(Vector2 a, Vector2 b);//ベクトル減算(二次元)

	float ThreeSquares(float a, float b);//直角三角形の斜辺の値を取得します。(aとbは直角に交わる。)

	float ToDegree(float radian_angle);//ラジアンを度数に変換
	float ToRadian(float degree_angle);//度数をラジアンに変換

	float EquilateralTriangleHeight(float length);//斜辺の長さから正三角形の高さを計算します。
	float EquilateralTriangleLength(float height);//高さから正三角形の斜辺の長さを計算します。

};

