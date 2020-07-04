#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "data/number.h"

class DayUI
{
private:
	DiploidImageV2 image;
	Number1000 number;

	int day = 0;
	bool active_flag = true;
	int active_time = 0;

	int alpha = 0;//透過値
	int set_active_time = 60;//表示時間
	int speed = 5;//透過速度

public:
	void Load();
	void Init(VECTOR pos, float scale = 1.0f);
	void Update(int days = 0);
	void Draw(bool draw = true);

	void SetAcitiveFlag(bool new_active_flag);
	void SetSpeed(int new_speed);
	void SetActiveTime(int new_time);//表示時間を設定します。

	int GetDay();
	bool GetActiveFlag();
	int GetSpeed();
};