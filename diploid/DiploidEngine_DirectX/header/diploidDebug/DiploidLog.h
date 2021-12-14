#pragma once
#include <list>
#include <string>
#include "DxLib.h"

class DiploidLog
{
private:
	std::list<std::string> log_list;

	int position_x, position_y;
	int red, green, blue;

public:
	void Init(int pos_x = 0, int pos_y = 0);
	void Update();
	void Draw(bool draw = true);

	void Push(std::string str);

	void SetPosition(int new_pos_x, int new_pos_y);
	void SetColor(int new_red, int new_green, int new_blue);

	std::list<std::string>* GetLogListPointer();
};