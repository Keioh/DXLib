#include "diploidInput\DiploidEngineInput.h"

void DiploidEngineInput::Init()
{

}

void DiploidEngineInput::Update()
{
	GetHitKeyStateAll(key);//キーの状態を確認

	/*	
	for (int count = 0; count < 256; ++count)
	{
		if (buffer[count])
		{
			if (key[count] == 0)
			{
				key[count] = 1;
			}
			else if (key[count] == 1)
			{
				key[count] = 2;
			}
			else
			{
				key[count] = 0;
			}
		}
	}
	*/

	Check_Mouse = GetMouseInputLog2(&MOUSE_BUTTON, &CLICK_X, &CLICK_Y, &LOG_TYPE, TRUE);//マウスの状態を確認

	GetMousePoint(&mouse_pos_adr_x, &mouse_pos_adr_y);//現在のマウス座標を取得

	//押したときの座標
	if (LOG_TYPE == MOUSE_INPUT_LOG_DOWN)
	{
		press_click_position_x = CLICK_X;
		press_click_position_y = CLICK_Y;
	}

	//離したときの座標
	if (LOG_TYPE == MOUSE_INPUT_LOG_UP)
	{
		release_click_position_x = CLICK_X;
		release_click_position_y = CLICK_Y;
	}

}

void DiploidEngineInput::Draw(int x, int y ,bool debug)
{
	DrawFormatStringF(x, y, GetColor(255, 255, 255), "CHECK MOUSE = %d", Check_Mouse);
}

bool DiploidEngineInput::GetMouse(int DXLIB_MOUSE_CODE)
{
	if ((MOUSE_BUTTON & DXLIB_MOUSE_CODE) != 0)
	{
		return true;
	}

	return false;
}

bool DiploidEngineInput::GetPressMouse(int DXLIB_MOUSE_CODE)
{
	if (Check_Mouse != -1)
	{
		if (GetMouse(DXLIB_MOUSE_CODE) == true)
		{
			if (LOG_TYPE == MOUSE_INPUT_LOG_DOWN)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;
}

bool DiploidEngineInput::GetReleaseMouse(int DXLIB_MOUSE_CODE)
{
	if (Check_Mouse != -1)
	{
		if (GetMouse(DXLIB_MOUSE_CODE) == true)
		{
			if (LOG_TYPE == MOUSE_INPUT_LOG_UP)
			{
				return true;
			}
		}
	}

	return false;
}

bool DiploidEngineInput::GetKey(int DXLIB_KEY_CODE)
{
	if (key[DXLIB_KEY_CODE] != 0)
	{
		return true;//キーが押されていたらtrueを返す。
	}

	return false;
}

bool DiploidEngineInput::GetPressKey(int DXLIB_KEY_CODE)
{
	if (key[DXLIB_KEY_CODE] != 0)
	{		
		press_time++;

		if (press_time <= 1)
		{
			return true;
		}
		else if (press_time >= 2)
		{
			return false;
		}
	}
	else
	{
		press_time = 0;
	}

	return false;
}

bool DiploidEngineInput::GetReleaseKey(int DXLIB_KEY_CODE)
{
	if (GetKey(DXLIB_KEY_CODE) == true)
	{
		release_key_flag = 1;
	}

	if (release_key_flag == 1)
	{
		if (GetKey(DXLIB_KEY_CODE) == false)
		{
			release_key_flag = -1;
			return true;
		}
	}

	return false;
}

VECTOR DiploidEngineInput::GetMousePressPosition()
{
	VECTOR pos;

	pos.x = press_click_position_x;
	pos.y = press_click_position_y;
	pos.z = 0;

	return pos;
}

VECTOR DiploidEngineInput::GetMouseReleasePosition()
{
	VECTOR pos;

	pos.x = release_click_position_x;
	pos.y = release_click_position_y;
	pos.z = 0;

	return pos;
}

VECTOR DiploidEngineInput::GetMousePosition()
{
	VECTOR pos;

	pos.x = mouse_pos_adr_x;
	pos.y = mouse_pos_adr_y;
	pos.z = 0;

	return pos;
}