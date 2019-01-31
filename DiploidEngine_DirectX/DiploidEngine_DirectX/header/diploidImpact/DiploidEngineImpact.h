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
	DiploidEngineImpact();//コンストラクタ
	~DiploidEngineImpact();//デストラクタ

	int screen_size_x = 1280 + 200;
	int screen_size_y = 720 + 200;

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

	void AutoNumber();//オブジェクト番号を付けるのがめんどいときの自動オブジェクト番号付与処理。(全てのオブジェクトは番号が異なるようになる。ループ処理に組み込むと動作が重くなるかも)

	void Draw(bool wire = true, bool debug = false);//描写

	//Updata()を使って処理をする場合は以下のImpact~関数を使用しない。
	void ImpactCirclePoint();//円と点の当たり判定処理(画面外の判定は行わない処理を実装ずみ){要バグ確認}
	void ImpactCircleCircle();//円と円の当たり判定処理
	void ImpactBoxPoint();//四角と点の当たり判定処理(画面外の判定は行わない処理を実装ずみ)
	void ImpactBoxBox();//四角と四角の当たり判定処理(画面外の判定は行わない処理を実装ずみ)
	void ImpactBoxCircle();//四角と円の当たり判定処理
	void ImpactCircleLine();//円と線分の当たり判定処理
	void ImpactPointLine();//点と線分の当たり判定処理
	void ImpactLineLine();//線分と線分の当たり判定処理
	void ImpactLineBox();//線分と箱の当たり判定処理

	//アニメーション値を変更する関数。
	//BOX(Position)
	void SetBoxPositionAnimation(int number, VECTOR move_speed = { 0.0f,0.0f,0.0f });//box配列から特定のboxを見つけて座標アニメーション値を変更する。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)
	void SetBoxPositionAnimationX(int number, float move_speed = 0.0f);//box配列から特定のboxを見つけてX座標アニメーション値だけを変更する。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)
	void SetBoxPositionAnimationY(int number, float move_speed = 0.0f);//box配列から特定のboxを見つけてY座標アニメーション値だけを変更する。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)
	void SetBoxPositionAnimationZ(int number, float move_speed = 0.0f);//box配列から特定のboxを見つけてZ座標アニメーション値だけを変更する。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)

	//CIRCLE(Position)
	void SetCirclePositionAnimation(int number, VECTOR move_speed = { 0,0,0 });//circle配列から特定のcircleを見つけて座標アニメーション値を変更する。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)
	void SetCirclePositionAnimationX(int number, float move_speed = 0.0f);//circle配列から特定のcircleを見つけてX座標アニメーション値だけを変更する。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)
	void SetCirclePositionAnimationY(int number, float move_speed = 0.0f);//circle配列から特定のcircleを見つけてY座標アニメーション値だけを変更する。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)

	//POINT(Position)
	void SetPointPositionAnimation(int number, VECTOR move_speed = { 0,0,0 });//point配列から特定のpointを見つけて座標アニメーション値を変更する。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)
	void SetPointPositionAnimationX(int number, float move_speed = 0.0f);//point配列から特定のpointを見つけてX座標アニメーション値だけを変更する。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)
	void SetPointPositionAnimationY(int number, float move_speed = 0.0f);//point配列から特定のpointを見つけてY座標アニメーション値だけを変更する。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)


	void SetBoxSizeAnimation(int number, VECTOR move_size = { 0,0,0 });//box配列から特定のboxを見つけて拡大アニメーション値を変更する。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)
	void SetCircleSizeAnimation(int number, float move_size = 0.0f);//circle配列から特定のcircleを見つけて拡大アニメーション値を変更する。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)

	void SetBoxPositionAdd(int number, VECTOR position = { 0,0,0 });//box配列から特定のboxを見つけて元ある座標に指定数値分だけを足す。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)
	void SetCirclePositionAdd(int number, VECTOR position = { 0,0,0 });//circle配列から特定のcircleを見つけて元ある座標に指定数値分だけを足す。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)
	void SetPointPositionAdd(int number, VECTOR position = { 0,0,0 });//point配列から特定のpointを見つけて元ある座標に指定数値分だけを足す。(numberにはオブジェクト番号を入れること。配列に追加した後に数値を変更したい場合に使用)

	VECTOR GetBoxCenterPosition(int number);//box配列から特定のboxを見つけてそのboxの中心点の座標を得ます。
	VECTOR GetCircleCenterPosition(int number);//circle配列から特定のcircleを見つけてそのcircleの中心点の座標を得ます。
	VECTOR GetPointPosition(int number);//point配列から特定のpointを見つけてそのpointの座標を得ます。

	//各配列の大きさを得る関数
	int GetEndBox();//box配列の現在の一番最後の数を取得。(配列になにもなければ-1を返す。)
	int GetEndCircle();//circle配列の現在の一番最後の数を取得。(配列になにもなければ-1を返す。)
	int GetEndPoint();//point配列の現在の一番最後の数を取得。(配列になにもなければ-1を返す。)
	int GetEndLine();//line配列の現在の一番最後の数を取得。(配列になにもなければ-1を返す。)

	//どれかの配列を基準に他の配列と大きさを比較して大きければ基準の配列の大きさを返す。
	int GetMaxBoxNumber();//box配列を基準に、一番大きい値を返す。つまり、box以外のオブジェクトと比較して大きければ最大数を返す。(配列になにもなければ-1を返す。)
	int GetMaxPointNumber();//point配列を基準に、一番大きい値を返す。つまり、point以外のオブジェクトと比較して大きければ最大数を返す。(配列になにもなければ-1を返す。)
	int GetMaxCircleNumber();//circle配列を基準に、一番大きい値を返す。つまり、circle以外のオブジェクトと比較して大きければ最大数を返す。(配列になにもなければ-1を返す。)
	int GetMaxLineNumber();//line配列を基準に、一番大きい値を返す。つまり、line以外のオブジェクトと比較して大きければ最大数を返す。(配列になにもなければ-1を返す。)

	int GetMaxArrayNumber();//box.point.circle.line配列をそれぞれ比べて一番大きい要素数を返す。

	int GetAllArraySize();//全ての配列のサイズの合計を返す。

	//オブジェクト番号を調べる関数。
	int GetBoxNumber(int target);//box配列の最初から数えてｘ番目のオブジェクト番号を取得する。
	int GetPointNumber(int target);//point配列の最初から数えてｘ番目のオブジェクト番号を取得する。
	int GetCircleNumber(int target);//circle配列の最初から数えてｘ番目のオブジェクト番号を取得する。
	int GetLineNumber(int target);//line配列の最初から数えてｘ番目のオブジェクト番号を取得する。

	//指定のオブジェクト番号を変更する関数。(要検証)
	void SetBoxNumber(int target_number, int set_number);//box配列の指定データのオブジェクト番号(number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)
	void SetCircleNumber(int target_number, int set_number);//circle配列の指定データのオブジェクト番号(number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)
	void SetPointNumber(int target_number, int set_number);//point配列の指定データのオブジェクト番号(number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)
	void SetLineNumber(int target_number, int set_number);//line配列の指定データのオブジェクト番号(number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)

	void SetNumber(int number);//未実装

	//レイヤー番号を調べる関数。
	int GetBoxLayerNumber(int target);//box配列の最初から数えてｘ番目のレイヤー番号を取得する。
	int GetPointLayerNumber(int target);//point配列の最初から数えてｘ番目のレイヤー番号を取得する。
	int GetCircleLayerNumber(int target);//circle配列の最初から数えてｘ番目のレイヤー番号を取得する。
	int GetLineLayerNumber(int target);//line配列の最初から数えてｘ番目のレイヤー番号を取得する。

	//指定のレイヤー番号を変更する関数。(要検証)
	void SetBoxLayerNumber(int target_number, int set_number);//box配列の指定データのレイヤー番号(layer_number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)
	void SetCircleLayerNumber(int target_number, int set_number);//circle配列の指定データのレイヤー番号(layer_number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)
	void SetPointLayerNumber(int target_number, int set_number);//point配列の指定データのレイヤー番号(layer_number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)
	void SetLineLayerNumber(int target_number, int set_number);//line配列の指定データのレイヤー番号(layer_number変数)を変更します。(target_numberには配列頭から数えて何番目の値を変えるのかを指定、set_numberには実際に変え値)


	//オブジェクトが衝突しているか調べる関数。
	int GetBoxImpactFlag(int number);//box配列のオブジェクト衝突フラグを取得する。(numberにはオブジェクト番号、0でヒットなし、１でヒットしている)
	int GetPointImpactFlag(int number);//point配列の最初から数えてｘ番目のオブジェクト衝突フラグ取得する。(numberにはオブジェクト番号、0でヒットなし、１でヒットしている)
	int GetCircleImpactFlag(int number);//circle配列の最初から数えてｘ番目のオブジェクト衝突フラグ取得する。(numberにはオブジェクト番号、0でヒットなし、１でヒットしている)
	int GetLineImpactFlag(int number);//line配列の最初から数えてｘ番目のオブジェクト衝突フラグ取得する。(numberにはオブジェクト番号、0でヒットなし、１でヒットしている)

};