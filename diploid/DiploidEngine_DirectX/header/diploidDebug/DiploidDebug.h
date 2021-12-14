#pragma once
#include "DxLib.h"
#include "diploidDebug/DiploidLog.h"
#include "diploidDebug/DiploidConsole.h"

class DiploidDebug
{
private:
	int now_game_time;
	int in_game_time;

public:
	DiploidLog log;

	void Init();

	void Update();

	void Draw(bool draw = true);


	int GetInGameTime();//�Q�[�����N�����Ă��鎞�Ԃ��擾���܂��B(�~���b)
};