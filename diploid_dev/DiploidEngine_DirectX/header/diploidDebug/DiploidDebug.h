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


	int GetInGameTime();//ゲームを起動している時間を取得します。(ミリ秒)
};