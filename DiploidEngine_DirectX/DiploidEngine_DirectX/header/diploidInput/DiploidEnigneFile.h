#pragma once
#include <fstream>
#include "DxLib.h"


class DiploidEngineFile
{
private:
	std::ifstream input_file;//����
	std::ofstream output_file;//�o��

	int file_handl;//�t�@�C���n���h��

public:


	int Craete(const char* path);//�t�@�C�������B�����ꏊ�Ɩ��O�ł��̊֐����g�p����Ɣ����Ō��t�@�C�����㏑������܂�(1���Ԃ�Ɛ���)
	int Load(const char* path);//1�ȏ�Ԃ�Ɛ���(�t�@�C���n���h����Ԃ�)
	int Write(const char* path);//1�ȏ�Ԃ�Ɛ���
};