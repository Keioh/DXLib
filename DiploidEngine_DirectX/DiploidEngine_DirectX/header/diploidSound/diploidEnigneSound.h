#pragma once
#include "DxLib.h"
#include <vector>

class DiploidEngineSound
{
private:

	std::vector<int> handl;//�n���h��

public:

	VECTOR position;//�ʒu
	bool play = true;//�Đ����邩�ǂ����̃t���O(true�ōĐ�)

	void Load(const char* path);
	void Play(int play_type = DX_PLAYTYPE_BACK);
	void End();
};