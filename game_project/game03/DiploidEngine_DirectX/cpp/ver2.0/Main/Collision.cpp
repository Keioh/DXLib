#include "ver2.0/Main/Collision.h"

bool DiploidCollision::CircleAndCircleCollisionUpdata(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two)
{
	float x = circle_one->GetPosition().x - circle_two->GetPosition().x;
	float y = circle_one->GetPosition().y - circle_two->GetPosition().y;
	float r = circle_one->GetRadius() + circle_two->GetRadius();

	if ((pow(x, 2) + pow(y, 2)) <= pow(r, 2))
	{
		circle_one->SetHitFlag(true);//ヒットフラグをtrueに変更。
		circle_two->SetHitFlag(true);//ヒットフラグをtrueに変更。

		return true;
	}
	else
	{
		circle_one->SetHitFlag(false);//ヒットフラグをfalseに変更。
		circle_two->SetHitFlag(false);//ヒットフラグをfalseに変更。

		return false;
	}
}