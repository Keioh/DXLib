#include "Input.h"


void Input::init()
{
	key_press = false;
	click = false;
	//button_buffer = -1;
	//x_buffer = -1;
	//y_buffer = -1;
	//button_input_log_buffer = -1;
}

int Input::GetKeyFrame()//キーフレームを習得
{
	GetHitKeyStateAll(key); // 全てのキーの入力状態を得る

	for (int n = 0; n < 256; n++) {
		if (key[n] != 0) { // n番のキーコードに対応するキーが押されていたら
			frame[n]++;     // 加算
		}
		else {              // 押されていなければ
			frame[n] = 0;   // 0にする
		}
	}
	return 0;
}

//瞬間のクリック
bool Input::MouseCilck(int MouseInput)//若干挙動がおかしいかも
{
	//int Button, x, y;

	// クリック情報を取得する
	if (GetMouseInputLog2(&button_buffer, &x_buffer, &y_buffer, &button_input_log_buffer, TRUE) == 0)
	{
		if ((GetMouseInput() & button_buffer & MouseInput) != 0)
		{
			return click = true;
		}
	}
	return click = false;
}

//マウスの継続クリック
bool Input::MouseClickContinuation(int mouseinput)
{
	if ((GetMouseInput() & mouseinput) != 0)
	{
		return  click = true;
	}
	else
	{
		return click = false;
	}
}

//キーの瞬間のクリック
bool Input::KeyCilick(int keyInput)
{
	if (frame[keyInput] == 1)
	{
		return key_press = true;
	}
	else
	{
		return key_press = false;
	}
}

//キーの継続クリック
bool Input::KeyCilickContinuation(int keyInput)
{
	if (key[keyInput] != 0)
	{
		return key_press = true;
	}
	else
	{
		return key_press = false;
	}
}
