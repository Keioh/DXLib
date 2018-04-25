#include "diploidImpact\DiploidEngineImpact.h"

void DiploidEngineImpact::PushCircle(DiploidCircle circle)
{
	circle_vector.push_back(circle);
}

void DiploidEngineImpact::PushPoint(DiploidPoint point)
{
	point_vector.push_back(point);
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

void DiploidEngineImpact::DestoryCircle()
{
	if (!circle_vector.empty())
	{
		for (size_t circle = 0; circle != circle_vector.size(); ++circle)
		{
			if (circle_vector[circle].impacted == true && circle_vector[circle].destory == true)
			{
				circle_vector.erase(circle_vector.begin() + circle);
			}
		}
	}
}

void DiploidEngineImpact::ImpactCirclePoint()
{
	if (!point_vector.empty() && !circle_vector.empty())
	{
		for (size_t point = 0; point != point_vector.size(); ++point)
		{
			for (size_t circle = 0; circle != circle_vector.size(); ++circle)
			{
				float x = 0, y = 0;
				x = (circle_vector[circle].position.x - point_vector[point].position.x);
				y = (circle_vector[circle].position.y - point_vector[point].position.y);

				if (std::pow(x, 2) + std::pow(y, 2) <= std::pow(circle_vector[circle].size.z, 2))
				{
					circle_vector[circle].impacted = true;
					point_vector[point].impacted = true;
				}
				else
				{
					circle_vector[circle].impacted = false;
					point_vector[point].impacted = false;
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
				x = (circle_vector[circle_one].position.x - circle_vector[circle_two].position.x);
				y = (circle_vector[circle_one].position.y - circle_vector[circle_two].position.y);
				r = (circle_vector[circle_one].size.z + circle_vector[circle_two].size.z);

				if ((std::pow(x, 2) + std::pow(y, 2)) <= std::pow(r, 2))
				{
					circle_vector[circle_one].impacted = true;
					circle_vector[circle_two].impacted = true;
				}
				else
				{
					circle_vector[circle_one].impacted = false;
					circle_vector[circle_two].impacted = false;
				}
			}
		}
	}
}

void DiploidEngineImpact::Updata()
{
	int updata_flag = 0;

	//円の更新処理
	if (!circle_vector.empty())
	{
		for (size_t circle = 0; circle != circle_vector.size(); ++circle)
		{
			circle_vector[circle].Update();//アニメアプデ
		}
	}

	//点の更新処理
	if (!point_vector.empty())
	{
		for (size_t point = 0; point != point_vector.size(); ++point)
		{
			point_vector[point].Update();//アニメアプデ
		}
	}

	ImpactCirclePoint();//円と点の衝突計算
	ImpactCircleCircle();//円と円の衝突計算
}

void DiploidEngineImpact::Draw(bool wire)
{
	if (!circle_vector.empty())
	{
		for (size_t circle = 0; circle != circle_vector.size(); ++circle)
		{
			//円がヒットしていたら
			if (circle_vector[circle].impacted == true)
			{
				circle_vector[circle].color = GetColor(255, 0, 0);
			}
			else
			{
				circle_vector[circle].color = GetColor(0, 0, 255);
			}	
			
			circle_vector[circle].Draw(wire);
		}
	}

	if (!point_vector.empty())
	{
		for (size_t point = 0; point != point_vector.size(); ++point)
		{
			//点がヒットしていたら
			if (point_vector[point].impacted == true)
			{
				point_vector[point].color = GetColor(255, 0, 0);
			}
			else
			{
				point_vector[point].color = GetColor(0, 0, 255);
			}	
			
			point_vector[point].Draw(wire);
		}
	}
}