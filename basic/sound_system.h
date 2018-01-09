#pragma once
#include "DxLib.h"

class SoundSystem
{
private:

public:
	SoundSystem();

	int sound_handl;
	int sound_copy_handl;

	int sound_volume;
	bool one_shot_flag;

	void init();//������

	void LoadSound(char* path);//����ǂݍ���
	void LoadSoundCopy(int copy_handl);//���������g���ꍇ�͂�����̊֐����g�����ƁB

	void Play(float volume, int PlayType, bool copy_type = false);//�����Đ�����B

	void OneShotPlay(float volume, int PlayType, bool copy_type = false);//��񂾂��Đ��������Ƃ��͂�����
	void OneShotReset();//��񂾂��Đ������ꍇ�͂��̊֐��ŕK��������

	void Stop();//�����~����B

	void SoundDelete();//�ǂݍ��񂾉����폜
};