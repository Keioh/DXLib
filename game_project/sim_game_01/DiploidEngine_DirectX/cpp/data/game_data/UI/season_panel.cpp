#include "data/game_data/UI/season_panel.h"

void SeasonPanel::Load()
{
	//季節パネルの読み込み
	season_panel.image.Load("texter/game/season/season_panel.png");

	//雨季パネルの読み込み
	rainy_season.image.Load("texter/game/season/rainy_season.png");

	//夏季パネルの読み込み
	summer_season.image.Load("texter/game/season/summer_season.png");

	//春季パネルの読み込み
	spring_season.image.Load("texter/game/season/spring_season.png");

	//冬季パネルの読み込み
	winter_season.image.Load("texter/game/season/winter_season.png");

	//日文字の読み込み
	{
		days1.image.Load("texter/game/season/day/day1.png");
		days2.image.Load("texter/game/season/day/day2.png");
		days3.image.Load("texter/game/season/day/day3.png");
		days4.image.Load("texter/game/season/day/day4.png");
		days5.image.Load("texter/game/season/day/day5.png");
		days6.image.Load("texter/game/season/day/day6.png");
		days7.image.Load("texter/game/season/day/day7.png");
		days8.image.Load("texter/game/season/day/day8.png");
		days9.image.Load("texter/game/season/day/day9.png");
		days10.image.Load("texter/game/season/day/day10.png");
		days11.image.Load("texter/game/season/day/day11.png");
		days12.image.Load("texter/game/season/day/day12.png");
		days13.image.Load("texter/game/season/day/day13.png");
		days14.image.Load("texter/game/season/day/day14.png");
		days15.image.Load("texter/game/season/day/day15.png");
		days16.image.Load("texter/game/season/day/day16.png");
		days17.image.Load("texter/game/season/day/day17.png");
		days18.image.Load("texter/game/season/day/day18.png");
		days19.image.Load("texter/game/season/day/day19.png");
		days20.image.Load("texter/game/season/day/day20.png");
		days21.image.Load("texter/game/season/day/day21.png");
		days22.image.Load("texter/game/season/day/day22.png");
		days23.image.Load("texter/game/season/day/day23.png");
		days24.image.Load("texter/game/season/day/day24.png");
	}

	//月文字の読み込み
	{
		blue_month_1.image.Load("texter/game/season/month/blue_month_1.png");
		blue_month_2.image.Load("texter/game/season/month/blue_month_2.png");
		blue_month_3.image.Load("texter/game/season/month/blue_month_3.png");
		red_month_1.image.Load("texter/game/season/month/red_month_1.png");
		red_month_2.image.Load("texter/game/season/month/red_month_2.png");
		red_month_3.image.Load("texter/game/season/month/red_month_3.png");
		white_month_1.image.Load("texter/game/season/month/white_month_1.png");
		white_month_2.image.Load("texter/game/season/month/white_month_2.png");
		white_month_3.image.Load("texter/game/season/month/white_month_3.png");
		pink_month_1.image.Load("texter/game/season/month/pink_month_1.png");
		pink_month_2.image.Load("texter/game/season/month/pink_month_2.png");
		pink_month_3.image.Load("texter/game/season/month/pink_month_3.png");
	}
}

void SeasonPanel::Init(VECTOR position)
{
	//季節パネルの初期化
	season_panel.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));

	//雨季パネルの初期化
	rainy_season.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));

	//夏季パネルの初期化
	summer_season.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));

	//春季パネルの初期化
	spring_season.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));

	//冬季パネルの初期化
	winter_season.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));

	//日文字の初期化
	{
		days1.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days2.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days3.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days4.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days5.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days6.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days7.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days8.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days9.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days10.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days11.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days12.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days13.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days14.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days15.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days16.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days17.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days18.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days19.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days20.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days21.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days22.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days23.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		days24.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
	}

	//月文字の初期化
	{
		blue_month_1.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		blue_month_2.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		blue_month_3.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		red_month_1.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		red_month_2.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		red_month_3.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		white_month_1.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		white_month_2.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		white_month_3.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		pink_month_1.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		pink_month_2.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
		pink_month_3.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));
	}
}

void SeasonPanel::Push(DiploidEngineImpact& impact)
{

}

