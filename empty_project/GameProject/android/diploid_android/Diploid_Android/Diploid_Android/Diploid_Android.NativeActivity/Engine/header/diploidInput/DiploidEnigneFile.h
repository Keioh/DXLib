#pragma once
#include <fstream>
#include "DxLib.h"

class DiploidEngineFile
{
private:
	std::ifstream input_file;//����
	std::ofstream output_file;//�o��

	std::ifstream json_file;//json�t�@�C���ǂݍ���

public:

	char strings[256];//256�����ۑ�
	int file_handl;//�t�@�C���n���h��

	int Craete(const char* path);//�t�@�C�������B�����ꏊ�Ɩ��O�ł��̊֐����g�p����Ɣ����Ō��t�@�C�����㏑������܂�(1���Ԃ�Ɛ���)
	int Load(const char* path);//1�ȏ�Ԃ�Ɛ���(�t�@�C���n���h����Ԃ�)

	int WriteINT(const char* path, const char* name, int data);//�t�@�C���̖����ɏ������݂������l���Ԃ�
	float WriteFLOAT(const char* path, const char* name, float data);//�t�@�C���̖����ɏ������݂������l���Ԃ�
	void Read(int handl);//�t�@�C�������s�ǂݏo��
	void Close(int handl);//�t�@�C�������(�t�@�C�����������������K�����̊֐����g���ăt�@�C������Ă�������)


	void LoadJSON(const char* path);//1�ȏ�Ԃ�Ɛ���
};