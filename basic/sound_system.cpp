#include "sound_system.h"

SoundSystem::SoundSystem()
{
	SoundSystem::init();
}

void SoundSystem::init()//初期化
{

}

void SoundSystem::LoadSound(char* path)//音を読み込む
{
	sound_handl = LoadSoundMem(path);
}
