#include "ver2.0/Main/Collision.h"

bool DiploidCollision::CircleAndCircleCollisionUpdata(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two)
{
	float x = circle_one->GetPosition().x - circle_two->GetPosition().x;
	float y = circle_one->GetPosition().y - circle_two->GetPosition().y;
	float r = circle_one->GetRadius() + circle_two->GetRadius();

	if ((pow(x, 2) + pow(y, 2)) <= pow(r, 2))
	{
		circle_one->SetHitFlag(true);//�q�b�g�t���O��true�ɕύX�B
		circle_two->SetHitFlag(true);//�q�b�g�t���O��true�ɕύX�B

		return true;
	}
	else
	{
		circle_one->SetHitFlag(false);//�q�b�g�t���O��false�ɕύX�B
		circle_two->SetHitFlag(false);//�q�b�g�t���O��false�ɕύX�B

		return false;
	}
}