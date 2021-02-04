#include "ver2.0/Objects/ContinuousTriangle.h"

void ContinuousTriangle::Init(VECTOR pos, float lenght, int size_x, int size_y)
{
	triangle_size_x = size_x;
	triangle_size_y = size_y;

	triangle_lenght = lenght;
	triangle_height = math.EquilateralTriangleHeight(triangle_lenght);

	/*
	if (!triangle_vector.empty())
	{
		for (int count_y = 0; count_y != triangle_size_y; count_y++)
		{
			for (int count_x = 0; count_x != triangle_size_x; count_x++)
			{
				//test[count_y].clear();
			}

			//test.clear();
		}
	}
	*/


	if (triangle_vector.empty() == true)
	{
		for (int count_y = 0; count_y != triangle_size_y; count_y++)
		{
			triangle_vector.emplace_back();

			for (int count_x = 0; count_x != triangle_size_x; count_x++)
			{
				if ((count_y % 2) == 0)//‹ô”‚È‚ç•\Ž¦‚ð‚¸‚ç‚³‚È‚¢
				{
					triangle_data.point_one = VAdd(VGet(0 + (triangle_lenght * count_x), 0 + (triangle_height * count_y), 0), pos);
					triangle_data.point_two = VAdd(VGet(-(triangle_lenght / 2) + (triangle_lenght * count_x), triangle_height + (triangle_height * count_y), 0), pos);
					triangle_data.point_three = VAdd(VGet((triangle_lenght / 2) + (triangle_lenght * count_x), triangle_height + (triangle_height * count_y), 0), pos);

					triangle.Init(triangle_data, GetColor(100, 100, 100));
					triangle.SetFill(true);

					triangle_vector[count_y].push_back(triangle);


					triangle_data.point_one = VAdd(VGet(0 + (triangle_lenght * count_x), 0 + (triangle_height * count_y), 0), pos);
					triangle_data.point_two = VAdd(VGet(triangle_lenght + (triangle_lenght * count_x), 0 + (triangle_height * count_y), 0), pos);
					triangle_data.point_three = VAdd(VGet((triangle_lenght / 2) + (triangle_lenght * count_x), triangle_height + (triangle_height * count_y), 0), pos);

					triangle.Init(triangle_data, GetColor(0, 0, 0));
					triangle.SetFill(true);

					triangle_vector[count_y].push_back(triangle);
				}
				else//Šï”‚È‚ç•\Ž¦‚ð‚¸‚ç‚·
				{
					triangle_data.point_one = VAdd(VGet(0 + (triangle_lenght * count_x) - (triangle_lenght / 2), 0 + (triangle_height * count_y), 0), pos);
					triangle_data.point_two = VAdd(VGet(-(triangle_lenght / 2) + (triangle_lenght * count_x) - (triangle_lenght / 2), triangle_height + (triangle_height * count_y), 0), pos);
					triangle_data.point_three = VAdd(VGet((triangle_lenght / 2) + (triangle_lenght * count_x) - (triangle_lenght / 2), triangle_height + (triangle_height * count_y), 0), pos);

					triangle.Init(triangle_data, GetColor(100, 100, 100));
					triangle.SetFill(true);

					triangle_vector[count_y].push_back(triangle);


					triangle_data.point_one = VAdd(VGet(0 + (triangle_lenght * count_x) - (triangle_lenght / 2), 0 + (triangle_height * count_y), 0), pos);
					triangle_data.point_two = VAdd(VGet(triangle_lenght + (triangle_lenght * count_x) - (triangle_lenght / 2), 0 + (triangle_height * count_y), 0), pos);
					triangle_data.point_three = VAdd(VGet((triangle_lenght / 2) + (triangle_lenght * count_x) - (triangle_lenght / 2), triangle_height + (triangle_height * count_y), 0), pos);

					triangle.Init(triangle_data, GetColor(0, 0, 0));
					triangle.SetFill(true);

					triangle_vector[count_y].push_back(triangle);
				}
			}
		}
	}
}

void ContinuousTriangle::Updata(DiploidEngineInput& input)
{
	if (!triangle_vector.empty())
	{
		for (int count_y = 0; count_y != triangle_size_y; count_y++)
		{
			for (int count_x = 0; count_x != triangle_size_x; count_x++)
			{
				pos.x = input.GetMousePosition().x - triangle_vector[count_y][count_x].GetCenterPosition().x;
				pos.y = input.GetMousePosition().y - triangle_vector[count_y][count_x].GetCenterPosition().y;
				pos.z = sqrtf((powf(pos.x, 2) + powf(pos.y, 2))) * (2 + sin_anime);

				color = abs(pos.z);

				sin_anime = sin(sin_add);

				if (color > 255) color = 255;
				if (color < 255 * max_color_scale) color = 255 * max_color_scale;

				triangle_vector[count_y][count_x].SetColor(GetColor(color, color, color));
			}


		}

		sin_add += 0.01f;

		if ((2 * DX_PI) < sin_add)
		{
			sin_add = 0;
		}
	}
}

void ContinuousTriangle::Draw(bool draw, bool debug)
{

	if (!triangle_vector.empty())
	{
		for (int count_y = 0; count_y != triangle_size_y; count_y++)
		{
			for (int count_x = 0; count_x != triangle_size_x; count_x++)
			{
				triangle_vector[count_y][count_x].Draw(draw);
			}
		}
	}
	
	if (debug == true)
	{
		DrawFormatString(0, 200, GetColor(0, 0, 0), "size_x = %d", triangle_vector[0].size());
		DrawFormatString(0, 220, GetColor(0, 0, 0), "size_y = %d", triangle_vector.size());
		DrawFormatString(0, 240, GetColor(0, 0, 0), "size_xy = %d", triangle_vector.size() * triangle_vector[0].size());
	}
}