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

public:

	void PushCircle(DiploidCircle circle);//�~���~�z��Ƀv�b�V�����܂��B
	void PushPoint(DiploidPoint point);//�_��_�z��Ƀv�b�V�����܂��B

	void Updata();
	void Draw(bool wire = true);
};