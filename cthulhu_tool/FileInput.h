#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include "Dxlib.h"

struct FILER_S//コンフィグ
{
	int host;
	IPDATA ips;
	int port;
	int member;
};

struct FILER_E//プレーヤー
{
	int str;
	int con;
	int pow;
	int dex;
	int app;
	int siz;
	int inte;
	int edu;
};

class Filer
{
private:

public:
	Filer();

	FILE *fp;
	FILER_S F_B;
	FILER_E F_E;

	void FileOpen_Config();//設定ファイル
	void FileOpen_Explorer();//探索者ファイル

};