#pragma once
#include "DxLib.h"

class SoundSystem
{
private:
	int sound_handl;

public:
	SoundSystem();

	void init();//������

	void LoadSound(char* path);//����ǂݍ���
};