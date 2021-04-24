#include "ver2.0/Objects/button/WindowSize.h"

void WindowSize::Load(const char* path)
{
	windows_size_button_image.Load(path);

	radio_button_off.Load("texter/basic/button/radio/0.png");
	radio_button_on.Load("texter/basic/button/radio/1.png");
}

void WindowSize::Init(VECTOR pos, DiploidEngineSetting& setting)
{
	//ウィンドウサイズ変更ボタン
	windows_size_button.Init(pos, VGet(160, 32, 0));
	windows_size_button_image.Init(pos);
	radio_button_off.Init(pos);
	radio_button_on.Init(pos);	
	
	if ((setting.GetSystemData().window_x == this->window_x) && (setting.GetSystemData().window_y == this->window_y))
	{
		windows_size_button.SetSelectedUI(1);
	}
	else
	{
		windows_size_button.SetSelectedUI(-1);
	}
}

void WindowSize::Update(DiploidEngineInput& input)
{
	//ウィンドウサイズ変更ボタン
	windows_size_button.Updata(&input);
}

void WindowSize::Draw(bool draw, bool debug)
{
	windows_size_button_image.Draw(draw);
	windows_size_button.Draw(draw, debug);
	radio_button_off.Draw(draw);

	if (windows_size_button.GetSelectedUI() == 1)
	{
		radio_button_on.Draw(draw);
	}
}


bool WindowSize::GetHit()
{
	return windows_size_button.GetHit();
}

bool WindowSize::GetClick()
{
	return windows_size_button.GetClick();
}

int WindowSize::GetSelected()
{
	return windows_size_button.GetSelectedUI();
}


void WindowSize::SetSelectedFlag(int new_flag)
{
	windows_size_button.SetSelectedUI(new_flag);
}

void WindowSize::SetWindowSize(int new_window_x, int new_window_y)
{
	window_x = new_window_x;
	window_y = new_window_y;
}