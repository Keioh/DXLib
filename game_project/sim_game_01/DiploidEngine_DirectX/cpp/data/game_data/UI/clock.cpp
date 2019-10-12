#include "data/game_data/UI/clock.h"

void Clock::Init(VECTOR positoin)
{
	//時計
	test_clock_back.image.Init(VGet(1280 - 128 / 2, 0 + 320 / 2, 0));
	test_clock_hour_hand.image.Init(VGet(1280 - 128 / 2, 0 + 320 / 2, 0));
	test_clock_minute_hand.image.Init(VGet(1280 - 128 / 2, 0 + 320 / 2, 0));
	test_clock_second_hand.image.Init(VGet(1280 - 128 / 2, 0 + 320 / 2, 0));

}

void Clock::Load()
{
	//時計
	test_clock_back.image.Load("texter/game/clock/back.png");
	test_clock_hour_hand.image.Load("texter/game/clock/hour_hand.png");
	test_clock_minute_hand.image.Load("texter/game/clock/minute_hand.png");
	test_clock_second_hand.image.Load("texter/game/clock/second_hand.png");


}

void Clock::Update()
{
	//時計
	timer++;

	if (timer > 59)
	{
		second += 1;

		second_flag = true;

		test_clock_second_hand.image.move_speed.x = 2;

		timer = 0;
	}
	else
	{
		second_flag = false;
	}

	if (second > 29)
	{
		minute += 1;

		minute_flag = true;

		test_clock_minute_hand.image.move_speed.y = 18;

		test_clock_second_hand.image.move_speed.x = -(2 * 29);

		second = 0;
	}
	else
	{
		minute_flag = false;
	}


	if (minute > 11)
	{
		hour += 1;

		hour_flag = true;

		test_clock_hour_hand.image.move_speed.y = 24;

		test_clock_minute_hand.image.move_speed.y = -(18 * 11);

		minute = 0;
	}
	else
	{
		hour_flag = false;
	}

	if (hour > 7)
	{
		test_clock_hour_hand.image.move_speed.y = -(24 * 7);

		hour = 0;
	}


	test_clock_second_hand.image.Updata();
	test_clock_minute_hand.image.Updata();
	test_clock_hour_hand.image.Updata();
}

void Clock::Draw(bool draw)
{
	//時計
	test_clock_back.image.Draw();
	test_clock_hour_hand.image.Draw();
	test_clock_minute_hand.image.Draw();
	test_clock_second_hand.image.Draw();

}


bool Clock::isSecondFlag()
{
	return second_flag;
}

bool Clock::isHourFlag()
{
	return hour_flag;
}

bool Clock::isMinuteFlag()
{
	return minute_flag;
}