#pragma once
#include <vector>
#include <algorithm>
#include "diploidObject\DiploidEngineObject.h"
#include "system\DiploidEngineMath.h"

#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidPoint.h"
#include "diploidGraphics\diploidBox.h"
#include "diploidGraphics\diploidLine.h"

class DiploidEngineImpact
{
private:
	DiploidEngineMath math;

	float circle_byte;
	float point_byte;
	float box_byte;
	float line_byte;

	int circle_size;
	int point_size;
	int box_size;
	int line_size;

public:
	std::vector<DiploidCircle> circle_vector;//円を保存しておく配列
	std::vector<DiploidPoint> point_vector;//点を保存しておく配列
	std::vector<DiploidBox> box_vector;//四角を保存しておく配列
	std::vector<DiploidLine> line_vector;//線分を保存しておく配列

	void GetSize();//各配列の大きさを取得

	void PushCircle(DiploidCircle circle);//円を円配列にプッシュします。
	void PushPoint(DiploidPoint point);//点を点配列にプッシュします。
	void PushBox(DiploidBox box);//四角を四角配列にプッシュします。
	void PushLine(DiploidLine line);//線分を線分配列にプッシュします。

	void PopBackCircle();//円を一番後ろの配列から削除します。
	void PopBackPoint();//点を一番後ろの配列から削除します。
	void PopBackBox();//四角を一番後ろの配列から削除します。
	void PopBackLine();//線分を一番後ろの配列から削除します。

	void DestoryCircle();//円がヒットしていたら円配列から削除
	void DestoryPoint();//点がヒットしていたら点配列から削除
	void DestoryBox();//四角がヒットしていたら四角配列から削除
	void DestoryLine();//線分がヒットしていたら線分配列から削除

	void Destory();//配列から削除

	void Init();//初期化

	void Updata();//衝突判定処理

	//Updata()を使って処理をする場合は以下の関数を使用しない。
	void ImpactCirclePoint();//円と点の当たり判定処理(画面外の判定は行わない処理を実装ずみ){要バグ確認}
	void ImpactCircleCircle();//円と円の当たり判定処理
	void ImpactBoxPoint();//四角と点の当たり判定処理(画面外の判定は行わない処理を実装ずみ)
	void ImpactBoxBox();//四角と四角の当たり判定処理(画面外の判定は行わない処理を実装ずみ)
	void ImpactBoxCircle();//四角と円の当たり判定処理
	void ImpactCircleLine();//円と線分の当たり判定処理
	void ImpactPointLine();//点と線分の当たり判定処理
	void ImpactLineLine();//線分と線分の当たり判定処理
	void ImpactLineBox();//線分と箱の当たり判定処理

	void Draw(bool wire = true, bool debug = false);//描写

	void SetBoxAnimation(int number, VECTOR move_speed = { 0,0,0 }, VECTOR move_size = { 0,0,0 });//box配列から特定のboxを見つけてアニメーション値を変更する。(配列に追加した後に数値を変更したい場合に使用)
};