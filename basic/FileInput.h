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


class Filer
{
private:

public:
	~Filer(){};		//�f�X�g���N�^

	FILE *fp;
	FILER_S F_B;

	void FileOpen_Config();//�ݒ�t�@�C��

};