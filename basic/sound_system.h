#pragma once
#include "DxLib.h"

class SoundSystem
{
private:
	int sound_handl;

public:
	SoundSystem();

	int sound_volume;

	void init();//‰Šú‰»

	void LoadSound(char* path);//‰¹‚ğ“Ç‚İ‚Ş

	void Play(float volume_scale, int PlayType);//‰¹‚ğÄ¶‚·‚éB

	void Stop();//‰¹‚ğ’â~‚·‚éB

	void SoundDelete();//“Ç‚İ‚ñ‚¾‰¹‚ğíœ
};