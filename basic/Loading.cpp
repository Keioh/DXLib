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
			DrawGraph(x + 150, y + 30, loading_point_graphics, TRUE);

			if (timer >= 60)
			{
				DrawGraph(x + 175, y + 30, loading_point_graphics, TRUE);
				if (timer >= 90)
				{
					DrawGraph(x + 200, y + 30, loading_point_graphics, TRUE);
					if (timer >= 120)
					{
						timer = 0;
					}
				}
			}
		}
	}

	DrawGraph(x, y, loading_graphics, TRUE);
}