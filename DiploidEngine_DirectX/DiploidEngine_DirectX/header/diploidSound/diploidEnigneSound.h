#pragma once
#include "DxLib.h"
#include <vector>

class DiploidEngineSound
{
private:

public:

	int handl;

	VECTOR position;//�ʒu
	bool play = true;//�Đ����邩�ǂ����̃t���O(true�ōĐ�)

	void Load(const char* path);
	void Play(int play_type = DX_PLAYTYPE_BACK);
	void Stop();//������
	void End();
};