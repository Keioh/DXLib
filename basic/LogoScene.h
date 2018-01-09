#pragma once
#include "DxLib.h"
#include "FileInput.h"

#include "logo.h"

#include "sound_system.h"

#include "fade_in.h"
#include "fade_out.h"

class LogoScene
{
private:
	Logo logo;//���S�\���֘A

	SoundSystem logo_sound;//���S��\������Ƃ��ɖ炷��

	FadeIn fade_in;//�t�F�[�h�C��
	FadeOut fade_out;//�t�F�[�h�A�E�g

public:
	LogoScene();//�R���X�g���N�^

	int logo_scene_flag;

	int logo_sound_handl;

	void init();//������

	void Load();//�ǂݍ���
	void DrawLogoScene(int x, int y, Filer config);//�`��

};