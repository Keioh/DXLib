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
	//oneからtwoに加算減算等を行っています。
	Vector2 VectorAdd(Vector2 one, Vector2 two);//ベクトル加算(x,yの座標で返してきます。)
	Vector2 VectorSub(Vector2 one, Vector2 two);//ベクトル減算(x,yの座標で返してきます。)
	float DotProduct(float a, float b);//ドット積(内積)ベクトルから算出します。(直角三角形として見たとき同じ始点としbが底辺でaが斜辺となるときcosで計算)
	float CrossProduct(float one, float two);//クロス積(外積)

	float ThreeSquares(float a, float b);//直角三角形の斜辺の値を取得します。

};

