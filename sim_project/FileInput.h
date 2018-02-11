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


	//������t�@�C���֘A
	STRING_DATA string_data;//�^�C�g����ʂƃI�v�V������ʂȂǂ̃f�[�^

	STRING_DATA_CHARACTER_NAME character_name;//�L�����N�^�[�̖��O

	STRING_DATA_CHARACTER_DESCRIPTION character_description;//�L�����N�^�[����


	STRING_DATA_FACTION_INFOMAITON faction_infomaiton_basic;//�S�L�����N�^�[���ʂ̃t�@�N�V��������


	void FileOpen_Config();//�ݒ�t�@�C���ǂݍ���

	void FileWrite_Config();//�ݒ�t�@�C����������

	void FileOpen_Window();//Window�t�@�C���ǂݍ���

	void FileOpen_Language();//����t�@�C���ǂݍ���
	void FileOpen_Japanese();//���{��t�@�C���ǂݍ���
	void FileOpen_English();//�p��t�@�C���ǂݍ���

	void CharacterNameJPN();//���{��t�@�C���ǂݍ���(�L�����N�^�̖��O)
	void CharacterNameENG();//�p��t�@�C���ǂݍ���(�L�����N�^�̐���)

	void CharacterDescriptionJPN();//���{��t�@�C���ǂݍ���(�L�����N�^�̐���)
	void CharacterDescriptionENG();//�p��t�@�C���ǂݍ���(�L�����N�^�̐���)

	void FactionInfomaitonBasicJPN();//���{��t�@�C���ǂݍ���(�S�L�����N�^�[���ʂ̃t�@�N�V��������)
	void FactionInfomaitonBasicENG();//�p��t�@�C���ǂݍ���(�S�L�����N�^�[���ʂ̃t�@�N�V��������)
};