#pragma once
#include <string.h>

using namespace std;

struct MODE
{
	int connection_mode = -1;
};

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
struct STRING_DATA_TITLE_AND_OPTION
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

//一行128文字まで(全キャラクター共通のファクション説明)
struct STRING_DATA_FACTION_INFOMAITON
{
	char main_title[128];//タブの名前
	char branch_point[128];
	char laboratory[128];
	char money[128];
	char research[128];//研究中
	char study[128];//勉強中
	char seasons[128];//季節
	char small_seasons[128];//節季
	char years[128];
	char hostility[128];//敵対
	char friendship[128];//友好
	char alliance[128];//同盟
	char transaction[128];//取引
	char characteristic[128];
	char block[128];//取引ブロック
};

//一行128文字まで(全キャラクター共通の本拠地説明)
struct STRING_DATA_HEADQUARTERS_INFOMAITON
{
	char main_title[128];
	
};

//一行64文字まで(全キャラクター共通のファクションの詳細説明)
struct STRING_DATA_FACTION_TAB_INSTRUCTIONS
{
	char branch_point[64];
	char laboratory[64];
	char money[64];
	char research[64];
	char study[64];
	char characteristic[64];
	char block[64];
	char seasons[64];
	char small_seasons[64];
	char years[64];
	char hostility[64];
	char friendship[64];
	char alliance[64];
	char transaction[64];
};

//一行64文字まで(全キャラクター共通のコネクトモード説明)
struct STRING_DATA_CONNECTION_MODE_INFOMAITON
{
	char main_title[64];

};
