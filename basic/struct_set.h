#pragma once

struct SOUND_DATA//���Ɋւ�����
{
	int bgm_volume;
	int se_volume;
	int bgm_mute;
	int se_mute;
};

struct WINDOW_DATA
{
	int windowX;
	int windowY;
	int windowBit;
};

struct LANGUAGE_DATA
{
	int japanese_flag;
	int english_flag;
};

//��s�P�Q�W�����܂�
struct STRING_DATA
{
	char ID_000[128];
	char ID_001[128];
};