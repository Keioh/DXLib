#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include "Dxlib.h"

struct FILER_S//�R���t�B�O
{
	int host;
	IPDATA ips;
	int port;
	int member;
};

struct FILER_E//�v���[���[
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

	void FileOpen_Config();//�ݒ�t�@�C��
	void FileOpen_Explorer();//�T���҃t�@�C��

};