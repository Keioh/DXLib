#pragma once
#include <string>
#include <vector>
#include <iostream> 
#include <fstream>
#include "DxLib.h"

class DiploidEngineFile
{
private:
	std::ifstream file_in;//����
	std::string strings;
	char buffer[512];

public:
	std::vector<std::string> str_data;
	std::vector<char> data;

	//�o�O
	void Load(const char* path, unsigned int mode = std::ios::in, size_t char_size = 2);//1�ȏ�Ԃ�Ɛ���(�t�@�C���n���h����Ԃ�)(mode��fstream�Q��)

	void Close();//�t�@�C�������(�t�@�C�����������������K�����̊֐����g���ăt�@�C������Ă�������)

};