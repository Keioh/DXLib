#pragma once
#include "button_ui.h"
#include "fade_in.h"

class LevelSwitch
{
private:
	FadeIn fade_in;

	ButtonUI level_reset_switch;

	ButtonUI level01_switch;
	ButtonUI level02_switch;
	ButtonUI level03_switch;

	float anime_sin;

public:

	int anime_alph;
	int select_level;//���ݑI�����Ă��郌�x��

	void init();
	void AnimtionInit();
	void Load();
	void Draw(int pos_x, int pos_y, bool wire);//���x���Z���N�g�{�^��
	void ResetButtonDraw(int pos_x, int pos_y, bool wire);//switch_level��0�ɂ���{�^��

};