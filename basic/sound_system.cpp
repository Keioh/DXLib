#include "sound_system.h"

SoundSystem::SoundSystem()
{
	SoundSystem::init();
}

void SoundSystem::init()//初期化
{
	sound_volume = 255;
}

void SoundSystem::LoadSound(char* path)//音を読み込む
{
	sound_handl = LoadSoundMem(path);
}

void SoundSystem::Play(float volume_scale, int PlayType)//音を再生する。(volume_scaleは1.0f~0.0fで設定。0.0fでボリューム0)
{
	ChangeVolumeSoundMem(sound_volume * volume_scale, sound_handl);//音量を設定。

	if (CheckSoundMem(sound_handl) == 0)//再生されていないなら
	{
		PlaySoundMem(sound_handl, PlayType, TRUE);//再生する。
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