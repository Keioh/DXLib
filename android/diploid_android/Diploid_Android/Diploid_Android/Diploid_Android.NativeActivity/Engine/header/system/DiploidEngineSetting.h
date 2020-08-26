//			DXLIB�֘A�̐ݒ��������N���X
//
//
//

#pragma once
#include "DxLib.h"
#include "diploidScreen/DiploidEngineAndroidScreen.h"

class DiploidEngineSetting
{
private:
	DiploidEngineAndroidScreen android_screen;//Android�f�o�C�X�̃f�B�X�v���C�X�e�[�^�X�m�F

public:
	DiploidEngineSetting();

	int window_x, window_y, window_bit, refresh_rate;//�E�B���h�E�T�C�Y�ƃ��t���b�V�����[�g
	int window_mode;//TRUE�ŃE�B���h�E���[�h
	const char* window_name;//�A�v���P�[�V�����̖��O

	void Init();//DxLib�����������B�������Ɏ��s(-1)�����ꍇ�̓A�v���P�[�V�������I�����܂��B
	void SetBegin();//DxLib�������������O�ɐݒ肷�鍀�ځB
	void SetEnd();//DxLib������������ɐݒ肷�鍀�ځB
	void End();//�Q�[���I��������Ƃ��ɌĂ�DxLib�I�������B
};