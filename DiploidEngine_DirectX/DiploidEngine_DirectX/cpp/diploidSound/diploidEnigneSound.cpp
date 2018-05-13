#include "diploidSound\diploidEnigneSound.h"

void DiploidEngineSound::Load(const char* path)
{
	handl.push_back(LoadSoundMem(path));
}

void DiploidEngineSound::Play(int play_type)
{

}