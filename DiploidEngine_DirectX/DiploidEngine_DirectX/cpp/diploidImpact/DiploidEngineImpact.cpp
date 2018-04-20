#include "diploidImpact\DiploidEngineImpact.h"

void DiploidEngineImpact::PushCircle(DiploidCircle circle)
{
	circle_vector.push_back(circle);
}

void DiploidEngineImpact::PushPoint(DiploidPoint point)
{
	point_vector.push_back(point);
}

void DiploidEngineImpact::ImpactCirclePoint()//â~Ç∆ì_ÇÃìñÇΩÇËîªíËèàóù
{
	for (size_t circle = 0; circle != circle_vector.size(); ++circle)
	{
		circle_vector[circle].Update();
	}

	for (size_t point = 0; point != point_vector.size(); ++point)
	{
		point_vector[point].Update();
	}
}

void DiploidEngineImpact::Updata()
{
	ImpactCirclePoint();
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