#pragma once
#include "DxLib.h"

class SoundSystem
{
private:
	int sound_handl;

public:
	SoundSystem();

	int sound_volume;

	void init();//������

	void LoadSound(char* path);//����ǂݍ���

	void Play(float volume_scale, int PlayType);//�����Đ�����B

	void Stop();//�����~����B

	void SoundDelete();//�ǂݍ��񂾉����폜
};