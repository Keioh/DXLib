#pragma once
#include <vector>
#include "diploidObject\DiploidEngineObject.h"

#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidPoint.h"

class DiploidEngineImpact
{
private:
	std::vector<DiploidCircle> circle_vector;//円を保存しておく配列
	std::vector<DiploidPoint> point_vector;//点を保存しておく配列

	void ImpactCirclePoint();//円と点の当たり判定処理

public:

	void PushCircle(DiploidCircle circle);//円を円配列にプッシュします。
	void PushPoint(DiploidPoint point);//点を点配列にプッシュします。

	void Updata();
	void Draw(bool wire = true);
};