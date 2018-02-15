#include "game_timer.h"

void GameTimer::Init()
{
	play_type = 0;
	timer.Init();
}

void GameTimer::Load()
{
	timer.Load("pack/GameObject/GameUI/time/back_wall.png");
	play_graphics = LoadGraph("pack/GameObject/GameUI/time/play.png");
	pause_graphics = LoadGraph("pack/GameObject/GameUI/time/pause.png");
}

void GameTimer::Draw(int pos_x, int pos_y, bool wire)
{
	if (timer.BoxUI_Button(pos_x, pos_y, 1, wire) == true)
	{
		play_type++;
	}

	if (play_type == 0)//ˆêŽž’âŽ~
	{
		DrawGraph(pos_x + 16, pos_y, pause_graphics, TRUE);
	}
	else if (play_type == 1)
	{
		DrawGraph(pos_x + 16, pos_y, play_graphics, TRUE);

	}
	else if (play_type == 2)
	{
		DrawGraph(pos_x + 8, pos_y, play_graphics, TRUE);
		DrawGraph(pos_x + 24, pos_y, play_graphics, TRUE);

	}
	else if (play_type == 3)
	{
		DrawGraph(pos_x, pos_y, play_graphics, TRUE);
		DrawGraph(pos_x + 16, pos_y, play_graphics, TRUE);
		DrawGraph(pos_x + 32, pos_y, play_graphics, TRUE);
	}
	else if (play_type > 3)
	{
		play_type = 0;
	}
}