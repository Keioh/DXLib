#pragma once
#include "DxLib.h"
#include "ObjectVector.h"
#include "define.h"

//�I�u�W�F�N�g�����ۂ̊�{�ɂȂ�L�q
class ObjectBase
{

private:

public:
	~ObjectBase(){};		//�f�X�g���N�^

	//int�|�W�V����
	int x;
	int y;
	int z;

	//int�T�C�Y
	int size_x;
	int size_y;
	int size_z;

	//int���l
	int red_a;
	int green_a;
	int blue_a;

	//float�|�W�V����
	float xF;
	float yF;
	float zF;


};	

struct SEQUENCE
{
	int title_screen;
	int game_screen;
	int load_screen;
	int option_screen;
	int exit_screen;
};