#pragma once
#include "DxLib.h"


class Sound
{
private:
	int sound[8];	//サウンドハンドル保存用(0は何もなし)

public:
	Sound();
	int stop_sound_dont_use;
	int stop_sound_dont_use_1;
	//int stop_sound_dont_use_2;

	int stop;
	int wait;
	int quiet_battle;
	int intense_battle;
	int normal_time_in_game;
	int deity;
	int reasoning;
	int fear;
	int climax;

	void Load();//SOUNDデータをロード
	void Play(int sound_number);//サウンド再生関数(再生したいサウンドの番号)


};