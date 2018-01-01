#pragma once
#include "Object_Base.h"
#include "Collision.h"
#include "Input.h"

class ButtonUI : public ObjectBase
{
private:
	Collision box_collision;
	Collision circle_collision;
	Input mouse_input;

	int graphics;
	int click_flag;//クリックしたかどうかのフラグ

public:
	ButtonUI();

	int switch_flag;//スイッチフラグ

	void Load(char* path);
	void Init();

	int BoxUI_Button(int pos_x, int pos_y, float scale_x, float scale_y, int input = MOUSE_INPUT_LEFT, bool wire = false);//バグにつきスケールの値は1.0fで使うこと。（戻り値はクリックフラグが返る。1でクリック、0でクリックしていない。）
	int BoxUI_Button_Continuation(int pos_x, int pos_y, float scale_x, float scale_y, int input = MOUSE_INPUT_LEFT, bool wire = false);//バグにつきスケールの値は1.0fで使うこと。（戻り値はクリックフラグが返る。1でクリック、0でクリックしていない。）
	int BoxUI_Button_Switch(int pos_x, int pos_y, float scale_x, float scale_y, int input = MOUSE_INPUT_LEFT, bool wire = false);//バグにつきスケールの値は1.0fで使うこと。（戻り値はクリックフラグが返る。1でクリック、0でクリックしていない。）

	int CircleUI_Button(int pos_x, int pos_y, int size_r, int input = MOUSE_INPUT_LEFT, bool wire = false);//戻り値はクリックフラグが返る。1でクリック、0でクリックしていない。）

};