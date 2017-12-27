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


class Filer
{
private:

public:
	~Filer(){};		//デストラクタ

	FILE *fp;
	FILER_S F_B;

	void FileOpen_Config();//設定ファイル

};