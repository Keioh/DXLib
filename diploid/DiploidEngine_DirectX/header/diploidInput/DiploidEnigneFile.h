#pragma once
#include <string>
#include <vector>
#include <iostream> 
#include <fstream>
#include "DxLib.h"

class DiploidEngineFile
{
private:
	std::fstream file_in;//�ǂݍ��ݗp
	std::ofstream file_out;//�������ݗp

public:

	//�t�@�C���ǂݍ��ݎ��Ƀt�@�C�������������ꍇ�A�����I�ɍ쐬����܂��B
	void Load(const char* path, unsigned int in_mode = std::ios::in, unsigned int out_mode = std::ios::trunc);//1�ȏ�Ԃ�Ɛ���(�t�@�C���n���h����Ԃ�)(mode��fstream�Q��)(�V�K�t�@�C���쐬���̃t�@�C���I�[�v�����[�h��trunc)

	std::string GetLine();//�t�@�C������1�s�����ǂݏo���B(��s�����Ȃ̂�for���Ƃ��ŘA�����ēǂݏo���K�v����)(�t�@�C���I�[�܂œǂݏo�����ꍇ�A�����œǂݍ��ݑ���fstream��close���܂��B)
	void SetLine(std::string name, float data);//�f�[�^=���l�Ƃ����\�L�ŏo�͂���܂��B

	void Close();//�ǂݍ��ݗp�Ə������ݗp�̃t�@�C���X�g���[������܂��B(�t�@�C����������������炱�̊֐����g���ăt�@�C������Ă�������)
	void FileInClose();//�ǂݍ��ݗp�̃t�@�C���X�g���[������܂��B
	void FileOutClose();//�������ݗp�̃t�@�C���X�g���[������܂��B
};