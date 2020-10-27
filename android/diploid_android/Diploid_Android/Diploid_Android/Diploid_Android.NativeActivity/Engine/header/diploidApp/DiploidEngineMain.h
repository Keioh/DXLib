//���̃t�@�C���ł��ׂĂ̏�����܂Ƃ߂�DiploidEngineApp�ɓn��

#pragma once
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidObject\DiploidEngineTag.h"
#include "diploidImpact\DiploidEngineImpact.h"
#include "diploidLayer\DiploidEngineLayer.h"
#include "diploidNetwork\DiploidEngineNetwork.h"
#include "diploidSound\diploidEnigneSound.h"
#include "diploidScreen\DiploidEngineScreen.h"
#include "diploidInput\DiploidEngineInput.h"
#include "diploidInput\DiploidEnigneFile.h"


class DiploidEngineMain
{
private:

	void LayerTOP_ImapctBOX_Sync();//�l�p�ƃ��C���[TOP�̏���
	void LayerMID_ImapctBOX_Sync();//�l�p�ƃ��C���[MID�̏���
	void LayerBOT_ImapctBOX_Sync();//�l�p�ƃ��C���[BOT�̏���
	void LayerUI_ImapctBOX_Sync();//�l�p�ƃ��C���[UI�̏���

	void LayerTOP_ImapctCIRCLE_Sync();//�~�ƃ��C���[TOP�̏���
	void LayerMID_ImapctCIRCLE_Sync();//�~�ƃ��C���[MID�̏���
	void LayerBOT_ImapctCIRCLE_Sync();//�~�ƃ��C���[BOT�̏���
	void LayerUI_ImapctCIRCLE_Sync();//�~�ƃ��C���[UI�̏���

	void LayerTOP_ImapctPOINT_Sync();//�_�ƃ��C���[TOP�̏���
	void LayerMID_ImapctPOINT_Sync();//�_�ƃ��C���[MID�̏���
	void LayerBOT_ImapctPOINT_Sync();//�_�ƃ��C���[BOT�̏���
	void LayerUI_ImapctPOINT_Sync();//�_�ƃ��C���[UI�̏���

	void LayerTOP_ImapctLINE_Sync();//�����ƃ��C���[TOP�̏���
	void LayerMID_ImapctLINE_Sync();//�����ƃ��C���[MID�̏���
	void LayerBOT_ImapctLINE_Sync();//�����ƃ��C���[BOT�̏���
	void LayerUI_ImapctLINE_Sync();//�����ƃ��C���[UI�̏���


public:	

	DiploidEngineTag diploidEngineTag;//�^�O���Ŏg�p

	DiploidEngineSound diploidEngineSound;//���֘A

	DiploidEngineInput diploidEngineInput;//�L�[���͂ƃ}�E�X���͂ƃW���C�p�b�g���͊֘A

	DiploidEngineScreen diploidEngineScreen;//FPS�J�E���^��Ȃǃt���[���֘A

	DiploidEngineSetting diploidEngineSetting;//�G���W����������ݒ�Ȃǂ̏����B
	DiploidEngineLayer diploidEngineLayer;//���C���[�V�X�e������
	DiploidEngineImpact diploidEngineImpact;//�Փˏ���
	DiploidEngineNetwork diploidEngineNetwork;//�l�b�g���[�N�@�\����

	DiploidEngineFile diploidEngineFile;//�t�@�C�����o��

	//�ȉ��A�悭�g���ϐ���֐��Ƃ��ēo�^
	VECTOR GetWindowSize();//window�T�C�Y��擾(z�l��BIT)

	void DestorySync();//��:�Փˏ����ƃ��C���[�����̍폜��������(�Ȃ��Ȃ�֐��������Ȃ�)
};