#pragma once
#include <list>
#include <string>
#include "DxLib.h"
#include "diploidInput/DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "system\DiploidEngineSetting.h"

class DiploidLog
{
private:
	std::list<std::string> log_list;

	DiploidEngineInput input, input_two;
	DiploidBoxV2 box;

	int shift_y = 0;
	int shift_scroll_y = 0;

	int position_x, position_y;
	int red = 255, green = 255, blue = 255;
	bool log_screen_flag = false;//true‚È‚ç•`‰æ‚Æˆ—‚ğÄŠJ‚·‚éB

public:
	void Init();
	void Update(int pos_x = 0, int pos_y = 0);
	void Draw(bool draw = true);

	void Push(std::string str);

	void SetPosition(int new_pos_x, int new_pos_y);
	void SetColor(int new_red, int new_green, int new_blue);

	std::list<std::string>* GetLogListPointer();
};