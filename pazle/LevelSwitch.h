#pragma once
#include "button_ui.h"

class LevelSwitch
{
private:
	ButtonUI level_reset_switch;

	ButtonUI level01_switch;
	ButtonUI level02_switch;
	ButtonUI level03_switch;

public:

	int anime_alph;
	int select_level;//現在選択しているレベル

	void init();
	void AnimtionInit();
	void Load();
	void Draw(int pos_x, int pos_y, bool wire);//レベルセレクトボタン
	void ResetButtonDraw(int pos_x, int pos_y, bool wire);//switch_levelを0にするボタン

};