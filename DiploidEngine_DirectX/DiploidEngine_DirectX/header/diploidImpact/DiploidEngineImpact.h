#pragma once
#include <vector>
#include <algorithm>
#include "diploidObject\DiploidEngineObject.h"

#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidPoint.h"

class DiploidEngineImpact
{
private:
	std::vector<DiploidCircle> circle_vector;//円を保存しておく配列
	std::vector<DiploidPoint> point_vector;//点を保存しておく配列

	void ImpactCirclePoint();//円と点の当たり判定処理
	void ImpactCircleCircle();//円と円の当たり判定処理

public:

	void PushCircle(DiploidCircle circle);//円を円配列にプッシュします。
	void PushPoint(DiploidPoint point);//点を点配列にプッシュします。(点は主にマウスポイントに使用してください)

	void PopBackCircle();//円を一番後ろの配列から削除します。
	void PopBackPoint();//点を一番後ろの配列から削除します。

	void DestoryCircle();//円がヒットしていたら円配列から削除

	void Init();//初期化

	void Updata();//衝突判定処理

	void Draw(bool wire = true);//描写
};