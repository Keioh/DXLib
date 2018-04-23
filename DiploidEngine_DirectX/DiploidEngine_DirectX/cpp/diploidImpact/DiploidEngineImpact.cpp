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

void DiploidEngineImpact::ImpactCirclePoint()//円と点の当たり判定処理
{
	if (!point_vector.empty() && !circle_vector.empty())
	{
		for (size_t circle = 0; circle != circle_vector.size(); ++circle)
		{
			for (size_t point = 0; point != point_vector.size(); ++point)
			{
				float x = 0, y = 0;
				x = (circle_vector[circle].position.x - point_vector[point].position.x);
				y = (circle_vector[circle].position.y - point_vector[point].position.y);

				if (std::powf(x, 2) + std::powf(y, 2) <= std::powf(circle_vector[circle].size.z, 2))
				{
					circle_vector[circle].color = GetColor(255, 0, 0);
					point_vector[point].color = GetColor(255, 0, 0);

					circle_vector[circle].impacted = true;
					point_vector[point].impacted = true;
				}
				else
				{
					circle_vector[circle].color = GetColor(0, 0, 255);
					point_vector[point].color = GetColor(0, 0, 255);

					circle_vector[circle].impacted = false;
					point_vector[point].impacted = false;
				}
			}
		}
	}
}

void DiploidEngineImpact::AnimeUpdata()
{

}

void DiploidEngineImpact::ImpactUpdata()
{
	ImpactCirclePoint();//円と点の衝突計算

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
}

void DiploidEngineImpact::Draw(bool wire)
{
	if (!circle_vector.empty())
	{
		for (size_t circle = 0; circle != circle_vector.size(); ++circle)
		{
			circle_vector[circle].Draw(wire);
		}
	}

	if (!point_vector.empty())
	{
		for (size_t point = 0; point != point_vector.size(); ++point)
		{
			point_vector[point].Draw(wire);
		}
	}
}