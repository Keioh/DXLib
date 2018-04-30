#pragma once
#include <vector>
#include <algorithm>
#include "diploidObject\DiploidEngineObject.h"

#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidPoint.h"

class DiploidEngineImpact
{
private:
	std::vector<DiploidCircle> circle_vector;//�~��ۑ����Ă����z��
	std::vector<DiploidPoint> point_vector;//�_��ۑ����Ă����z��


public:

	void PushCircle(DiploidCircle circle);//�~���~�z��Ƀv�b�V�����܂��B
	void PushPoint(DiploidPoint point);//�_��_�z��Ƀv�b�V�����܂��B(�_�͎�Ƀ}�E�X�|�C���g�Ɏg�p���Ă�������)

	void PopBackCircle();//�~����Ԍ��̔z�񂩂�폜���܂��B
	void PopBackPoint();//�_����Ԍ��̔z�񂩂�폜���܂��B

	void DestoryCircle();//�~���q�b�g���Ă�����~�z�񂩂�폜

	void Init();//������

	void Updata();//�Փ˔��菈��

	//Updata()���g���ď���������ꍇ�͈ȉ��̊֐����g�p���Ă͂����Ȃ��B
	void ImpactCirclePoint();//�~�Ɠ_�̓����蔻�菈��
	void ImpactCircleCircle();//�~�Ɖ~�̓����蔻�菈��

	void Draw(bool wire = true);//�`��
};