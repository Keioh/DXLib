#pragma once
#include "DxLib.h"

#include "save_and_return.h"

#include "fade_in.h"
#include "fade_out.h"

#include "bgm_volume_slider.h"
#include "se_volume_slider.h"
#include "bgm_mute.h"
#include "se_mute.h"

class OptionScene
{
private:
	BGMVolumeSlider bgm_volume;
	SEVolumeSlider se_volume;
	BGMMute bgm_mute;
	SEMute se_mute;

	SaveAndReturn save_and_return;

	bool flag;//クリック判定保存変数

	int back_wall_graphics;//背景画像ハンドル保存用変数

public:
	OptionScene();

	FadeIn fade_in;
	FadeOut fade_out;

	int option_scene_flag;

	void Load();
	void Init();

	void DrawOptionScene(int window_x, int window_y, bool wire);

};