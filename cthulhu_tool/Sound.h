#pragma once
#include "DxLib.h"


class Sound
{
private:
	int sound[8];	//�T�E���h�n���h���ۑ��p(0�͉����Ȃ�)

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

	void Load();//SOUND�f�[�^�����[�h
	void Play(int sound_number);//�T�E���h�Đ��֐�(�Đ��������T�E���h�̔ԍ�)


};