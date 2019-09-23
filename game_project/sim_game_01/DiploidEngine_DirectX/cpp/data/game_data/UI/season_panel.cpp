#include "data/game_data/UI/season_panel.h"

void SeasonPanel::Load()
{
	//‹Gßƒpƒlƒ‹‚Ì“Ç‚Ýž‚Ý
	season_panel.image.Load("texter/game/season/season_panel.png");

	//‰J‹Gƒpƒlƒ‹‚Ì“Ç‚Ýž‚Ý
	rainy_season.image.Load("texter/game/season/rainy_season.png");

	//‰Ä‹Gƒpƒlƒ‹‚Ì“Ç‚Ýž‚Ý
	summer_season.image.Load("texter/game/season/summer_season.png");

	//t‹Gƒpƒlƒ‹‚Ì“Ç‚Ýž‚Ý
	spring_season.image.Load("texter/game/season/spring_season.png");

	//“~‹Gƒpƒlƒ‹‚Ì“Ç‚Ýž‚Ý
	winter_season.image.Load("texter/game/season/winter_season.png");

	//“ú•¶Žš‚Ì“Ç‚Ýž‚Ý
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

	//ŒŽ•¶Žš‚Ì“Ç‚Ýž‚Ý
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
	//‹Gßƒpƒlƒ‹‚Ì‰Šú‰»
	season_panel.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));

	//‰J‹Gƒpƒlƒ‹‚Ì‰Šú‰»
	rainy_season.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));

	//‰Ä‹Gƒpƒlƒ‹‚Ì‰Šú‰»
	summer_season.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));

	//t‹Gƒpƒlƒ‹‚Ì‰Šú‰»
	spring_season.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));

	//“~‹Gƒpƒlƒ‹‚Ì‰Šú‰»
	winter_season.image.Init(VGet(position.x + (128 / 2), position.y + (128 / 2), 0));

	//“ú•¶Žš‚Ì‰Šú‰»
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

	//ŒŽ•¶Žš‚Ì‰Šú‰»
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
	_Days_Season_Count();//ƒtƒ[ˆ—

	//‹Gßƒpƒlƒ‹‚ÌƒAƒbƒvƒf[ƒg
	season_panel.image.Updata();

	//t‹Gƒpƒlƒ‹‚ÌƒAƒbƒvƒf[ƒg
	if (season == SPRING_SEASON)
	{
		spring_season.image.Updata();
	}

	//‰J‹Gƒpƒlƒ‹‚ÌƒAƒbƒvƒf[ƒg
	if (season == RAINY_SEASON)
	{
		rainy_season.image.Updata();
	}

	//‰Ä‹Gƒpƒlƒ‹‚ÌƒAƒbƒvƒf[ƒg
	if (season == SUMMER_SEASON)
	{
		summer_season.image.Updata();
	}

	//“~‹Gƒpƒlƒ‹‚ÌƒAƒbƒvƒf[ƒg
	if (season == WINTER_SEASON)
	{
		winter_season.image.Updata();
	}

	//“ú‚É‚¿‚ÌƒAƒbƒvƒf[ƒg
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

	//ŒŽ‚ÌƒAƒbƒvƒf[ƒg
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
	//‹Gßƒpƒlƒ‹‚Ì•`ŽÊ
	season_panel.image.Draw();

	//t‹G‚Ì•`ŽÊ
	if (season == SPRING_SEASON)
	{
		spring_season.image.Draw();
	}

	//‰J‹G‚Ì•`ŽÊ
	if (season == RAINY_SEASON)
	{
		rainy_season.image.Draw();
	}

	//‰Ä‹G‚Ì•`ŽÊ
	if (season == SUMMER_SEASON)
	{
		summer_season.image.Draw();
	}

	//“~‹G‚Ì•`ŽÊ
	if (season == WINTER_SEASON)
	{
		winter_season.image.Draw();
	}

	//“ú‚É‚¿‚Ì•`ŽÊ
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

	//ŒŽ‚Ì•`ŽÊ
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
	//“ú‚É‚¿
	if (days > 24)
	{
		month += NEXT_MONTH;
		days = NEXT_DAY;
	}

	if (month >= TANTOU_NO_TUKI)//t
	{
		season = SPRING_SEASON;

		if (month >= TANSEI_NO_TUKI)//‰J
		{
			season = RAINY_SEASON;

			if (month >= TANSEKI_NO_TUKI)//‰Ä
			{
				season = SUMMER_SEASON;

				if (month >= TANHAKU_NO_TUKI)//“~
				{
					season = WINTER_SEASON;
				}
			}
		}
	}

	//ƒtƒ[ˆ—
	if (month > 12)
	{
		month = TANTOU_NO_TUKI;
	}

	if (season > 4)
	{
		season = SPRING_SEASON;
	}
}