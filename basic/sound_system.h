#pragma once
#include "DxLib.h"

class SoundSystem
{
private:
	int sound_handl;

public:
	SoundSystem();

	int sound_volume;

	void init();//初期化

	void LoadSound(char* path);//音を読み込む

	void Play(float volume_scale, int PlayType);//音を再生する。

	void Stop();//音を停止する。

	void SoundDelete();//読み込んだ音を削除
};