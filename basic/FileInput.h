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
	~Filer(){};		//�f�X�g���N�^

	FILE *fp;

	SOUND_DATA sound_data;//���Ɋւ���ݒ�

	void FileOpen_Config();//�ݒ�t�@�C���ǂݍ���

	void FileWrite_Config();//�ݒ�t�@�C����������

};