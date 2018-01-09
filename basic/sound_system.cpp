#include "sound_system.h"

SoundSystem::SoundSystem()
{
	SoundSystem::init();
}

void SoundSystem::init()//初期化
{
	one_shot_flag = false;
	sound_volume = 255;
}

void SoundSystem::LoadSound(char* path)//音を読み込む
{
	sound_handl = LoadSoundMem(path);
}

void SoundSystem::LoadSoundCopy(int copy_handl)//同じ音を使う場合はこちらの関数を使うこと。
{
	sound_copy_handl = DuplicateSoundMem(copy_handl);
}

void SoundSystem::Play(float volume, int PlayType, bool copy_type)//音を再生する。
{
	ChangeVolumeSoundMem(volume, sound_handl);//音量を設定。
	ChangeVolumeSoundMem(volume, sound_copy_handl);//音量を設定。

	if (copy_type == false)
	{
		if (CheckSoundMem(sound_handl) == 0)//再生されていないなら
		{
			PlaySoundMem(sound_handl, PlayType, TRUE);//再生する。
		}
	}
	else if (copy_type == true)//ハンドルが複製の場合
	{
		if (CheckSoundMem(sound_copy_handl) == 0)//再生されていないなら
		{
			PlaySoundMem(sound_copy_handl, PlayType, TRUE);//再生する。
		}
	}
}

void SoundSystem::OneShotPlay(float volume, int PlayType, bool copy_type)//一回だけ再生したいときはこっち
{
	ChangeVolumeSoundMem(volume, sound_handl);//音量を設定。
	ChangeVolumeSoundMem(volume, sound_copy_handl);//音量を設定。

	if (copy_type == false)
	{
		if ((CheckSoundMem(sound_handl) == 0) && one_shot_flag == false)//再生されていないなら
		{
			PlaySoundMem(sound_handl, PlayType, TRUE);//再生する。
			one_shot_flag = true;
		}
	}
	else if (copy_type == true)
	{
		if ((CheckSoundMem(sound_copy_handl) == 0) && one_shot_flag == false)//再生されていないなら
		{
			PlaySoundMem(sound_copy_handl, PlayType, TRUE);//再生する。
			one_shot_flag = true;
		}
	}
}

void SoundSystem::OneShotReset()//一回だけ再生した場合はこの関数で必ず初期化
{
	if (one_shot_flag = true)
	{
		one_shot_flag = false;
	}
}

void SoundSystem::Stop()//音を停止する。
{
	if (CheckSoundMem(sound_handl) == 1)//再生中なら
	{
		StopSoundMem(sound_handl);//音を止める。
	}
}

void SoundSystem::SoundDelete()//読み込んだ音を削除
{
	DeleteSoundMem(sound_handl);//削除
}