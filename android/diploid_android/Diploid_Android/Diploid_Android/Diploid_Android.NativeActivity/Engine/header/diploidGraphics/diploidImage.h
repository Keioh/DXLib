#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidImage : public DiploidEngineObjectInformation
{
private:
	VECTOR anime_position;
	VECTOR origin_position;
	VECTOR center_position;
	double anime_size;
	double move_size_private;	
	double anime_angle;
	double origin_angle;
	double origin_size;//z�����g�p

	void DrawNameTag();

public:
	int handl = DX_NONE_GRAPH;
	int mouse_x, mouse_y;
	double scale = 1.0f;
	double angle = 0.0f;
	float blend_volume = 255;
	float blend_speed = 0;
	int blend_mode = DX_BLENDMODE_ALPHA;
	int revers_x = FALSE;
	int revers_y = FALSE;
	int GRAPHICS_SIZE_X, GRAPHICS_SIZE_Y;//���̐��l������O�ɃR�s�[������Ă����Ȃ��Ɛ��l��������B
	int red_bright = 255;
	int green_bright = 255;
	int blue_bright = 255;//�摜�̖��邳
	float red_bright_speed = 0.0f;
	float green_bright_speed = 0.0f;
	float blue_bright_speed = 0.0f;
	double move_angle;



	void Load(const char* path);//�摜�ǂݍ���
	void Init(VECTOR pos = { 0.0f,0.0f,0.0f }, double size_scale = 1.0f, double angle_scale = 0.0f);//�����ʒu(size_scale��1�œ��{�A2�œ�{�Ȃ�)
	void Updata();//�ʒu��A�j���[�V�����Ȃǂ̍X�V(�܂��ɍ��W�ړ�)
	void Draw(bool draw = true);//�摜��\��

	int GetGraphicsSizeX();//�ǂݍ��񂾉摜��X�̑傫�����擾���܂��B
	int GetGraphicsSizeY();//�ǂݍ��񂾉摜��Y�̑傫�����擾���܂��B

	void TransformScale(float scale = 1.0f);//�T�C�Y�X�P�[����ύX����B

	int SetDrawNameTagFlag(int flag = FALSE);//TRUE��name_tag��\���B
	std::string GetNameTag();//name_tag�ɐݒ肳��Ă��閼�O��Ԃ��܂��B

};