#pragma once
#include <vector>
#include "DxLib.h"
#include  "ver2.0/Graphics/DiploidBoxV2.h"
#include  "ver2.0/Graphics/DiploidImageV2.h"
#include  "ver2.0/Graphics/DiploidCircleV2.h"

class SoftImageData
{
public:
	int r;
	int g;
	int b;
	int a;

	VECTOR pos;
	VECTOR size;

	int soft_handle;
	int image_handle;
};

class DiploidSoftImage
{
private:
	int soft_handle, graphics_handle, div_graphics_handle;//�n���h��
	int graphics_size_x, graphics_size_y;//�摜�T�C�Y
		
	int r, g, b, a;//�s�N�Z���̐F���

	float scale_x = 1.0f, scale_y = 1.0f, angle = 0.0f;//�摜�P���P���̃X�P�[���Ɗp�x

	SoftImageData data_buffer;
	DiploidBoxV2 box;

	std::vector<SoftImageData> data;
	std::vector<DiploidBoxV2> image_box;


	std::vector<SoftImageData> screen_0, screen_1, screen_2, screen_3;

public:
	void Load(const char* path);

	int GetGraphicsHandle();//�ꖇ�̉摜�Ƃ��Ẵn���h���𓾂�B

	void CreatSoftImage(float x = 1, float y = 1);//BOX��p���ĕ`�悷��ۂ̃f�[�^���쐬���܂��B(x,y�ɂ͂P�h�b�g�̑傫�����w��,resize��1�ȏ���w��)
	void CreatGraphicsImage(int x = 1, int y = 1);//Image��p���ĕ`�悷��ۂ̃f�[�^���쐬���܂��B(x,y�ɂ͂P�h�b�g�̑傫�����w��,resize��1�ȏ���w��)


	void SetSoftPixelSize(float x, float y);//�`��Ŏg�p���Ă���BOX�̑傫����ύX���܂��B(�񐄏�)
	void SetSoftPosition(VECTOR pos);
	void SetSoftFill(bool fill);
	void SetSoftThickness(float thickness);

	void SetGraphicsScale(float x, float y);

	void Draw(bool debug = false);//GPU�o�R�ŕ`�悵�܂��B(������)
	void SoftwareDraw(bool debug = false);//BOX��p���ĕ`�悵�܂��B
	void GraphicsDraw(bool debug = false);//DrawGraph��p���ĕ`�悵�܂��B

	void SoftImageDelet();
};

