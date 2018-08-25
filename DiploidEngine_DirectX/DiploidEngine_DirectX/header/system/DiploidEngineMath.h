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
	float VectorAdd(float a, float b);//ベクトル加算(x,yの座標で返してきます。)
	float VectorSub(float a, float b);//ベクトル減算(x,yの座標で返してきます。)
	float DotProduct(float a, float b, float angle);//ドット積(内積)を算出します。(直角三角形として見たとき同じ点を始点としbが底辺でaが斜辺となるときcosで計算)
	float CrossProduct(float one, float two);//クロス積(外積)

	float DotProduct(Vector2 a, Vector2 b);//ドット積(内積)を成分で算出します。(直角三角形として見たとき同じ始点としbが底辺でaが斜辺となるときcosで計算)

	float ThreeSquares(float a, float b);//直角三角形の斜辺の値を取得します。

	float DotProductPointAndLine(VECTOR point, VECTOR a, float angle);//点と線分の現在の最短距離を算出します。(pointが点、aが線分始点、[bが線分終点])

	float ToDegree(float angle);//ラジアンを度数に変換
};

