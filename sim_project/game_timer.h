#pragma once
#include "button_ui.h"
#include "Input.h"

class GameTimer
{
private:
	ButtonUI timer;
	Input key;
	int play_graphics, pause_graphics;

public:
	int play_type;//0が一時停止
	int seconds, minute, hour, day, month, year;//時間を保存する変数

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, bool wire);

	void ColliderOff();
	void ColliderOn();
};