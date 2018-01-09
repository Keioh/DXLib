#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include "Dxlib.h"
#include "struct_set.h"



class Filer
{
private:

public:
	~Filer(){};		//デストラクタ

	FILE *fp;

	SOUND_DATA sound_data;//音に関する設定
	LANGUAGE_DATA language_data;//言語に関する設定
	WINDOW_DATA window_data;//画面に関する設定

	STRING_DATA string_data;//会話などのデータ

	void FileOpen_Config();//設定ファイル読み込み

	void FileWrite_Config();//設定ファイル書き込み

	void FileOpen_Window();//Windowファイル読み込み

	void FileOpen_Language();//言語ファイル読み込み
	void FileOpen_Japanese();//日本語ファイル読み込み
	void FileOpen_English();//英語ファイル読み込み
};