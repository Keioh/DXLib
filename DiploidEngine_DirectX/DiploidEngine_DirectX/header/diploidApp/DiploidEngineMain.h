//���̃t�@�C���ł��ׂĂ̏������܂Ƃ߂�DiploidEngineApp�ɓn��

#pragma once
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidObject\DiploidEngineTag.h"
#include "diploidImpact\DiploidEngineImpact.h"
#include "diploidLayer\DiploidEngineLayer.h"
#include "diploidNetwork\DiploidEngineNetwork.h"
#include "diploidSound\diploidEnigneSound.h"

class DiploidEngineMain
{
private:

	void LayerTOP_ImapctBOX_Sync();//�l�p�ƃ��C���[TOP�̏���
	void LayerMID_ImapctBOX_Sync();//�l�p�ƃ��C���[MID�̏���
	void LayerBOT_ImapctBOX_Sync();//�l�p�ƃ��C���[BOT�̏���

	void LayerTOP_ImapctCIRCLE_Sync();//�~�ƃ��C���[TOP�̏���
	void LayerMID_ImapctCIRCLE_Sync();//�~�ƃ��C���[MID�̏���
	void LayerBOT_ImapctCIRCLE_Sync();//�~�ƃ��C���[BOT�̏���

public:	

	DiploidEngineTag diploidEngineTag;//�^�O���Ŏg�p

	DiploidEngineSound diploidEngineSound;//���֘A

	DiploidEngineSetting diploidEngineSetting;//�G���W����������ݒ�Ȃǂ̏����B
	DiploidEngineLayer diploidEngineLayer;//���C���[�V�X�e������
	DiploidEngineImpact diploidEngineImpact;//�Փˏ���
	DiploidEngineNetwork diploidEngineNetwork;//�l�b�g���[�N�@�\����

	//�ȉ��A�悭�g���ϐ����֐��Ƃ��ēo�^
	VECTOR WindowSize();//window�T�C�Y���擾(z�l��BIT)

	void DestorySync();//��:�Փˏ����ƃ��C���[�����̍폜��������(�Ȃ��Ȃ�֐���������Ȃ�)
};