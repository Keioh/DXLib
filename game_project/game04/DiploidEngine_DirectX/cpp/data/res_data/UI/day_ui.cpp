#include "data/res_data/UI/day_ui.h"


void DayUI::Load()
{
	image.Load("texter/res/day/back.png");
	number.Load();
}

void DayUI::Init(VECTOR pos, float scale)
{
	image.Init(pos, true);
	image.SetScale(scale, scale);

	number.Init(VGet(pos.x + (94 * scale),pos.y - 0,pos.z), scale);
}

void DayUI::Update(int days)
{	
	day = days;

	number.Update(day);

	if (active_flag == true)
	{
		alpha += speed;

		if (alpha > 255)
		{
			alpha = 255;
			
			if (active_time < set_active_time)
			{
				++active_time;
			}
			else
			{
				active_flag = false;
				active_time = 0;
			}
		}
	}
	else
	{
		alpha -= speed;
		if (alpha < 0) alpha = 0;
	}

}

void DayUI::Draw(bool draw)
{
	if (alpha > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		image.Draw(draw);
		number.Draw(draw);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}


void DayUI::SetAcitiveFlag(bool new_active_flag)
{
	active_flag = new_active_flag;
}

void DayUI::SetSpeed(int new_speed)
{
	alpha = new_speed;
}

void DayUI::SetActiveTime(int new_time)
{
	set_active_time = new_time;
}


int DayUI::GetDay()
{
	return day;
}

bool DayUI::GetActiveFlag()
{
	return active_flag;
}

int DayUI::GetSpeed()
{
	return speed;
}