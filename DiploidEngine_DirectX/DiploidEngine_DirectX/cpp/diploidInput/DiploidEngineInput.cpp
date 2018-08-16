#include "diploidInput\DiploidEngineInput.h"

void DiploidEngineInput::Init()
{

}

void DiploidEngineInput::Update()
{
	GetHitKeyStateAll(Key);//キーの状態を確認
	Check_Mouse = GetMouseInputLog2(&MOUSE_BUTTON, &CLICK_X, &CLICK_Y, &LOG_TYPE, TRUE);//マウスの状態を確認
}

void DiploidEngineInput::Draw(int x, int y ,bool debug)
{
	if (CheckHitKeyAll() != 0)//キーが押されていたら文字を表示
	{
		DrawFormatStringF(x, y, GetColor(255, 255, 255), "press key");
	}

	if (Check_Mouse != -1)
	{
		if ((MOUSE_BUTTON & MOUSE_INPUT_LEFT) != 0)
		{
			DrawFormatStringF(x, y + 20, GetColor(255, 255, 255), "press mouse left");
		}
		else if ((MOUSE_BUTTON & MOUSE_INPUT_RIGHT) != 0)
		{
			DrawFormatStringF(x, y + 40, GetColor(255, 255, 255), "press mouse right");
		}
		else if ((MOUSE_BUTTON & MOUSE_INPUT_MIDDLE) != 0)
		{
			DrawFormatStringF(x, y + 60, GetColor(255, 255, 255), "press mouse middle");
		}
	}
}

bool DiploidEngineInput::GetMouse(int DXLIB_MOUSE_CODE)
{
	if ((MOUSE_BUTTON & DXLIB_MOUSE_CODE) != 0)
	{
		return true;
	}

	return false;
}

bool DiploidEngineInput::GetKey(int DXLIB_KEY_CODE)
{
	if (Key[DXLIB_KEY_CODE] != 0)
	{
		return true;//キーが押されていたらtrueを返す。
	}

	return false;
}
