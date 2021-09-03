#pragma once
#include <string>
#include <vector>
#include <iostream> 
#include <fstream>
#include <sstream>
#include <limits>
#include "DxLib.h"


class DiploidEngineFile
{
private:
	std::ifstream file_in;//�ǂݍ��ݗp
	std::ofstream file_out;//�������ݗp


public:

	//�t�@�C���ǂݍ��ݎ��Ƀt�@�C�������������ꍇ�A�����I�ɍ쐬����܂��B
	void ReadOpen(const char* path, unsigned int in_mode = std::ios::in);//1�ȏ�Ԃ�Ɛ���(�t�@�C���n���h����Ԃ�)(mode��fstream�Q��)(�V�K�t�@�C���쐬���̃t�@�C���I�[�v�����[�h��trunc)
	void WriteOpen(const char* path, unsigned int out_mode = std::ios::out);

	std::string GetLine();//�t�@�C������1�s�����ǂݏo���B(��s�����Ȃ̂�for���Ƃ��ŘA�����ēǂݏo���K�v����)(�t�@�C���I�[�܂œǂݏo�����ꍇ�A�����œǂݍ��ݑ���fstream��close���܂��B)
	void SetLine(const char* name, float data);//�f�[�^=���l�Ƃ����\�L�ŏo�͂���܂��B
	void SetLine(const char* name, int data);//�f�[�^=���l�Ƃ����\�L�ŏo�͂���܂��B
	void SetLine(const char* name, bool data);//�f�[�^=���l�Ƃ����\�L�ŏo�͂���܂��B

	void Close();//�ǂݍ��ݗp�Ə������ݗp�̃t�@�C���X�g���[������܂��B(�t�@�C����������������炱�̊֐����g���ăt�@�C������Ă�������)
	void FileInClose();//�ǂݍ��ݗp�̃t�@�C���X�g���[������܂��B
	void FileOutClose();//�������ݗp�̃t�@�C���X�g���[������܂��B

	std::ifstream& GetFileInAdr();
	std::ofstream& GetFileOutAdr();

};

//DiploidTranslate.cpp�ɋL�q
class DiploidTranslate
{
private:

public:
	bool Find(std::string& string_data, std::string string_name);//string_data�ɂ͒��ׂ镶����f�[�^�Astring_name�ɂ͒T������������B�����񂪌���������true��Ԃ��B
	bool Find(std::vector<std::string>& string_data, std::string string_name);//��L�֐���vector�z��Ή���

	float FindDataFloat(std::string& string_data, std::string string_name);//string_data����string_name�ɑΉ����鐔�l���擾���܂��B(string_name=�Z�Z�`���́����������擾)
	int FindDataInt(std::string& string_data, std::string string_name);//string_data����string_name�ɑΉ����鐔�l���擾���܂��B(string_name=�Z�Z�`���́����������擾)
	bool FindDataBool(std::string& string_data, std::string string_name);//string_data����string_name�ɑΉ����鐔�l���擾���܂��B(string_name=�Z�Z�`���́����������擾)

	float FindDataFloat(std::vector<std::string>& string_data, std::string string_name);//string_data����string_name�ɑΉ����鐔�l���擾���܂��B(string_name=�Z�Z�`���́����������擾)
	int FindDataInt(std::vector<std::string>& string_data, std::string string_name);//string_data����string_name�ɑΉ����鐔�l���擾���܂��B(string_name=�Z�Z�`���́����������擾)
	bool FindDataBool(std::vector<std::string>& string_data, std::string string_name);//string_data����string_name�ɑΉ����鐔�l���擾���܂��B(string_name=�Z�Z�`���́����������擾)

	void SplitString(std::string string_data, std::string& first, std::string& second);//�u=�v�Ōq����string_data��=��ŕ������Afirst��second�Ŏ擾���܂��B
	void SplitStringMulti(std::string string_data, std::string& first, std::string& second, std::string& three);//�u=�v�Ōq����string_data��=��ŕ������Afirst��second��three�Ŏ擾���܂��B

};