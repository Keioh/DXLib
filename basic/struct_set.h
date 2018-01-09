#pragma once

struct SOUND_DATA//音に関する情報
{
	int bgm_volume;
	int se_volume;
	int bgm_mute;
	int se_mute;
};

struct LANGUAGE_DATA
{
	int japanese_flag;
	int english_flag;
};

struct STRING_DATA
{
	char ID_001[128];
};