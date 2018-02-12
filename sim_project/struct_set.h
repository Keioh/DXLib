#pragma once
#include <string.h>

using namespace std;

struct SOUND_DATA//���Ɋւ�����
{
	int bgm_volume;
	int se_volume;
	int bgm_mute;
	int se_mute;
};

struct WINDOW_DATA
{
	int windowX;
	int windowY;
	int windowBit;
	int fullscreen;
};

struct LANGUAGE_DATA
{
	int japanese_flag;
	int english_flag;
};

//��s�P�Q�W�����܂�(�^�C�g����ʁA�I�v�V������ʂ̐���)
struct STRING_DATA
{
	char bgm_volume[128];
	char se_volume[128];
	char start_info_new_game[128];
	char start_info_load[128];
	char start_info_option[128];
	char start_info_exit[128];
};

//��s�P�Q�W�����܂�(�L�����N�^�̖��O)
struct STRING_DATA_CHARACTER_NAME
{
	char charcter_name_0[128];
	char charcter_name_1[128];
	char charcter_name_2[128];
	char charcter_name_3[128];
};

//��s256�����܂�(�L�����N�^����)
struct STRING_DATA_CHARACTER_DESCRIPTION
{
	char charcter_0[256];
	char charcter_1[256];
	char charcter_2[256];
	char charcter_3[256];	
};

//��s128�����܂�(//�S�L�����N�^�[���ʂ̃t�@�N�V��������)
struct STRING_DATA_FACTION_INFOMAITON
{
	char main_title[128];//�^�u�̖��O
	char branch_point[128];
	char laboratory[128];
	char money[128];
	char research[128];//������
	char study[128];//�׋���
	char seasons[128];//�G��
	char small_seasons[128];//�ߋG
	char years[128];
	char hostility[128];//�G��
	char friendship[128];//�F�D
	char alliance[128];//����
	char transaction[128];//���
	char characteristic[128];
	char block[128];//����u���b�N
};
