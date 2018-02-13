#include "Loading.h"

Loading::Loading()
{
	Loading::inti();
}

void Loading::inti()
{
	timer = 0;
}

void Loading::LoadGraphics()
{
	loading_graphics = LoadGraph("pack/UI/Loading/loading.png");//ロードディング画像
	loading_point_graphics = LoadGraph("pack/UI/Loading/point.png");//点画像
}

void Loading::DrawLoading(int x, int y)
{
	if (timer >= 0)
	{
		timer++;
		if (timer >= 30)
		{
			DrawGraphF(x + 150, y + 30, loading_point_graphics, TRUE);

			if (timer >= 60)
			{
				DrawGraphF(x + 175, y + 30, loading_point_graphics, TRUE);
				if (timer >= 90)
				{
					DrawGraphF(x + 200, y + 30, loading_point_graphics, TRUE);
					if (timer >= 120)
					{
						timer = 0;
					}
				}
			}
		}
	}

	DrawGraphF(x, y, loading_graphics, TRUE);
}