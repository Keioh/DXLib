#pragma once
#include "DxLib.h"
#include "diploidGraphics\diploidImage.h"

class DiploidImage
{
private:

public:
	int handl;
	VECTOR position;

	void Load(const char* path);//�摜�ǂݍ���
	void Init(VECTOR pos);//�����ʒu
	void Updata();//�ʒu��A�j���[�V�����Ȃǂ̍X�V(�܂��ɍ��W�ړ�)
	void Draw(bool draw = true);//�摜��\��
};