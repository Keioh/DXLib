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
	int fullscreen;
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
	char start_info_new_game[128];
	char start_info_load[128];
	char start_info_option[128];
	char start_info_exit[128];
};