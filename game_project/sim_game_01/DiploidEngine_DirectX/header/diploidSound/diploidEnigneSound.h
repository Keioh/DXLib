#pragma once
#include "DxLib.h"
#include <vector>

class DiploidEngineSound
{
private:

public:

	int handl;

	VECTOR position;//ˆÊ’u
	bool play = true;//Ä¶‚·‚é‚©‚Ç‚¤‚©‚Ìƒtƒ‰ƒO(true‚ÅÄ¶)

	void Load(const char* path);
	void Play(int play_type = DX_PLAYTYPE_BACK);
	void Stop();//–¢À‘•
	void End();
};