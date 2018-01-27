#pragma once
#include "sound_system.h"
#include "button_ui.h"
#include "fade_in.h"
#include "FileInput.h"

class LevelSwitch
{
private:
	FadeIn fade_in;

	SoundSystem hit_se[4];

	ButtonUI level_reset_switch;

	ButtonUI level01_switch;
	ButtonUI level02_switch;
	ButtonUI level03_switch;

	float anime_sin;

	void PlayHitSE(Filer config);

public:

	int anime_alph;
	int select_level;//現在選択しているレベル

	void init();
	void AnimtionInit();
	void Load();


	void Draw(int pos_x, int pos_y, Filer config, bool wire);//レベルセレクトボタン
	void ResetButtonDraw(int pos_x, int pos_y, bool wire);//switch_levelを0にするボタン

};