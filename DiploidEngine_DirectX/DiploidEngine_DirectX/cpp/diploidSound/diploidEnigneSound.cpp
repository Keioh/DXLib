#include "diploidSound\diploidEnigneSound.h"

void DiploidEngineSound::Load(const char* path)
{
	handl.push_back(LoadSoundMem(path));
}

void DiploidEngineSound::Play(int play_type)
{
	for (auto handl_count = handl.begin(); handl_count != handl.end(); ++handl_count)
	{
		if (CheckSoundMem(*handl_count) == 1)
		{
			PlaySoundMem(*handl_count, play_type);
		}
	}
}

void DiploidEngineSound::End()
{
	InitSoundMem();
}