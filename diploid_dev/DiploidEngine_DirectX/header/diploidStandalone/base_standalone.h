#pragma once
#include "DxLib.h"
//�X�^���h�A���[�����N���X

class BaseStandalone
{
private:

public:
	BaseStandalone();
	~BaseStandalone();

	VECTOR size;		//�I�u�W�F�N�g�̑傫��
	VECTOR position;	//�I�u�W�F�N�g�̈ʒu
	float radius;		//�I�u�W�F�N�g�̔��a
	float scale = 1.0f;		//���݂̃X�P�[���l(1.0f�œ��{)

	bool hit = false;	//�I�u�W�F�N�g�����̃I�u�W�F�N�g�ɓ������Ă��邩�ǂ���(true�̏ꍇ�A�������Ă���)

};