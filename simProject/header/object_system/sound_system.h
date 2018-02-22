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

	void init();//初期化

	void LoadSound(char* path, int data_flag = FALSE);//音を読み込む(data_flagをTRUEにすると3D用ハンドルになります。)
	void LoadSoundCopy(int copy_handl);//同じ音を使う場合はこちらの関数を使うこと。

	void Play(float volume, int PlayType, bool copy_type = false);//音を再生する。
	void Play3D(VECTOR pos, float volume, int PlayType, bool wire = false, bool copy_type = false);//音を再生する。(3D版)

	void OneShotPlay(float volume, int PlayType, bool copy_type = false);//一回だけ再生したいときはこっち
	void OneShotPlay3D(VECTOR pos, float volume, int PlayType, bool wire = false, bool copy_type = false);//一回だけ再生したいときはこっち(3D版)
	void OneShotReset();//一回だけ再生した場合はこの関数で必ず初期化(3D兼用)

	void Stop();//音を停止する。

	void SoundDelete();//読み込んだ音を削除
};