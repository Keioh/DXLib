//			DXLIB�֘A�̐ݒ��������N���X
//
//
//

#pragma once
#include <vector>
#include <string>
#include "DxLib.h"
#include "diploidInput/DiploidEnigneFile.h"
#include "data/system_data/system_data.h"

using namespace std;

class DiploidEngineSetting
{
private:
	bool reload = false;//�����[�hflag(��ʃT�C�Y�ύX�������Ƃ��ɕω�)

	DiploidEngineFile file;
	DiploidTranslate translate;
	vector<string> string_data;

	SystemData system_data{};

public:
	DiploidEngineSetting();

	int buffer_window_x, buffer_window_y, buffer_window_bit;
	//int window_x, window_y, refreshrate;//�E�B���h�E�T�C�Y�ƃ��t���b�V�����[�g
	//int window_mode;//TRUE�ŃE�B���h�E���[�h
	int window_bit;
	const char* window_name;//�A�v���P�[�V�����̖��O
	//bool vsync;

	int screen_handle;
	//int simulation_window_x, simulation_window_y;//���z�E�B���h�E�T�C�Y

	int exit = 0;//�I���t���O(1�ɂȂ����烁�C����while�𔲂���)


	void Init();//DxLib�����������B�������Ɏ��s(-1)�����ꍇ�̓A�v���P�[�V�������I�����܂��B
	void SetBegin();//DxLib�������������O�ɐݒ肷�鍀�ځB
	void SetEnd();//DxLib������������ɐݒ肷�鍀�ځB
	void End();//�Q�[���I��������Ƃ��ɌĂ�DxLib�I�������B

	void Updata();

	void SetExit(int flag);//�I���t���O��ݒ肷��B
	void SetWindowSize(int new_window_x, int new_window_y);

	int GetExit();//�I���t���O���擾����B

	bool GetReloadFlag();//�ēx�摜��ǂݍ���flag���擾����B
	void SetReloadFlag(bool new_flag);//�ēx�摜��ǂݍ���flag��ύX����B

	SystemData GetSystemData();//���݂̐ݒ���擾���܂��B
};