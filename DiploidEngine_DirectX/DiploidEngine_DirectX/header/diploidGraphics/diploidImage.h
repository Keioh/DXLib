#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidImage : public DiploidEngineObjectInformation
{
private:

public:
	int handl;
	int mouse_x, mouse_y;
	double scale = 1.0f;
	double angle = 0.0f;
	int revers_x = FALSE;
	int revers_y = FALSE;
	int GRAPHICS_SIZE_X, GRAPHICS_SIZE_Y;

	VECTOR anime_position;
	VECTOR origin_position;
	VECTOR center_position;
	double anime_size;
	double move_size;	
	double move_angle;
	double anime_angle;
	double origin_angle;
	double origin_size;//z�����g�p


	void Load(const char* path);//�摜�ǂݍ���
	void Init(VECTOR pos = { 0,0,0 }, double size_scale = 1.0f, double angle_scale = 0.0f);//�����ʒu(size_scale��1�œ��{�A2�œ�{�Ȃ�)
	void Updata();//�ʒu��A�j���[�V�����Ȃǂ̍X�V(�܂��ɍ��W�ړ�)
	void Draw(bool draw = true);//�摜��\��
};