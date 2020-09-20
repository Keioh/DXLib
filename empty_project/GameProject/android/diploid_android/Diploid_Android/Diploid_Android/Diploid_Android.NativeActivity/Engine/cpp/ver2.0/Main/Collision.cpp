#include "ver2.0/Main/Collision.h"

bool DiploidCollision::CircleAndCircleCollisionUpdate(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two, int updata_rate)
{
	if (updata_rate <= upadata_count)
	{
		float x = circle_one->GetPosition().x - circle_two->GetPosition().x;
		float y = circle_one->GetPosition().y - circle_two->GetPosition().y;
		float r = circle_one->GetRadius() + circle_two->GetRadius();

		if ((pow(x, 2) + pow(y, 2)) <= pow(r, 2))
		{
			if (circle_one->GetHitFlag() != true)
			{
				circle_one->SetHitFlag(true);//ヒットフラグをtrueに変更。		
			}

			if (circle_two->GetHitFlag() != true)
			{
				circle_two->SetHitFlag(true);//ヒットフラグをtrueに変更。
			}

			upadata_count = 0;

			return true;
		}
		else
		{
			if (circle_one->GetHitFlag() != false)
			{
				circle_one->SetHitFlag(false);//ヒットフラグをfalseに変更。
			}

			if (circle_two->GetHitFlag() != false)
			{
				circle_two->SetHitFlag(false);//ヒットフラグをfalseに変更。
			}

			upadata_count = 0;

			return false;
		}	
	}
	else
	{
		++upadata_count;//カウントを進める。
	}
}

VECTOR DiploidCollision::CircleAndCircleCollisionPointsUpdate(DiploidCircleV2* circle_one, DiploidCircleV2* circle_two, int updata_rate)
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


bool DiploidCollision::BoxAndMouseCollisionUpdate(DiploidBoxV2* box, int mouse_x, int mouse_y, int updata_rate)
{
	if ((box->GetPosition().x <= window_size_x) && (box->GetPosition().x + box->GetSize().x >= 0)
		&& (box->GetPosition().y <= window_size_y) && (box->GetPosition().y + box->GetSize().y >= 0))
	{
		if (updata_rate <= upadata_count)
		{
			if ((box->GetPosition().x < mouse_x) && (box->GetPosition().x + box->GetSize().x > mouse_x)
				&& (box->GetPosition().y < mouse_y) && (box->GetPosition().y + box->GetSize().y > mouse_y))
			{
				if (box->GetHitFlag() != true)
				{
					box->SetHitFlag(true);//ヒットフラグをtrueに変更
				}

				upadata_count = 0;

				return true;
			}
			else
			{
				if (box->GetHitFlag() != false)
				{
					box->SetHitFlag(false);//ヒットフラグをfalseに変更
				}

				upadata_count = 0;

				return false;
			}
		}
	}
}

bool DiploidCollision::BoxAndTouchCollisionUpdate(DiploidBoxV2* box, int touch_x, int touch_y, int updata_rate)
{
	if ((box->GetPosition().x <= window_size_x) && (box->GetPosition().x + box->GetSize().x >= 0)
		&& (box->GetPosition().y <= window_size_y) && (box->GetPosition().y + box->GetSize().y >= 0))
	{
		if (updata_rate <= upadata_count)
		{
			if ((box->GetPosition().x < touch_x) && (box->GetPosition().x + box->GetSize().x > touch_x)
				&& (box->GetPosition().y < touch_y) && (box->GetPosition().y + box->GetSize().y > touch_y))
			{
				if (box->GetHitFlag() != true)
				{
					box->SetHitFlag(true);//ヒットフラグをtrueに変更
				}

				upadata_count = 0;

				return true;
			}
			else
			{
				if (box->GetHitFlag() != false)
				{
					box->SetHitFlag(false);//ヒットフラグをfalseに変更
				}

				upadata_count = 0;

				return false;
			}
		}
	}
}


int DiploidCollision::GetUpdateCounter()
{
	return this->upadata_count;
}