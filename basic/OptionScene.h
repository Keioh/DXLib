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

	bool flag;//�N���b�N����ۑ��ϐ�

	int anime_alph;
	float anime_speed;

	int back_wall_graphics;//�w�i�摜�n���h���ۑ��p�ϐ�

public:
	OptionScene();

	SoundSystem bgm;

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

	bool DrawOptionScene(int window_x, int window_y, Filer& config, bool wire);//config�͐ݒ�t�@�C����˂�����

};