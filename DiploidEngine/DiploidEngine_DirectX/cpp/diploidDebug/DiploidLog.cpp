#include "diploidDebug/DiploidLog.h"

void DiploidLog::Init()
{
	position_x = 0;
	position_y = 0;

	box.Init(VGet(position_x, position_y, 0), VGet(320, 1080, 0), GetColor(0, 0, 0));
	box.SetFill(true);
}

void DiploidLog::Update(int pos_x, int pos_y)
{
	input.Update();

	if (input.GetPressKey(KEY_INPUT_F3) == true)
	{
		if (log_screen_flag == false)
		{
			log_screen_flag = true;
		}
		else
		{
			log_screen_flag = false;
		}
	}

	if (log_screen_flag == true)
	{
		position_x = pos_x;
		position_y = pos_y;

		shift_scroll_y += input.GetWhellVolume() * 20;

		box.SetPosition(VGet(position_x - 320, 0, 0));

		box.MoveUpdate();

		//ÅŒã”ö‚ÉˆÚ“®
		input_two.Update();

		if (input_two.GetPressKey(KEY_INPUT_END) == true)
		{
			if (!log_list.empty())
			{
				shift_scroll_y = (log_list.size() - 1) * -20;
			}
		}
	}
}

void DiploidLog::Draw(bool draw)
{
	if(draw == true)
	{
		if (log_screen_flag == true)
		{
			int count = 0;

			box.Draw(draw);

			for (auto itr = log_list.begin(); itr != log_list.end(); itr++)
			{
				DrawFormatString(position_x - 320, (20 * count) + shift_scroll_y, GetColor(red, green, blue), itr->c_str());

				count++;
			}
		}
	}
}


void DiploidLog::Push(std::string str)
{
	log_list.push_back(str);
}

void DiploidLog::SetPosition(int new_pos_x, int new_pos_y)
{
	position_x = new_pos_x;
	position_y = new_pos_y;
}

void DiploidLog::SetColor(int new_red, int new_green, int new_blue)
{
	red = new_red;
	green = new_green;
	blue = new_blue;
}


std::list<std::string>* DiploidLog::GetLogListPointer()
{
	return &log_list;
}