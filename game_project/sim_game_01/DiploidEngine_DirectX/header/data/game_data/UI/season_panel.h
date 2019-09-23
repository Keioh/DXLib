/*---------------------------------------------------------*/
/*--------------季節パネルのすべてがここに-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"


//レイヤー番号はDIPLOID_LAYER_00
class SeasonPanel
{
private:
	DiploidObject season_panel;//季節パネル
	DiploidObject rainy_season;//雨季文字
	DiploidObject summer_season;//夏季文字
	DiploidObject spring_season;//春季文字
	DiploidObject winter_season;//冬季文字

	//日文字(1~24日まで)
	DiploidObject days1;
	DiploidObject days2;
	DiploidObject days3;
	DiploidObject days4;
	DiploidObject days5;
	DiploidObject days6;
	DiploidObject days7;
	DiploidObject days8;
	DiploidObject days9;
	DiploidObject days10;
	DiploidObject days11;
	DiploidObject days12;
	DiploidObject days13;
	DiploidObject days14;
	DiploidObject days15;
	DiploidObject days16;
	DiploidObject days17;
	DiploidObject days18;
	DiploidObject days19;
	DiploidObject days20;
	DiploidObject days21;
	DiploidObject days22;
	DiploidObject days23;
	DiploidObject days24;

	//月文字
	DiploidObject blue_month_1;
	DiploidObject blue_month_2;
	DiploidObject blue_month_3;
	DiploidObject red_month_1;
	DiploidObject red_month_2;
	DiploidObject red_month_3;
	DiploidObject white_month_1;
	DiploidObject white_month_2;
	DiploidObject white_month_3;
	DiploidObject pink_month_1;
	DiploidObject pink_month_2;
	DiploidObject pink_month_3;


	void _Days_Season_Count();//季節と日にちのフロー管理


	int days = 1;//日にちのカウント(１から始まる)
	int month = TANTOU_NO_TUKI;//日にちのカウント(１から始まる)
	int season = SPRING_SEASON;//季節のカウント(春季が初期値)

	int count;

public:
	SeasonPanel() {};
	~SeasonPanel() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

	//基本はDays系関数を使うこと
	int GetDays();//現在の日にちを得る。
	int GetMonth();//現在の月を得る。
	int GetSeason();//現在の季節を得る。

	void NextDays();//現在の日にちを一日進める。
	void NextMonth();//現在の月を一月進める。
	void NextSeason();//現在の季節を一季節進める。

	void SetDays(int set_day);//日にちを設定する。
	void SetMonth(int set_month);//月を設定する。
	void SetSeason(int set_season);//季節を設定する。

};