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

	void FileOpen_Config();//設定ファイル読み込み

	void FileWrite_Config();//設定ファイル書き込み

};