#pragma once
#include "DxLib.h"
#include <vector>

class DiploidEngineSound
{
private:

	std::vector<int> handl;//ƒnƒ“ƒhƒ‹

public:

	void Load(const char* path);
	void Play(int play_type = 0);
};