#include "game_timer.h"

void GameTimer::Init()//‰Šú‰»
{
	play_type = 0;
	timer.Init();
	key.init();

	seconds = minute = hour = year = day = month = 0;
}

void GameTimer::Load()//“Ç‚Ýž‚Ý
{
	timer.Load("pack/GameObject/GameUI/time/back_wall.png");
	play_graphics = LoadGraph("pack/GameObject/GameUI/time/play.png");
	pause_graphics = LoadGraph("pack/GameObject/GameUI/time/pause.png");
}

void GameTimer::Draw(int pos_x, int pos_y, bool wire)//•`ŽÊ
{
	key.GetKeyFrame();
	if ((key.KeyCilick(KEY_INPUT_SEMICOLON) == true) || (key.KeyCilick(KEY_INPUT_ADD) == true))
	{
		play_type++;
	}

	if ((key.KeyCilick(KEY_INPUT_MINUS) == true) || (key.KeyCilick(KEY_INPUT_SUBTRACT) == true))
	{
		play_type--;
	}

	if (key.KeyCilick(KEY_INPUT_SPACE) == true)
	{
		play_type++;
	}

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

		count += 1;
	}
	else if (play_type == 2)
	{
		DrawGraph(pos_x + 8, pos_y, play_graphics, TRUE);
		DrawGraph(pos_x + 24, pos_y, play_graphics, TRUE);

		count += 6;
	}
	else if (play_type == 3)
	{
		DrawGraph(pos_x, pos_y, play_graphics, TRUE);
		DrawGraph(pos_x + 16, pos_y, play_graphics, TRUE);
		DrawGraph(pos_x + 32, pos_y, play_graphics, TRUE);

		count += 30;
	}
	else if (play_type > 3)
	{
		play_type = 0;
	}
	else if (play_type <= 0)
	{
		DrawGraph(pos_x + 16, pos_y, pause_graphics, TRUE);
		play_type = 0;
	}

	if (wire == true)
	{
		DrawFormatString(10, 20, GetColor(255, 255, 255), "second %d", seconds);
		DrawFormatString(10, 40, GetColor(255, 255, 255), "minute %d", minute);
		DrawFormatString(10, 60, GetColor(255, 255, 255), "hour %d", hour);
		DrawFormatString(10, 80, GetColor(255, 255, 255), "day %d", day);
		DrawFormatString(10, 100, GetColor(255, 255, 255), "month %d", month);
		DrawFormatString(10, 120, GetColor(255, 255, 255), "year %d", year);
		DrawFormatString(10, 140, GetColor(255, 255, 255), "count %d", count);
	}

	//•b‚És‚­‚½‚ß‚ÌƒJƒEƒ“ƒg
	if (count >= 60)
	{
		minute++;
		count = 0;
	}

	//•b
	if (seconds >= 60)
	{
		minute++;
		seconds = 0;
	}

	//•ª
	if (minute >= 60)
	{
		hour++;
		minute = 0;
	}

	//Žž
	if (hour >= 24)
	{
		day++;
		hour = 0;
	}

	//“ú(“ñ\“úŽüŠú)
	if (day >= 20)
	{
		month++;
		day = 0;
	}

	//ŒŽ(12ƒ–ŒŽŽüŠú)
	if (month >= 20)
	{
		year++;
		month = 0;
	}
}

void GameTimer::ColliderOff()
{
	timer.ColliderOff();
}

void GameTimer::ColliderOn()
{
	timer.ColliderOn();
}