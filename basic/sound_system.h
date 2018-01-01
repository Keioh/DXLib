#pragma once
#include "DxLib.h"

class SoundSystem
{
private:
	int sound_handl;

public:
	SoundSystem();

	void init();//‰Šú‰»

	void LoadSound(char* path);//‰¹‚ğ“Ç‚İ‚Ş
};