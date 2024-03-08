//�I�u�W�F�N�g�܂Ƃ�

#pragma once
#include "DxLib.h"
#include "diploidGraphics\diploidBox.h"
#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidPoint.h"
#include "diploidGraphics\diploidLine.h"
#include "diploidGraphics\diploidPanel.h"
#include "diploidGraphics\diploidImage.h"
#include "diploidSound\diploidEnigneSound.h"
#include "diploidInput\DiploidEngineInput.h"
#include "diploidInput\DiploidEnigneFile.h"
#include "diploidObject\DiploidMap.h"
#include "diploidPhysics/diploidPhysics.h"
#include "diploidObject/DiploidEngineTag.h"

class DiploidObject
{
private:

public:
	DiploidBox box;//�l�p
	DiploidCircle circle;//�~
	DiploidPoint point;//�_
	DiploidLine line;//����
	DiploidPanel panel;//�p�l��(2�|���S����3D)

	DiploidImage image;//�摜

	DiploidEngineSound sound;//��
	
	DiploidEngineFile file;//�t�@�C�����o��
	DiploidMap map;//�}�b�v�쐻

	Tag tag;//�^�O���̍쐬(App�ɂ���diploidEngineTag��Push�֐��ɑ��)
	DiploidEngineTag tag_system;//�^�O�V�X�e���̍쐬(App�ɂ���diploidEngineTag�Ƃ͕ʂɐV�����V�X�e�����쐬�������ꍇ�Ɏg�p)

	DiploidEngineInput input;//���͋@��L�[�{�[�h��}�E�X�A�p�b�h�Ȃ�(App�̂ق��Ŏg�����ق������ʂȃ�����������Ȃ��ł��ށB�V���O���g���������Ȃ����)

	DiploidPhysics physics;//�����v�Z


	void Init();
	void Updata();
	void Draw(bool debug = true);

};