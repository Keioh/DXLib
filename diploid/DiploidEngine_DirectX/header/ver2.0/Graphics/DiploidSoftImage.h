#pragma once
#include <vector>
#include "DxLib.h"
#include  "ver2.0/Graphics/DiploidBoxV2.h"
#include  "ver2.0/Graphics/DiploidCircleV2.h"

//����JPEG�̂�
class DiploidSoftImage
{
private:
	int soft_handle, graphics_handle, div_graphics_handle;//�n���h��
	int graphics_size_x, graphics_size_y;//�摜�T�C�Y
	std::vector<DiploidBoxV2> image_box;

public:
	void Load(const char* path);

	int GetGraphicsHandle();//�ꖇ�̉摜�Ƃ��Ẵn���h���𓾂�B

	void CreatSoftImage(float x = 1, float y = 1);//BOX��p���ĕ`�悷��ۂ̃f�[�^���쐬���܂��B(x,y�ɂ͂P�h�b�g�̑傫�����w��,resize��1�ȏ���w��)

	void SetPixelSize(float x, float y);//�`��Ŏg�p���Ă���BOX�̑傫����ύX���܂��B(�񐄏�)
	void SetPosition(VECTOR pos);
	void SetFill(bool fill);

	void Draw(bool debug = false);//GPU�o�R�ŕ`�悵�܂��B(������)
	void SoftwareDraw(bool debug = false);//BOX��p���ĕ`�悵�܂��B

};

