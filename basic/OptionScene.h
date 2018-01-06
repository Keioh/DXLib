#pragma once
#include "DxLib.h"
#include "FileInput.h"
#include "sound_system.h"

#include "save_and_return.h"
#include "apply.h"

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

	BGMVolumeSlider bgm_volume;
	SEVolumeSlider se_volume;
	BGMMute bgm_mute;
	SEMute se_mute;

	Apply apply_button;
	SaveAndReturn save_and_return;

	bool flag;//�N���b�N����ۑ��ϐ�

	int back_wall_graphics;//�w�i�摜�n���h���ۑ��p�ϐ�

public:
	OptionScene();

	SoundSystem bgm;


	int option_scene_flag;

	void Load();
	void Init();

	void DrawOptionScene(int window_x, int window_y, Filer config, bool wire);//config�͐ݒ�t�@�C����˂�����

};