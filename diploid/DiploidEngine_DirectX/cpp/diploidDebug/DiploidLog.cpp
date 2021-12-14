#include "diploidDebug/DiploidLog.h"

void DiploidLog::Init(int pos_x, int pos_y)
{
	position_x = pos_x;
	position_y = pos_y;
}

void DiploidLog::Update()
{

}

void DiploidLog::Draw(bool draw)
{
	if(draw == true)
	{
		int count = 0;

		for (auto itr = log_list.begin(); itr != log_list.end(); itr++)
		{
			DrawFormatString(position_x, position_y + (20 * count), GetColor(red, green, blue), itr->c_str());

			count++;
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