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


	//文字列ファイル関連
	STRING_DATA string_data;//タイトル画面とオプション画面などのデータ

	STRING_DATA_CHARACTER_NAME character_name;//キャラクターの名前

	STRING_DATA_CHARACTER_DESCRIPTION character_description;//キャラクター説明


	STRING_DATA_FACTION_INFOMAITON faction_infomaiton_basic;//全キャラクター共通のファクション説明


	void FileOpen_Config();//設定ファイル読み込み

	void FileWrite_Config();//設定ファイル書き込み

	void FileOpen_Window();//Windowファイル読み込み

	void FileOpen_Language();//言語ファイル読み込み
	void FileOpen_Japanese();//日本語ファイル読み込み
	void FileOpen_English();//英語ファイル読み込み

	void CharacterNameJPN();//日本語ファイル読み込み(キャラクタの名前)
	void CharacterNameENG();//英語ファイル読み込み(キャラクタの説明)

	void CharacterDescriptionJPN();//日本語ファイル読み込み(キャラクタの説明)
	void CharacterDescriptionENG();//英語ファイル読み込み(キャラクタの説明)

	void FactionInfomaitonBasicJPN();//日本語ファイル読み込み(全キャラクター共通のファクション説明)
	void FactionInfomaitonBasicENG();//英語ファイル読み込み(全キャラクター共通のファクション説明)
};