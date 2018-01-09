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
	char bgm_volume[128];
	char se_volume[128];
};