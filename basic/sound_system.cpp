#include "sound_system.h"

SoundSystem::SoundSystem()
{
	SoundSystem::init();
}

void SoundSystem::init()//������
{

}

void SoundSystem::LoadSound(char* path)//����ǂݍ���
{
	sound_handl = LoadSoundMem(path);
}
