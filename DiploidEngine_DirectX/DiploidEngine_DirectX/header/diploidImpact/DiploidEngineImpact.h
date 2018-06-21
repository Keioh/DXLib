#pragma once
#include <vector>
#include <algorithm>
#include "diploidObject\DiploidEngineObject.h"

#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidPoint.h"
#include "diploidGraphics\diploidBox.h"

class DiploidEngineImpact
{
private:
	std::vector<DiploidCircle> circle_vector;//�~��ۑ����Ă����z��
	std::vector<DiploidPoint> point_vector;//�_��ۑ����Ă����z��
	std::vector<DiploidBox> box_vector;//�l�p��ۑ����Ă����z��

	float circle_byte;
	float point_byte;
	float box_byte;
	int circle_size;
	int point_size;
	int box_size;

public:

	void GetSize();//�e�z��̑傫�����擾

	void PushCircle(DiploidCircle circle);//�~���~�z��Ƀv�b�V�����܂��B
	void PushPoint(DiploidPoint point);//�_��_�z��Ƀv�b�V�����܂��B(�_�͎�Ƀ}�E�X�|�C���g�Ɏg�p���Ă�������)
	void PushBox(DiploidBox box);//�l�p���l�p�z��Ƀv�b�V�����܂��B(�l�p��UI�ɂ̂ݎg�p���Ă�������)

	void PopBackCircle();//�~����Ԍ��̔z�񂩂�폜���܂��B
	void PopBackPoint();//�_����Ԍ��̔z�񂩂�폜���܂��B
	void PopBackBox();//�l�p����Ԍ��̔z�񂩂�폜���܂��B

	void DestoryCircle();//�~���q�b�g���Ă�����~�z�񂩂�폜
	void DestoryPoint();//�_���q�b�g���Ă�����_�z�񂩂�폜
	void DestoryBox();//�l�p���q�b�g���Ă�����l�p�z�񂩂�폜

	void Destory();//�z�񂩂�폜

	void Init();//������

	void Updata();//�Փ˔��菈��

	//Updata()���g���ď���������ꍇ�͈ȉ��̊֐����g�p���Ȃ��B
	void ImpactCirclePoint();//�~�Ɠ_�̓����蔻�菈��
	void ImpactCircleCircle();//�~�Ɖ~�̓����蔻�菈��
	void ImpactBoxPoint();//�l�p�Ɠ_�̓����蔻�菈��
	void ImpactBoxBox();//�l�p�Ǝl�p�̓����蔻�菈��(������)

	void Draw(bool wire = true);//�`��
};