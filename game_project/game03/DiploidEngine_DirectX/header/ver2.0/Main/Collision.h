#pragma once
#include <list>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"

using namespace std;

class DiploidCollision
{
private:

protected:

public:
	bool CircleAndCircleCollisionUpdata(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two);//円と円の当たり判定を実行します。(戻り値は二つの円がヒットしていたらtrueを返します。)
	VECTOR CircleAndCircleCollisionPointsUpdata(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two);//円と円が当たった瞬間の位置を得ます。(戻り値は当たった場所の位置を返します。zには半径が入っています。)
};