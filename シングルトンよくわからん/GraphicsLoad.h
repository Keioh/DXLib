#pragma once
#include "DxLib.h"

class GraphicsLoad
{
public:
	GraphicsLoad() {};

	int graphics_handl;//�摜�n���h��
	float height;//�摜�̍���
	float width;//�摜�̕�

	int Load(const char* path);//�摜�̓ǂݍ���(�O���t�B�b�N�n���h����Ԃ��B)
};