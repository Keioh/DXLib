#pragma once
#include "KeyInput.h"

bool KEY_INPUT::Key_isPush(int Key_type, bool debug)
{
	static int isPush_flag = -1;

	if (isPush_flag == -1)
	{
		if (CheckHitKey(KEY_INPUT_SPACE) != 0)
		{
			isPush_flag *= -1;
			return false;
		}
	}

	if (isPush_flag == 1)
	{
		if (CheckHitKey(KEY_INPUT_SPACE) != 1)
		{
			isPush_flag *= -1;
			return true;
		}
	}

	if (debug == true)
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Key_isPush =  %d", isPush_flag);
	}
}