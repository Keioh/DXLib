#pragma once
#include "DxLib.h"
#include <vector>

class DiploidEngineSound
{
private:

public:

	int handl;

	VECTOR position;//位置
	bool play = true;//再生するかどうかのフラグ(trueで再生)

	void Load(const char* path);
	void Play(int play_type = DX_PLAYTYPE_BACK);
	void Stop();//未実装
	void End();
};