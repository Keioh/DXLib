#include "Input.h"

Input::Input()
{

}

//瞬間のクリック
bool Input::MouseCilck(int MouseInput)//若干挙動がおかしいかも
{
	//int Button, x, y;

	// クリック情報を取得する
	if (GetMouseInputLog(&button_buffer, &x_buffer, &y_buffer, TRUE) == 0)
	{
		if ((GetMouseInput() & button_buffer & MouseInput) != 0)
		{
			return true;
		}
	}
	return false;
}

//マウスの継続クリック
bool Input::MouseInputClick(int mouseinput)
{
	if ((GetMouseInput() & mouseinput) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}