#pragma once
#include "DxLib.h"

class SoundSystem
{
private:
	int sound_handl;

public:
	SoundSystem();

	void init();//初期化

	void LoadSound(char* path);//音を読み込む
};