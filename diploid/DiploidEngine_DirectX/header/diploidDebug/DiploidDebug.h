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


	int GetInGameTime();//ゲームを起動している時間を取得します。(ミリ秒)
};