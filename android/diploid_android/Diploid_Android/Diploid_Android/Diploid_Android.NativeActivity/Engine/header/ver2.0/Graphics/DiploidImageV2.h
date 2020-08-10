#pragma once
#include "DxLib.h"
#include  <string>
#include <cmath>

using namespace std;

class DiploidImageV2
{
private:
	string name = "no_name";//オブジェクトの名前(主に検索するときに使用)
	int layer_number;//レイヤーの番号(主に当たり判定時にどの層に居るのか判別するのに使用)
	int object_number;//オブジェクトの番号

	int graphics_handl;//グラフィックハンドル
	int graphics_x, graphics_y;//オリジナルの大きさ

	VECTOR graphics_size;//いろいろ変更を加えた大きさ
	VECTOR move_speed;//オブジェクトの移動スピード
	float move_angle;//オブジェクトの移動方向
	VECTOR center_position;//画像の中心位置
	VECTOR down_center_position;//画像の下の中心位置

	VECTOR position;//描画位置
	VECTOR rotate_position;//回転する際の中心点
	VECTOR graphics_scale = { 1.0f,1.0f,1.0f };//画像の倍率
	float angle;//回転角度
	bool turn = FALSE;//左右反転のフラグ

	float object_life;//寿命

	bool destory_flag = false;//削除フラグ(trueの場合、削除対象に)
	bool hit_flag = false;//当たっているかのフラグ
	bool main_camera = false;//メインカメラの追うオブジェクトかのフラグ
	bool active = false;

protected:

public:
	void Load(const char* path);//画像を読み込みます。
	void Init(VECTOR pos, bool shift_flag = true);//読み込んだ画像を初期化します。(shift_flagがtrueで画像を中心にして描画します。)
	void MoveUpdate();//設定した移動速度を反映します。
	void Draw(bool draw = true);//画像を描画します。

	void SetHandl(int new_handl);//画像ハンドルを設定します。
	void SetScale(float scale_x, float scale_y);//画像の表示倍率を変更します。
	void SetAngle(float new_angle);//新しく回転角を設定します。
	void SetPosition(VECTOR new_position);//新しく表示位置を設定します。
	void SetTurnFlag(bool new_flag);//新しく画像反転フラグを設定します。
	void SetRotatePosition(VECTOR new_position);//新しく回転軸を設定します。
	void SetBright(float scale = 1.0f);//明るさを設定します。(1.0fで100%)
	void SetBright(int red, int green, int blue);//明るさを指定します。

	void SetMoveSpeed(VECTOR new_move_speed);//新しく移動する速度を設定します。(3軸指定版)
	void SetMoveSpeed(float angle, float new_move_speed);//新しく移動する速度を設定します。(ラジアン角指定版)
	void SetName(string new_name);//新たにオブジェクトの名前を設定します。
	void SetLife(float new_life);//新しく寿命を設定します。
	void SetDestoryFlag(bool new_flag);//新しく削除フラグを設定します。
	void SetMainCameraFlag(bool new_flag);//新しくメインカメラフラグを設定します。(Camera関数以外からの使用は控える)
	void SetObjectNumber(int new_number);//新しいオブジェクト番号を設定します。
	void SetHitFlag(bool new_hit_flag);//新しくヒットフラグを設定します。
	void SetActiveFlag(bool new_active_flag);

	void AddLife(float add_val);//寿命カウントを足します。
	void SubLife(float sub_val);//寿命カウントを引きます。

	int GetGraphicsHandl();//読み込まれた現在のグラフィックハンドルを取得します。
	VECTOR GetScale();//現在の画像の表示倍率を取得します。
	VECTOR GetSize();//現在の画像の大きさを取得します。
	VECTOR GetPosition();//現在の画像の左上の位置を取得します。
	VECTOR GetCenterPosition();//現在の画像の中心位置を取得します。
	VECTOR GetRotatePosition();//現在の画像の回転軸座標を取得します。
	VECTOR GetDownCenterPosition();//現在の画像の左下の座標を取得します。
	float GetAngle();//現在の画像の回転角を取得します。(ラジアン)
	bool GetTurnFlag();//現在の画像反転フラグを取得します。(TRUEで反転)
	bool GetActiveFlag();

	VECTOR GetMoveSpeed();//現在のオブジェクトの移動速度を取得します。
	float GetMoveAngle();//現在のオブジェクトの移動している方角を取得します。(ラジアン)
	string GetName();//現在のオブジェクトの名前を取得します。
	float GetLife();//現在のオブジェクトの寿命を取得します。
	bool GetDestoryFlag();//現在の削除フラグを取得します。(trueで削除対象オン)	
	bool GetMainCameraFlag();//現在のオブジェクトがメインカメラの対象になっているかのフラグを取得します。
	int GetObjectNumber();//現在のオブジェクトの番号を取得します。
	bool GetHitFlag();//現在のオブジェクトのヒットフラグを取得します。

};