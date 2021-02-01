#pragma once
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"

class WindowSize
{
private:
	DiploidImageV2 radio_button_off, radio_button_on;

	DiploidImageV2 windows_size_button_image;
	DiploidSelectedUIV2 windows_size_button;

	int window_x = 1280;
	int window_y = 720;

public:
	void Load(const char* path);
	void Init(VECTOR pos, DiploidEngineSetting& setting);
	void Update(DiploidEngineInput& input);
	void Draw(bool draw = true, bool debug = false);

	bool GetHit();//カーソルが当たっているか
	bool GetClick();//クリックされたか
	int GetSelected();//選択状態か

	void SetWindowSize(int new_window_x, int new_window_y);
	void SetSelectedFlag(int new_flag);

};