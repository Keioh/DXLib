#pragma once
#include "DxLib.h"
#include <vector>

class DiploidEngineSound
{
private:

	std::vector<int> handl;//�n���h��

public:

	void Load(const char* path);
	void Play(int play_type = 0);
};