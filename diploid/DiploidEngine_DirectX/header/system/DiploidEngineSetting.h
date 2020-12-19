//			DXLIB�֘A�̐ݒ��������N���X
//
//
//

#pragma once
#include "DxLib.h"

class DiploidEngineSetting
{
private:

public:
	DiploidEngineSetting();

	int window_x, window_y, window_bit, refresh_rate;//�E�B���h�E�T�C�Y�ƃ��t���b�V�����[�g
	int window_mode;//TRUE�ŃE�B���h�E���[�h
	const char* window_name;//�A�v���P�[�V�����̖��O

	int screen_handle;
	int sim_window_x, sim_window_y;//���z�E�B���h�E�T�C�Y

	int exit = 0;//�I���t���O(1�ɂȂ����烁�C����while�𔲂���)

	void Init();//DxLib�����������B�������Ɏ��s(-1)�����ꍇ�̓A�v���P�[�V�������I�����܂��B
	void SetBegin();//DxLib�������������O�ɐݒ肷�鍀�ځB
	void SetEnd();//DxLib������������ɐݒ肷�鍀�ځB
	void End();//�Q�[���I��������Ƃ��ɌĂ�DxLib�I�������B

	void SetExit(int flag);//�I���t���O��ݒ肷��B
	int GetExit();//�I���t���O���擾����B
};