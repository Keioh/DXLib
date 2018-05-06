#include "diploidImpact\DiploidEngineImpact.h"

void DiploidEngineImpact::PushCircle(DiploidCircle circle)
{
	circle_vector.push_back(circle);
}

void DiploidEngineImpact::PushPoint(DiploidPoint point)
{
	point_vector.push_back(point);
}

void DiploidEngineImpact::PushBox(DiploidBox box)
{
	box_vector.push_back(box);
}

void DiploidEngineImpact::PopBackCircle()
{
	if (!circle_vector.empty())
	{
		circle_vector.pop_back();
	}
}

void DiploidEngineImpact::PopBackPoint()
{
	if (!point_vector.empty())
	{
		point_vector.pop_back();
	}
}

void DiploidEngineImpact::PopBackBox()
{
	if (!box_vector.empty())
	{
		box_vector.pop_back();
	}
}

void DiploidEngineImpact::DestoryCircle()
{	
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			if ((circle->impacted == true) && (circle->destory == true))
			{
				circle_vector.erase(circle);
				circle = circle_vector.begin();
			}
		}
	}
}

void DiploidEngineImpact::ImpactCirclePoint()
{
	if (!point_vector.empty() && !circle_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
			{
				float x = 0, y = 0;

				x = (circle->position.x - point->position.x);
				y = (circle->position.y - point->position.y);

				if (std::pow(x, 2) + std::pow(y, 2) <= std::pow(circle->size.z, 2))
				{
					circle->impacted = true;
					point->impacted = true;
				}
			}
		}
	}
}

void DiploidEngineImpact::ImpactCircleCircle()
{
	if (!circle_vector.empty())
	{
		for (size_t circle_one = 0; circle_one != circle_vector.size(); ++circle_one)
		{
			for (size_t circle_two = 1; circle_two != circle_vector.size(); ++circle_two)
			{
				float x = 0, y = 0, r = 0;

				if (circle_one == circle_two)//同じ値なら計算しない
				{
					//x = 0;
					//y = 0;
					//r = 0;
				}
				else if(circle_vector[circle_one].impacted == false)
				{
					x = (circle_vector[circle_one].position.x - circle_vector[circle_two].position.x);
					y = (circle_vector[circle_one].position.y - circle_vector[circle_two].position.y);
					r = (circle_vector[circle_one].size.z + circle_vector[circle_two].size.z);

					if ((std::pow(x, 2) + std::pow(y, 2)) <= std::pow(r, 2))
					{
						circle_vector[circle_one].impacted = true;
					}
				}
			}
		}
	}
}

void DiploidEngineImpact::ImpactBoxPoint()
{
	if (!point_vector.empty() && !box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
			{
				if ((box->position.x <= point->position.x) && ((box->position.x + box->size.x) >= point->position.x))
				{
					if ((box->position.y <= point->position.y) && ((box->position.y + box->size.y) >= point->position.y))
					{
						point->impacted = true;
						box->impacted = true;
					}
				}
			}
		}
	}
}

void DiploidEngineImpact::ImpactBoxBox()
{
	if (!box_vector.empty())
	{
		for (auto box_one = box_vector.begin(); box_one != box_vector.end(); ++box_one)
		{
			for (auto box_two = box_vector.begin() + 1; box_two != box_vector.end(); ++box_two)
			{

			}
		}
	}
}

void DiploidEngineImpact::Updata()
{
	//円の更新処理
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			circle->Update();//アニメアプデ
		}
	}

	//点の更新処理
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			point->Update();//アニメアプデ
		}
	}

	//四角の更新処理
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			box->Update();//アニメアプデ
		}
	}

	ImpactCirclePoint();//円と点の衝突計算
	ImpactCircleCircle();//円と円の衝突計算
	ImpactBoxPoint();//四角と点の衝突計算
	ImpactBoxBox();//四角と四角の衝突計算
}

void DiploidEngineImpact::Init()
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			//円がヒットしていたら
			if (circle->impacted == true)
			{
				circle->impacted = false;
			}
		}
	}

	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			//点がヒットしていたら
			if (point->impacted == true)
			{
				point->impacted = false;
			}
		}
	}

	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			//四角がヒットしていたら
			if (box->impacted == true)
			{
				box->impacted = false;
			}
		}
	}
}

void DiploidEngineImpact::Draw(bool wire)
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			//円がヒットしていたら
			if (circle->impacted == true)
			{
				circle->color = GetColor(255, 0, 0);
			}
			else
			{
				circle->color = GetColor(0, 0, 255);
			}	
			
			circle->Draw(wire);
		}
	}

	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			//点がヒットしていたら
			if (point->impacted == true)
			{
				point->color = GetColor(255, 0, 0);
			}
			else
			{
				point->color = GetColor(0, 0, 255);
			}	
			
			point->Draw(wire);
		}
	}

	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			//四角がヒットしていたら
			if (box->impacted == true)
			{
				box->color = GetColor(255, 0, 0);
			}
			else
			{
				box->color = GetColor(0, 0, 255);
			}

			box->Draw(wire);
		}
	}
}