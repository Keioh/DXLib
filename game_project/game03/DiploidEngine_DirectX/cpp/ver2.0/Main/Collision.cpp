#include "ver2.0/Main/Collision.h"

bool DiploidCollision::CircleAndCircleCollisionUpdata(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two, int updata_rate)
{
	if (updata_rate <= upadata_count)
	{
		float x = circle_one->GetPosition().x - circle_two->GetPosition().x;
		float y = circle_one->GetPosition().y - circle_two->GetPosition().y;
		float r = circle_one->GetRadius() + circle_two->GetRadius();

		if ((pow(x, 2) + pow(y, 2)) <= pow(r, 2))
		{
			circle_one->SetHitFlag(true);//ヒットフラグをtrueに変更。		
			circle_two->SetHitFlag(true);//ヒットフラグをtrueに変更。

			upadata_count = 0;

			return true;
		}
		else
		{
			circle_one->SetHitFlag(false);//ヒットフラグをfalseに変更。
			circle_two->SetHitFlag(false);//ヒットフラグをfalseに変更。
			upadata_count = 0;

			return false;
		}	
	}
	else
	{
		++upadata_count;//カウントを進める。
	}
}

VECTOR DiploidCollision::CircleAndCircleCollisionPointsUpdata(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two, int updata_rate)
{
	if (updata_rate <= upadata_count)
	{
		float x = circle_one->GetPosition().x - circle_two->GetPosition().x;
		float y = circle_one->GetPosition().y - circle_two->GetPosition().y;
		float r = circle_one->GetRadius() + circle_two->GetRadius();

		if ((pow(x, 2) + pow(y, 2)) <= pow(r, 2))
		{
			//当たった場所を保存
			circle_one->GetHitPointsListPointer()->push_back({ circle_one->GetPosition().x, circle_one->GetPosition().y, 0 });
			circle_two->GetHitPointsListPointer()->push_back({ circle_two->GetPosition().x, circle_two->GetPosition().y, 0 });


			upadata_count = 0;

			return VGet(x, y, r);
		}
		else
		{
			//当たった場所の削除
			if (!circle_one->GetHitPointsListPointer()->empty())
			{
				circle_one->GetHitPointsListPointer()->clear();
			}

			if (!circle_two->GetHitPointsListPointer()->empty())
			{
				circle_two->GetHitPointsListPointer()->clear();
			}

			upadata_count = 0;

			return VGet(-1, -1, -1);
		}
	}
	else
	{
		++upadata_count;//カウントを進める。
	}
}


int DiploidCollision::GetUpdataCounter()
{
	return this->upadata_count;
}