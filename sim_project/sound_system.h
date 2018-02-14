#pragma once
#include "DxLib.h"

class SoundSystem
{
private:

public:
	SoundSystem();

	int sound_handl;
	int sound_copy_handl;
	float sound_r;

	int sound_volume;
	bool one_shot_flag;

	void init();//������

	void LoadSound(char* path, int data_flag = FALSE);//����ǂݍ���(data_flag��TRUE�ɂ����3D�p�n���h���ɂȂ�܂��B)
	void LoadSoundCopy(int copy_handl);//���������g���ꍇ�͂�����̊֐����g�����ƁB

	void Play(float volume, int PlayType, bool copy_type = false);//�����Đ�����B
	void Play3D(VECTOR pos, float volume, int PlayType, bool wire = false, bool copy_type = false);//�����Đ�����B(3D��)

	void OneShotPlay(float volume, int PlayType, bool copy_type = false);//��񂾂��Đ��������Ƃ��͂�����
	void OneShotPlay3D(VECTOR pos, float volume, int PlayType, bool wire = false, bool copy_type = false);//��񂾂��Đ��������Ƃ��͂�����(3D��)
	void OneShotReset();//��񂾂��Đ������ꍇ�͂��̊֐��ŕK��������(3D���p)

	void Stop();//�����~����B

	void SoundDelete();//�ǂݍ��񂾉����폜
};