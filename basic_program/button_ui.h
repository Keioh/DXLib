#pragma once
#include "Object_Base.h"
#include "Collision.h"
#include "Input.h"

class ButtonUI : public ObjectBase
{
private:
	Collision box_collision;
	Input mouse_input;

	int graphics;
	int click_flag;

public:

	ButtonUI();

	int Load(char* path);

	int BoxUI_Button(int pos_x, int pos_y, float scale_x, float scale_y, int input = MOUSE_INPUT_LEFT, bool wire = false);//バグにつきスケールの値は1.0fで使うこと。（戻り値はクリックフラグが返る。1でクリック、0でクリックしていない。）

};