#pragma once
#include <vector>
#include "diploidObject\DiploidEngineObject.h"

#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidPoint.h"

class DiploidEngineImpact
{
private:
	std::vector<DiploidCircle> circle_vector;//�~��ۑ����Ă����z��
	std::vector<DiploidPoint> point_vector;//�_��ۑ����Ă����z��

	void ImpactCirclePoint();//�~�Ɠ_�̓����蔻�菈��

	void CircleAnime(float anime_position_x, float anime_position_y, VECTOR size);//�~�̃A�j���[�V�����X�V����(z�l�͔��a)
	void PointAnime(float anime_position_x, float anime_position_y);//�_�̃A�j���[�V�����X�V����

public:

	void PushCircle(DiploidCircle circle);//�~���~�z��Ƀv�b�V�����܂��B
	void PushPoint(DiploidPoint point);//�_��_�z��Ƀv�b�V�����܂��B

	void PopBackCircle();//�~����Ԍ��̔z�񂩂�폜���܂��B
	void PopBackPoint();//�_����Ԍ��̔z�񂩂�폜���܂��B

	void AnimeUpdata(float anime_position_x, float anime_position_y, VECTOR size);//�A�j���[�V���������ׂĂ̍X�V����
	void ImpactUpdata();//�Փ˔��菈��

	void Draw(bool wire = true);//�`��
};