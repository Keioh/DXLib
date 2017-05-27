#include "DxLib.h"
#include "System.h"
#include "title.h"

TITLE::Title()
{
	mouse_x = 0;
	mouse_y = 0;
}

int title_graph[5];
void TITLE::Title_Graph_Load()
{
	title_graph[0] = LoadGraph("res/graph/black.png");
	title_graph[1] = LoadGraph("res/graph/title.png");

	title_graph[2] = LoadGraph("res/graph/title/tile_s.png");
	title_graph[3] = LoadGraph("res/graph/title/tile_black.png");
	title_graph[4] = LoadGraph("res/graph/title/tile_s_on.png");

}

void TITLE::Title_Screen()
{
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		static int anime;
		static int color;
		static int flag = -1;;

		GetMousePoint(&mouse_x, &mouse_y);

		DrawGraph(0, 0, title_graph[1], TRUE);

		DrawGraph(200, 200, title_graph[2], TRUE);

		if ((200 < mouse_x && 200 < mouse_y) && (300 > mouse_x && 300 > mouse_y))
		{
			DrawGraph(200, 200, title_graph[4], TRUE);

			color = 20;
			if (Mouse_Cilck(MOUSE_INPUT_LEFT, 0) != 0)
			{
				anime = 0;

				flag *= -1;
			}
		}
		else
		{
			color = 0;
		}
		//DrawBox(200, 200, 300, 300, GetColor(100 + color, 100 + color, 100 + color), TRUE);


		if (flag == 1)
		{
			anime += 15;

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, anime);
			DrawGraph(200, 200, title_graph[3], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, anime);

		}

		App_End(KEY_INPUT_ESCAPE);
	}
}