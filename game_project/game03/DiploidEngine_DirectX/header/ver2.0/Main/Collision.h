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
	
};