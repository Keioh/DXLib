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
	LANGUAGE_DATA language_data;//����Ɋւ���ݒ�
	WINDOW_DATA window_data;//��ʂɊւ���ݒ�

	STRING_DATA string_data;//��b�Ȃǂ̃f�[�^

	void FileOpen_Config();//�ݒ�t�@�C���ǂݍ���

	void FileWrite_Config();//�ݒ�t�@�C����������

	void FileOpen_Window();//Window�t�@�C���ǂݍ���

	void FileOpen_Language();//����t�@�C���ǂݍ���
	void FileOpen_Japanese();//���{��t�@�C���ǂݍ���
	void FileOpen_English();//�p��t�@�C���ǂݍ���
};