//�I�u�W�F�N�g�܂Ƃ�

#pragma once
#include "DxLib.h"
#include "diploidGraphics\diploidBox.h"
#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidPoint.h"
#include "diploidGraphics\diploidLine.h"
#include "diploidGraphics\diploidImage.h"
#include "diploidSound\diploidEnigneSound.h"
#include "diploidInput\DiploidEngineInput.h"
#include "diploidInput\DiploidEnigneFile.h"

class DiploidObject
{
private:

public:
	DiploidBox box;//�l�p
	DiploidCircle circle;//�~
	DiploidPoint point;//�_
	DiploidLine line;//����

	DiploidImage image;//�摜

	DiploidEngineSound sound;//��
	
	DiploidEngineFile file;//�t�@�C�����o��

	DiploidEngineInput input;//���͋@��L�[�{�[�h��}�E�X�A�p�b�h�Ȃ�(App�̂ق��Ŏg�����ق������ʂȃ�����������Ȃ��ł��ށB�V���O���g���������Ȃ����)

	void Init();
	void Updata();
	void Draw(bool debug = true);

};