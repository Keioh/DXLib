#pragma once
#include "DxLib.h"
#include "FileInput.h"
#include "sound_system.h"

#include "option_return.h"
#include "apply.h"
#include "english.h"
#include "japanese.h"

#include "fade_in.h"
#include "fade_out.h"

#include "bgm_volume_slider.h"
#include "se_volume_slider.h"
#include "bgm_mute.h"
#include "se_mute.h"

class OptionScene
{
private:

	FadeIn fade_in;
	FadeOut fade_out;


	Apply apply_button;
	OptionReturn option_return;

	bool flag;//クリック判定保存変数
	bool language_change_flag;//言語変更フラグ

	int anime_alph;
	float anime_speed;

	int back_wall_graphics;//背景画像ハンドル保存用変数

public:
	OptionScene();

	SoundSystem se_apply,se_apply_click;
	SoundSystem se_option_return, se_option_return_click;
	SoundSystem se_bgm_volume;
	SoundSystem se_se_volume;

	Japanese japanese;
	English english;

	BGMVolumeSlider bgm_volume;
	SEVolumeSlider se_volume;
	BGMMute bgm_mute;
	SEMute se_mute;

	bool back_flag;

	int option_scene_flag;

	void Load();
	void Init(Filer config);

	bool DrawOptionScene(int window_x, int window_y, Filer& config, bool wire);//configは設定ファイルを突っ込む

};