#pragma once
#include <string>
#include <list>
#include <math.h>
#include "DxLib.h"

using namespace std;

//2Dの円に関するクラス(スタンドアローンなクラスとして実装)
class DiploidCircleV2
{
private:
	string name;//オブジェクトの名前(主に検索するときに使用)
	int layer_number;//レイヤーの番号(主に当たり判定時にどの層に居るのか判別するのに使用)
	int object_number;//オブジェクトの番号

	VECTOR position;//オブジェクトの位置
	VECTOR move_speed;//オブジェクトの移動スピード
	float move_angle;//オブジェクトの移動方向
	float radius;//円の半径(実質、Size)

	list<VECTOR> hit_points_list;//当たっている場所の位置。
	list<VECTOR>* hit_points_list_pointer;//hit_points_listへのポインター(イテレータではない)
	list<VECTOR>::iterator hit_points_list_iterator = hit_points_list.begin();//hit_points_listのイテレータ

	unsigned int object_color;//色
	bool object_fill;//塗りつぶし
	float object_thickness;//太さ
	float object_life;//寿命

	bool destory_flag = false;//削除フラグ(trueの場合、削除対象に)
	bool hit_flag = false;//当たっているかのフラグ
	bool main_camera = false;//メインカメラの追うオブジェクトかのフラグ

protected:

public:

	void Init(VECTOR pos, float radi, unsigned int color, bool fill = FALSE, float thickness = 1.0f);
	void MoveUpdata();//設定した移動速度を反映します。
	void Draw(bool draw = true);//円を描画します。(drawにfalseを入れることで描画しない)

	void SetColor(unsigned int color);//新しい色を設定します。
	void SetPosition(VECTOR new_pos);//新しい位置を設定します。
	void SetRadius(float new_radius);//新しい半径を設定します。
	void SetFill(bool new_fill);//新たに塗りつぶしを設定します。
	void SetThickness(float new_thickness);//新たに線の太さを設定します。

	void SetName(string new_name);//新たにオブジェクトの名前を設定します。
	void SetObjectNumber(int new_number);//新しいオブジェクト番号を設定します。
	void SetHitFlag(bool new_hit_flag);//新しくヒットフラグを設定します。
	void SetMoveSpeed(VECTOR new_move_speed);//新しく移動する速度を設定します。(3軸指定版)
	void SetMoveSpeed(float angle, float new_move_speed);//新しく移動する速度を設定します。(ラジアン角指定版)
	void SetLife(float new_life);//新しく寿命を設定します。
	void SetDestoryFlag(bool new_flag);//新しく削除フラグを設定します。
	void SetMainCameraFlag(bool new_flag);//新しくメインカメラフラグを設定します。(Camera関数以外からの使用は控える)

	void AddLife(float add_val);//寿命カウントを足します。
	void SubLife(float sub_val);//寿命カウントを引きます。
	
	VECTOR GetPosition();//現在の位置を取得します。
	float GetRadius();//現在の半径を取得します。
	float GetThickness();//現在の線の太さを取得します。
	unsigned int GetColor();//現在の色を取得します。
	bool GetFill();//現在の塗りつぶしの設定を取得します。

	string GetName();//現在のオブジェクトの名前を取得します。
	int GetObjectNumber();//現在のオブジェクトの番号を取得します。
	bool GetHitFlag();//現在のオブジェクトのヒットフラグを取得します。
	VECTOR GetMoveSpeed();//現在のオブジェクトの移動速度を取得します。
	float GetMoveAngle();//現在のオブジェクトの移動している方角を取得します。(ラジアン)
	float GetLife();//現在のオブジェクトの寿命を取得します。
	bool GetDestoryFlag();//現在の削除フラグを取得します。(trueで削除対象オン)	
	bool GetMainCameraFlag();//現在のオブジェクトがメインカメラの対象になっているかのフラグを取得します。

	size_t GetHitPointsVolume();//現在の当たっている場所の総数を取得します。
	VECTOR GetHitPosition();//現在の当たっている場所の位置を取得します。
	list<VECTOR>::iterator GetHitPointsListIterator(list<VECTOR>::iterator* pointer_to_iterator);//hit_points_listのイテレータを取得します。(使用非推奨:イテレータ指定版)
	list<VECTOR>::iterator GetHitPointsListIterator();//要検証：hit_points_listのイテレータを取得します。(使用推奨：安全版。list<>::begin()が初期値)
	list<VECTOR>* GetHitPointsListPointer();//hit_points_listへのポインタを取得します。
};
