//���̃t�@�C���ł��ׂĂ̏������܂Ƃ߂�DiploidEngineApp�ɓn��

#pragma once
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidImpact\DiploidEngineImpact.h"
#include "diploidLayer\DiploidEngineLayer.h"
#include "diploidNetwork\DiploidEngineNetwork.h"

class DiploidEngineMain
{
private:

public:
	DiploidEngineSetting diploidEngineSetting;//�G���W����������ݒ�Ȃǂ̏����B
	DiploidEngineLayer diploidEngineLayer;//���C���[�V�X�e������
	DiploidEngineImpact diploidEngineImpact;//�Փˏ���
	DiploidEngineNetwork diploidEngineNetwork;//�l�b�g���[�N�@�\����

	//�ȉ��A�悭�g���ϐ����֐��Ƃ��ēo�^
	VECTOR WindowSize();//window�T�C�Y���擾(z�l��BIT)
};