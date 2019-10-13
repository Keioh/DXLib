/*---------------------------------------------------------*/
/*--------------Œv‚Ì‚·‚×‚Ä‚ª‚±‚±‚É-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "data/game_data/UI/status_bar.h"
#include "data/game_data/UI/command_ui.h"

class Clock
{
private:
	DiploidObject test_clock_back;
	DiploidObject test_clock_hour_hand;
	DiploidObject test_clock_minute_hand;
	DiploidObject test_clock_second_hand;
	int timer = 0;
	int day = 0;
	int hour = 0;
	int minute = 0;
	int second = 0;

	bool second_flag = false;
	bool minute_flag = false;
	bool hour_flag = false;
	bool day_flag = false;

public:

	void Init(VECTOR positoin = { 0,0,0 });
	void Load();
	void Update();
	void Draw(bool draw = true);

	//ŠÔ‚ªi‚ñ‚¾uŠÔ‚¾‚¯true‚ğ•Ô‚·B
	bool isSecondFlag();
	bool isHourFlag();
	bool isMinuteFlag();
	bool isDayFlag();

};