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

VECTOR DiploidCollision::CircleAndCircleCollisionPointsUpdata(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two)
{
	float x = circle_one->GetPosition().x - circle_two->GetPosition().x;
	float y = circle_one->GetPosition().y - circle_two->GetPosition().y;
	float r = circle_one->GetRadius() + circle_two->GetRadius();

	if ((pow(x, 2) + pow(y, 2)) <= pow(r, 2))
	{
		//���������ꏊ��ۑ�
		circle_one->GetHitPointsListPointer()->push_back({ circle_one->GetPosition().x, circle_one->GetPosition().y, 0 });
		circle_two->GetHitPointsListPointer()->push_back({ circle_two->GetPosition().x, circle_two->GetPosition().y, 0 });

		return VGet(x, y, r);
	}
	else
	{
		//���������ꏊ�̍폜
		if (!circle_one->GetHitPointsListPointer()->empty())
		{
			circle_one->GetHitPointsListPointer()->clear();
		}

		if (!circle_two->GetHitPointsListPointer()->empty())
		{
			circle_two->GetHitPointsListPointer()->clear();
		}
		return VGet(-1, -1, -1);
	}

}