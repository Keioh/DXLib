#include "GraphicsLoad.h"

int GraphicsLoad::Load(const char* path)
{
	graphics_handl = LoadGraph(path);//�摜��ǂݍ���

	GetGraphSizeF(graphics_handl, &width, &height);//�摜�̑傫�����擾

	return graphics_handl;//�O���t�B�b�N�n���h����Ԃ��B
}