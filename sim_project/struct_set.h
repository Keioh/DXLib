#pragma once
#include <string.h>

using namespace std;

struct SOUND_DATA//音に関する情報
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

//一行１２８文字まで(タイトル画面、オプション画面の説明)
struct STRING_DATA
{
	char bgm_volume[128];
	char se_volume[128];
	char start_info_new_game[128];
	char start_info_load[128];
	char start_info_option[128];
	char start_info_exit[128];
};

//一行１２８文字まで(キャラクタの名前)
struct STRING_DATA_CHARACTER_NAME
{
	char charcter_name_0[128];
	char charcter_name_1[128];
	char charcter_name_2[128];
	char charcter_name_3[128];
};

//一行256文字まで(キャラクタ説明)
struct STRING_DATA_CHARACTER_DESCRIPTION
{
	char charcter_0[256];
	char charcter_1[256];
	char charcter_2[256];
	char charcter_3[256];	
};
