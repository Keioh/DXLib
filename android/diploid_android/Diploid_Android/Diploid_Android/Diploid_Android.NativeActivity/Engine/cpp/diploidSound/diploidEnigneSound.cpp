#include "diploidSound\diploidEnigneSound.h"

void DiploidEngineSound::Load(const char* path)
{
	handl = LoadSoundMem(path);
}

void DiploidEngineSound::Play(int play_type)
{
	if ((CheckSoundMem(handl) == 0) && (play == true))
	{
		PlaySoundMem(handl, play_type);
	}
}

void DiploidEngineSound::Stop()
{

}

void DiploidEngineSound::End()
{
	InitSoundMem();
}