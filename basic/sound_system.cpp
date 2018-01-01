#include "sound_system.h"

SoundSystem::SoundSystem()
{
	SoundSystem::init();
}

void SoundSystem::init()//‰Šú‰»
{

}

void SoundSystem::LoadSound(char* path)//‰¹‚ğ“Ç‚İ‚Ş
{
	sound_handl = LoadSoundMem(path);
}
