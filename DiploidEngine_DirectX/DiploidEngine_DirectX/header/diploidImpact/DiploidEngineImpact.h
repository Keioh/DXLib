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

	void CircleAnime(float anime_position_x, float anime_position_y, VECTOR size);//円のアニメーション更新処理(z値は半径)
	void PointAnime(float anime_position_x, float anime_position_y);//点のアニメーション更新処理

public:

	void PushCircle(DiploidCircle circle);//円を円配列にプッシュします。
	void PushPoint(DiploidPoint point);//点を点配列にプッシュします。

	void PopBackCircle();//円を一番後ろの配列から削除します。
	void PopBackPoint();//点を一番後ろの配列から削除します。

	void AnimeUpdata(float anime_position_x, float anime_position_y, VECTOR size);//アニメーションをすべての更新処理
	void ImpactUpdata();//衝突判定処理

	void Draw(bool wire = true);//描写
};