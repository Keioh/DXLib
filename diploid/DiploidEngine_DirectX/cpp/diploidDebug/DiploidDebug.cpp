#include "diploidDebug/DiploidDebug.h"

void DiploidDebug::Init()
{
	now_game_time = GetNowCount();
	in_game_time = 0;

	log.Init();
}

void DiploidDebug::Update()
{
	log.Update();
}

void DiploidDebug::Draw(bool draw)
{
	log.Draw(draw);
}


int DiploidDebug::GetInGameTime()
{
	return in_game_time = GetNowCount() - now_game_time;
}