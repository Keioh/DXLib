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

void DiploidEngineImpact::CircleAnime(float anime_position_x, float anime_position_y, VECTOR size)
{
	for (size_t circle = 0; circle != circle_vector.size(); ++circle)
	{
		circle_vector[circle].move_speed.x = anime_position_x;
		circle_vector[circle].move_speed.y = anime_position_y;
		circle_vector[circle].move_size = size.z;
	}
}

void DiploidEngineImpact::PointAnime(float anime_position_x, float anime_position_y)
{
	for (size_t point = 0; point != point_vector.size(); ++point)
	{
		point_vector[point].move_speed.x = anime_position_x;
		point_vector[point].move_speed.y = anime_position_y;
	}
}

void DiploidEngineImpact::AnimeUpdata(float anime_position_x, float anime_position_y, VECTOR size)
{
	CircleAnime(anime_position_x, anime_position_y, size);
	PointAnime(anime_position_x, anime_position_y);
}

void DiploidEngineImpact::ImpactUpdata()
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