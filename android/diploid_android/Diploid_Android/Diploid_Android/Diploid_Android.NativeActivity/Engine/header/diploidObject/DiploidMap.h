//�z���map�ł͂Ȃ��A�摜����Q�[���}�b�v��쐻���邽�߂̃N���X�ł��B

#pragma once
#include <list>
#include "DxLib.h"


struct MAP_DATA
{
	float x;
	float y;

	int red;
	int green;
	int blue;
	int alph;

	int size;
};

class DiploidMap
{
private:
	float map_moved_x, map_moved_y;

public:
	int handl;
	int Width, Height;//�摜�̏c�Ɖ��̑傫��

	int MAP_SIZE = 2;//�}�b�v�`�b�v�̑傫����w�肵�܂��B(1�h�b�g�P��)

	float position_x = 0.0f, position_y = 0.0f;

	std::list<MAP_DATA> MAP;

	void SetMapChipSize(int size = 4);//�}�b�v�`�b�v�̑傫������Ă�
	void SetPosition(float x = 0.0f, float y = 0.0f);//�}�b�v�̏����ʒu��w�肵�܂��B(Create�֐��̑O�Ɏ��s�����Ƃ��������ʂ𔭊����܂�)
	int Load(const char* path, int data_size_x, int data_size_y);//�}�b�v�f�[�^��ǂݍ��݂܂��B
	void Create();//�}�b�v��쐻���܂��B(����Ƃ��Ă�MAP�z���Load�œǂݍ��񂾉摜�̑傫���������c��RBG�ƃ��l��v�b�V���o�b�N���Ă��܂��B)
	void Updata(float move_x, float move_y);//�L�����N�^�[��g���Ĉړ�����Ƃ��Ƀ}�b�v��ړ������܂�(������)
	void Draw(bool wire = false);//�}�b�v�f�[�^����Ƀ}�b�v��`�ʂ��܂�
};