void SeasonPanel::Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	_Days_Season_Count();//フロー処理

	//季節パネルのアップデート
	season_panel.image.Updata();

	//春季パネルのアップデート
	if (season == SPRING_SEASON)
	{
		spring_season.image.Updata();
	}

	//雨季パネルのアップデート
	if (season == RAINY_SEASON)
	{
		rainy_season.image.Updata();
	}

	//夏季パネルのアップデート
	if (season == SUMMER_SEASON)
	{
		summer_season.image.Updata();
	}

	//冬季パネルのアップデート
	if (season == WINTER_SEASON)
	{
		winter_season.image.Updata();
	}

	//日にちのアップデート
	switch (days)
	{
	case 1: days1.image.Updata(); break;
	case 2: days2.image.Updata(); break;
	case 3: days3.image.Updata(); break;
	case 4: days4.image.Updata(); break;
	case 5: days5.image.Updata(); break;
	case 6: days6.image.Updata(); break;
	case 7: days7.image.Updata(); break;
	case 8: days8.image.Updata(); break;
	case 9: days9.image.Updata(); break;
	case 10: days10.image.Updata(); break;
	case 11: days11.image.Updata(); break;
	case 12: days12.image.Updata(); break;
	case 13: days13.image.Updata(); break;
	case 14: days14.image.Updata(); break;
	case 15: days15.image.Updata(); break;
	case 16: days16.image.Updata(); break;
	case 17: days17.image.Updata(); break;
	case 18: days18.image.Updata(); break;
	case 19: days19.image.Updata(); break;
	case 20: days20.image.Updata(); break;
	case 21: days21.image.Updata(); break;
	case 22: days22.image.Updata(); break;
	case 23: days23.image.Updata(); break;
	case 24: days24.image.Updata(); break;
	default: break;
	}

	//月のアップデート
	switch (month)
	{
	case 1: pink_month_1.image.Updata(); break;
	case 2: pink_month_2.image.Updata(); break;
	case 3: pink_month_3.image.Updata(); break;
	case 4: blue_month_1.image.Updata(); break;
	case 5: blue_month_2.image.Updata(); break;
	case 6: blue_month_3.image.Updata(); break;
	case 7: red_month_1.image.Updata(); break;
	case 8: red_month_2.image.Updata(); break;
	case 9: red_month_3.image.Updata(); break;
	case 10: white_month_1.image.Updata(); break;
	case 11: white_month_2.image.Updata(); break;
	case 12: white_month_3.image.Updata(); break;
	default: break;
	}
}

void SeasonPanel::Draw(bool draw)
{
	//季節パネルの描写
	season_panel.image.Draw();

	//春季の描写
	if (season == SPRING_SEASON)
	{
		spring_season.image.Draw();
	}

	//雨季の描写
	if (season == RAINY_SEASON)
	{
		rainy_season.image.Draw();
	}

	//夏季の描写
	if (season == SUMMER_SEASON)
	{
		summer_season.image.Draw();
	}

	//冬季の描写
	if (season == WINTER_SEASON)
	{
		winter_season.image.Draw();
	}

	//日にちの描写
	switch (days)
	{
	case 1: days1.image.Draw(); break;
	case 2: days2.image.Draw(); break;
	case 3: days3.image.Draw(); break;
	case 4: days4.image.Draw(); break;
	case 5: days5.image.Draw(); break;
	case 6: days6.image.Draw(); break;
	case 7: days7.image.Draw(); break;
	case 8: days8.image.Draw(); break;
	case 9: days9.image.Draw(); break;
	case 10: days10.image.Draw(); break;
	case 11: days11.image.Draw(); break;
	case 12: days12.image.Draw(); break;
	case 13: days13.image.Draw(); break;
	case 14: days14.image.Draw(); break;
	case 15: days15.image.Draw(); break;
	case 16: days16.image.Draw(); break;
	case 17: days17.image.Draw(); break;
	case 18: days18.image.Draw(); break;
	case 19: days19.image.Draw(); break;
	case 20: days20.image.Draw(); break;
	case 21: days21.image.Draw(); break;
	case 22: days22.image.Draw(); break;
	case 23: days23.image.Draw(); break;
	case 24: days24.image.Draw(); break;
	default: break;
	}

	//月の描写
	switch (month)
	{
	case 1: pink_month_1.image.Draw(); break;
	case 2: pink_month_2.image.Draw(); break;
	case 3: pink_month_3.image.Draw(); break;
	case 4: blue_month_1.image.Draw(); break;
	case 5: blue_month_2.image.Draw(); break;
	case 6: blue_month_3.image.Draw(); break;
	case 7: red_month_1.image.Draw(); break;
	case 8: red_month_2.image.Draw(); break;
	case 9: red_month_3.image.Draw(); break;
	case 10: white_month_1.image.Draw(); break;
	case 11: white_month_2.image.Draw(); break;
	case 12: white_month_3.image.Draw(); break;
	default: break;
	}
}


int SeasonPanel::GetDays()
{
	return days;
}

int SeasonPanel::GetMonth()
{
	return month;
}

int SeasonPanel::GetSeason()
{
	return season;
}


void SeasonPanel::NextDays()
{
	days += 1;
}

void SeasonPanel::NextMonth()
{
	month += 1;
}

void SeasonPanel::NextSeason()
{
	season += NEXT_SEASON;
}


void SeasonPanel::SetDays(int set_day)
{
	days = set_day;
}

void SeasonPanel::SetMonth(int set_month)
{
	month = set_month;
}

void SeasonPanel::SetSeason(int set_season)
{
	season = set_season;
}



void SeasonPanel::_Days_Season_Count()
{
	//日にち
	if (days > 24)
	{
		month += NEXT_MONTH;
		days = NEXT_DAY;
	}

	if (month >= TANTOU_NO_TUKI)//春
	{
		season = SPRING_SEASON;

		if (month >= TANSEI_NO_TUKI)//雨
		{
			season = RAINY_SEASON;

			if (month >= TANSEKI_NO_TUKI)//夏
			{
				season = SUMMER_SEASON;

				if (month >= TANHAKU_NO_TUKI)//冬
				{
					season = WINTER_SEASON;
				}
			}
		}
	}

	//フロー処理
	if (month > 12)
	{
		month = TANTOU_NO_TUKI;
	}

	if (season > 4)
	{
		season = SPRING_SEASON;
	}
}