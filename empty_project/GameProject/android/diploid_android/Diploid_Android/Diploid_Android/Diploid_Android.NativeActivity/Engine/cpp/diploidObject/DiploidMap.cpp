#include "diploidObject\DiploidMap.h"

void DiploidMap::SetMapChipSize(int size)
{
	MAP_SIZE = size;
}

void DiploidMap::SetPosition(float x, float y)
{
	position_x = x;
	position_y = y;
}

int DiploidMap::Load(const char* path, int data_size_x, int data_size_y)
{
	SetUseASyncLoadFlag(FALSE);
	handl = LoadSoftImage(path);
	SetUseASyncLoadFlag(TRUE);

	Width = data_size_x;
	Height = data_size_y;

	return handl;
}

void DiploidMap::Create()
{
	for (int X = 0; X < Width; ++X)
	{
		for (int Y = 0; Y < Height; ++Y)
		{
			int r, g, b, a;

			if (GetPixelSoftImage(handl, X, Y, &r, &g, &b, &a) == 0)
			{
				if (a > 0)
				{
					MAP.push_back({ (float)X + position_x, (float)Y + position_y, r, g, b, a , MAP_SIZE });
				}
			}
		}
	}
}

void DiploidMap::Updata(float move_x, float move_y)
{
	for (auto count = MAP.begin(); count != MAP.end(); ++count)
	{
		count->x += move_x;
		count->y += move_y;
	}
}

void DiploidMap::Draw(bool wire)
{
	if (wire == true)
	{
		for (auto count = MAP.begin(); count != MAP.end(); ++count)
		{
			if ((count->red == 0) && (count->green == 0) && (count->blue == 0) && (count->alph == 255))
			{
				DrawBoxAA(count->x * MAP_SIZE, count->y * MAP_SIZE, count->x * MAP_SIZE + MAP_SIZE, count->y * MAP_SIZE + MAP_SIZE, GetColor(0, 0, 0), TRUE);
			}
		}
	}
}