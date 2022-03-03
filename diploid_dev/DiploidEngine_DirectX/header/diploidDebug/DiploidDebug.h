#pragma once
#include "DxLib.h"
#include "diploidDebug/DiploidLog.h"
#include "diploidDebug/DiploidConsole.h"
#include "system\DiploidEngineSetting.h"

class DiploidDebug
{
private:
	int now_game_time = 0;
	int in_game_time = 0;

public:
	DiploidLog log;

	void Init();

	void Update(DiploidEngineSetting& setting);

	void Draw(bool draw = true);


	int GetInGameTime();//�Q�[�����N�����Ă��鎞�Ԃ��擾���܂��B(�~���b)
};