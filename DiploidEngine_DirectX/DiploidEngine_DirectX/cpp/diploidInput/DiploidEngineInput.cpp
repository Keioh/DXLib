#include "diploidInput\DiploidEngineInput.h"

void DiploidEngineInput::Init()
{

}

void DiploidEngineInput::Update()
{
	GetHitKeyStateAll(Key);//�L�[�̏�Ԃ��m�F
	Check_Mouse = GetMouseInputLog2(&MOUSE_BUTTON, &CLICK_X, &CLICK_Y, &LOG_TYPE, TRUE);//�}�E�X�̏�Ԃ��m�F
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
	if (Key[DXLIB_KEY_CODE] != 0)
	{
		return true;//�L�[��������Ă�����true��Ԃ��B
	}

	return false;
}

bool DiploidEngineInput::GetPressKey(int DXLIB_KEY_CODE)
{
	if (Key[DXLIB_KEY_CODE] != 0)
	{
		press_time++;//�����Ă���t���[���𐔂���B

		if (press_time <= 1)
		{
			return true;//�L�[��������Ă�����true��Ԃ��B
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